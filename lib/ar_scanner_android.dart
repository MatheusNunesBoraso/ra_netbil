import 'dart:async';

import 'package:arcore_flutter_plugin/arcore_flutter_plugin.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart' show rootBundle;
import 'package:vector_math/vector_math_64.dart' as vm;

import 'models/catalog.dart';

class ArScannerAndroid extends StatefulWidget {
  final CollectionItem item;
  const ArScannerAndroid({super.key, required this.item});

  @override
  State<ArScannerAndroid> createState() => _ArScannerAndroidState();
}

class _ArScannerAndroidState extends State<ArScannerAndroid> {
  static const Duration _detectionTimeout = Duration(seconds: 15);

  ArCoreController? _controller;
  final Set<int> _placed = <int>{};
  String _status = 'Aponte para a capa do livro...';
  bool _hasError = false;
  Timer? _detectionTimer;

  @override
  void dispose() {
    _detectionTimer?.cancel();
    _controller?.dispose();
    super.dispose();
  }

  Future<void> _onArViewCreated(ArCoreController controller) async {
    _controller = controller;
    controller.onTrackingImage = _onTrackingImage;

    try {
      final bytes = await rootBundle.load(widget.item.referenceImageAsset);
      await controller.loadSingleAugmentedImage(
        bytes: bytes.buffer.asUint8List(),
      );
      _startDetectionTimer();
    } catch (e) {
      if (!mounted) return;
      setState(() {
        _hasError = true;
        _status =
            'Nao foi possivel iniciar a camera AR.\nVerifique se o aparelho suporta ARCore.';
      });
    }
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

  void _onTrackingImage(ArCoreAugmentedImage image) {
    if (_placed.contains(image.index)) return;
    _placed.add(image.index);
    _detectionTimer?.cancel();

    final scale = widget.item.physicalWidthMeters;

    try {
      final node = ArCoreReferenceNode(
        name: '${widget.item.id}_${image.index}',
        objectUrl: widget.item.model3dUrl,
        position: vm.Vector3(0, 0, 0),
        scale: vm.Vector3(scale, scale, scale),
      );

      _controller?.addArCoreNodeToAugmentedImage(node, image.index);
      setState(() {
        _hasError = false;
        _status = 'Modelo ancorado na capa!';
      });
    } catch (e) {
      setState(() {
        _hasError = true;
        _status =
            'Capa detectada, mas falhou ao carregar o modelo 3D.\nVerifique a conexao com a internet.';
      });
    }
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
