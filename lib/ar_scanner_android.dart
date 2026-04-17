import 'package:arcore_flutter_plugin/arcore_flutter_plugin.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart' show rootBundle;
import 'package:vector_math/vector_math_64.dart' as vm;

class ArScannerAndroid extends StatefulWidget {
  const ArScannerAndroid({super.key});

  @override
  State<ArScannerAndroid> createState() => _ArScannerAndroidState();
}

class _ArScannerAndroidState extends State<ArScannerAndroid> {
  ArCoreController? _controller;
  final Set<int> _placed = <int>{};
  String _status = 'Aponte para a capa do livro...';

  @override
  void dispose() {
    _controller?.dispose();
    super.dispose();
  }

  Future<void> _onArViewCreated(ArCoreController controller) async {
    _controller = controller;
    controller.onTrackingImage = _onTrackingImage;

    final bytes = await rootBundle.load('assets/images/book_cover.jpg');
    await controller.loadSingleAugmentedImage(
      bytes: bytes.buffer.asUint8List(),
    );
  }

  void _onTrackingImage(ArCoreAugmentedImage image) {
    if (_placed.contains(image.index)) return;
    _placed.add(image.index);

    final node = ArCoreReferenceNode(
      name: 'book_3d_${image.index}',
      objectUrl:
          'https://raw.githubusercontent.com/KhronosGroup/glTF-Sample-Models/master/2.0/Duck/glTF-Binary/Duck.glb',
      position: vm.Vector3(0, 0, 0),
      scale: vm.Vector3(0.15, 0.15, 0.15),
    );

    _controller?.addArCoreNodeToAugmentedImage(node, image.index);
    setState(() => _status = 'Modelo ancorado na capa!');
  }

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        ArCoreView(
          onArCoreViewCreated: _onArViewCreated,
          enableTapRecognizer: false,
          enableUpdateListener: true,
          type: ArCoreViewType.AUGMENTEDIMAGES,
        ),
        _StatusBar(text: _status),
      ],
    );
  }
}

class _StatusBar extends StatelessWidget {
  const _StatusBar({required this.text});
  final String text;

  @override
  Widget build(BuildContext context) {
    return Positioned(
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
          child: Text(text, style: const TextStyle(color: Colors.white)),
        ),
      ),
    );
  }
}
