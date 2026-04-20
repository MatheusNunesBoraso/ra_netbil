import 'package:easyar_flutter/easyar_flutter.dart';
import 'package:flutter/material.dart';

import 'models/catalog.dart';

/// Pagina AR unica baseada em EasyAR (Sense, image tracking nativo).
///
/// Fase 1 (atual): embute [EasyArView]. Plugin nativo mostra placeholder
/// confirmando que a ponte Flutter <-> nativo funciona. Engine real do
/// EasyAR ainda nao e inicializada — isso vem na Fase 2.
class ArScannerPage extends StatelessWidget {
  final CollectionItem item;
  const ArScannerPage({super.key, required this.item});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text(item.title)),
      body: EasyArView(
        referenceImageAsset: item.referenceImageAsset,
        model3dUrl: item.model3dUrl,
        physicalWidthMeters: item.physicalWidthMeters,
      ),
    );
  }
}
