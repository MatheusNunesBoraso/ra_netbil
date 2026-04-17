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
  ARKitController? _controller;
  final Set<String> _placed = <String>{};
  String _status = 'Aponte para a capa do livro...';

  @override
  void dispose() {
    _controller?.dispose();
    super.dispose();
  }

  void _onArKitViewCreated(ARKitController controller) {
    _controller = controller;
    controller.onAddNodeForAnchor = _onAnchor;
  }

  void _onAnchor(ARKitAnchor anchor) {
    if (anchor is! ARKitImageAnchor) return;
    if (_placed.contains(anchor.identifier)) return;
    _placed.add(anchor.identifier);

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

    setState(() => _status = 'Modelo ancorado na capa!');
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
          left: 0,
          right: 0,
          bottom: 24,
          child: Center(
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
              decoration: BoxDecoration(
                color: Colors.black.withValues(alpha: 0.6),
                borderRadius: BorderRadius.circular(24),
              ),
              child:
                  Text(_status, style: const TextStyle(color: Colors.white)),
            ),
          ),
        ),
      ],
    );
  }
}
