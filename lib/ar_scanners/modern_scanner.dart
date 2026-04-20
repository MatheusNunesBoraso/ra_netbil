import 'package:ar_flutter_plugin_2/ar_flutter_plugin.dart';
import 'package:ar_flutter_plugin_2/datatypes/config_planedetection.dart';
import 'package:ar_flutter_plugin_2/datatypes/hittest_result_types.dart';
import 'package:ar_flutter_plugin_2/datatypes/node_types.dart';
import 'package:ar_flutter_plugin_2/managers/ar_anchor_manager.dart';
import 'package:ar_flutter_plugin_2/managers/ar_location_manager.dart';
import 'package:ar_flutter_plugin_2/managers/ar_object_manager.dart';
import 'package:ar_flutter_plugin_2/managers/ar_session_manager.dart';
import 'package:ar_flutter_plugin_2/models/ar_anchor.dart';
import 'package:ar_flutter_plugin_2/models/ar_hittest_result.dart';
import 'package:ar_flutter_plugin_2/models/ar_node.dart';
import 'package:flutter/material.dart';
import 'package:vector_math/vector_math_64.dart' as vm;

import '../models/catalog.dart';

/// Scanner plane+tap. **NAO reconhece a capa.**
/// Usuario toca em um plano detectado pela camera e o modelo 3D
/// e ancorado naquele ponto. Serve de fallback quando image tracking
/// nao consegue detectar a capa (ex.: iluminacao ruim, capa lisa).
class ModernScanner extends StatefulWidget {
  final CollectionItem item;
  const ModernScanner({super.key, required this.item});

  @override
  State<ModernScanner> createState() => _ModernScannerState();
}

class _ModernScannerState extends State<ModernScanner> {
  ARSessionManager? _sessionManager;
  ARObjectManager? _objectManager;
  ARAnchorManager? _anchorManager;

  final List<ARNode> _nodes = [];
  final List<ARAnchor> _anchors = [];
  String _status = 'Aponte para uma superficie plana\ne toque na tela.';
  bool _hasError = false;

  @override
  void dispose() {
    _sessionManager?.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        ARView(
          onARViewCreated: _onARViewCreated,
          planeDetectionConfig: PlaneDetectionConfig.horizontalAndVertical,
        ),
        Positioned(
          left: 16,
          right: 16,
          bottom: 24,
          child: Center(
            child: Container(
              padding:
                  const EdgeInsets.symmetric(horizontal: 16, vertical: 10),
              decoration: BoxDecoration(
                color: (_hasError ? Colors.red.shade900 : Colors.black)
                    .withValues(alpha: 0.75),
                borderRadius: BorderRadius.circular(16),
              ),
              child: Text(
                _status,
                textAlign: TextAlign.center,
                style: const TextStyle(color: Colors.white, fontSize: 14),
              ),
            ),
          ),
        ),
      ],
    );
  }

  void _onARViewCreated(
    ARSessionManager sessionManager,
    ARObjectManager objectManager,
    ARAnchorManager anchorManager,
    ARLocationManager locationManager,
  ) {
    _sessionManager = sessionManager;
    _objectManager = objectManager;
    _anchorManager = anchorManager;

    sessionManager.onInitialize(
      showFeaturePoints: false,
      showPlanes: true,
      showWorldOrigin: false,
      handleTaps: true,
    );
    objectManager.onInitialize();

    sessionManager.onPlaneOrPointTap = _onPlaneOrPointTapped;
  }

  Future<void> _onPlaneOrPointTapped(List<ARHitTestResult> hits) async {
    final planeHit = hits.firstWhere(
      (h) => h.type == ARHitTestResultType.plane,
      orElse: () => hits.first,
    );

    try {
      final anchor = ARPlaneAnchor(transformation: planeHit.worldTransform);
      final added = await _anchorManager?.addAnchor(anchor);
      if (added != true) {
        setState(() {
          _hasError = true;
          _status = 'Nao foi possivel criar a ancora.';
        });
        return;
      }
      _anchors.add(anchor);

      final scale = widget.item.physicalWidthMeters;
      final node = ARNode(
        type: NodeType.webGLB,
        uri: widget.item.model3dUrl,
        scale: vm.Vector3.all(scale),
        position: vm.Vector3(0, 0, 0),
        rotation: vm.Vector4(1, 0, 0, 0),
      );
      final didAdd = await _objectManager?.addNode(node, planeAnchor: anchor);
      if (didAdd == true) {
        _nodes.add(node);
        setState(() {
          _hasError = false;
          _status = 'Modelo posicionado! Toque em outro lugar para mover.';
        });
      } else {
        setState(() {
          _hasError = true;
          _status = 'Falha ao carregar modelo 3D.\nVerifique a internet.';
        });
      }
    } catch (e) {
      setState(() {
        _hasError = true;
        _status = 'Erro: $e';
      });
    }
  }
}
