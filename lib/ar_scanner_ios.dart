import 'dart:async';

import 'package:arkit_plugin/arkit_plugin.dart';
import 'package:flutter/material.dart';
import 'package:vector_math/vector_math_64.dart' as vm;

import 'models/catalog.dart';

class ArScannerIos extends StatefulWidget {
  final CollectionItem item;
  const ArScannerIos({super.key, required this.item});

  @override
  State<ArScannerIos> createState() => _ArScannerIosState();
}

class _ArScannerIosState extends State<ArScannerIos> {
  static const Duration _detectionTimeout = Duration(seconds: 15);

  ARKitController? _controller;
  final Set<String> _placed = <String>{};
  String _status = 'Aponte para a capa do livro...';
  bool _hasError = false;
  Timer? _detectionTimer;

  @override
  void dispose() {
    _detectionTimer?.cancel();
    _controller?.dispose();
    super.dispose();
  }

  void _onArKitViewCreated(ARKitController controller) {
    _controller = controller;
    controller.onAddNodeForAnchor = _onAnchor;
    controller.onError = (error) {
      if (!mounted) return;
      setState(() {
        _hasError = true;
        _status =
            'Erro do ARKit: $error\nVerifique se o aparelho suporta AR.';
      });
    };
    _startDetectionTimer();
  }

  void _startDetectionTimer() {
    _detectionTimer?.cancel();
    _detectionTimer = Timer(_detectionTimeout, () {
      if (!mounted) return;
      if (_placed.isNotEmpty) return;
      setState(() {
        _hasError = true;
        _status =
            'Nao conseguimos detectar a capa.\nAproxime a camera, melhore a iluminacao\ne mantenha o livro centralizado.';
      });
    });
  }

  void _onAnchor(ARKitAnchor anchor) {
    if (anchor is! ARKitImageAnchor) return;
    if (_placed.contains(anchor.identifier)) return;
    _placed.add(anchor.identifier);
    _detectionTimer?.cancel();

    try {
      final node = ARKitSphere(
        radius: 0.04,
        materials: [
          ARKitMaterial(
            diffuse: ARKitMaterialProperty.color(Colors.orange),
          ),
        ],
      );

      _controller?.add(
        ARKitNode(
          geometry: node,
          position: vm.Vector3(0, 0.05, 0),
          name: '${widget.item.id}_${anchor.identifier}',
        ),
        parentNodeName: anchor.nodeName,
      );

      setState(() {
        _hasError = false;
        _status = 'Modelo ancorado na capa!';
      });
    } catch (e) {
      setState(() {
        _hasError = true;
        _status =
            'Capa detectada, mas falhou ao posicionar o modelo 3D.';
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        ARKitSceneView(
          onARKitViewCreated: _onArKitViewCreated,
          configuration: ARKitConfiguration.imageTracking,
          detectionImagesGroupName: 'AR Resources',
          maximumNumberOfTrackedImages: 1,
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
}
