import 'package:flutter/material.dart';

import '../models/catalog.dart';

/// Placeholder page para EasyAR.
///
/// Integracao real exige:
/// 1. Baixar SDK nativo (Android .aar + iOS .xcframework) de www.easyar.com
/// 2. Escrever MethodChannel + PlatformView em Kotlin (Android)
/// 3. Escrever MethodChannel + PlatformView em Swift (iOS)
/// 4. Empacotar como plugin local em `plugins/easyar_flutter/`
/// 5. Configurar a chave Sense (ver memoria project_ar_strategy.md)
/// 6. Carregar alvo de image tracking a partir de widget.item.referenceImageAsset
///
/// Ate isso existir, essa tela so mostra status pro usuario.
class EasyArStub extends StatelessWidget {
  final CollectionItem item;
  const EasyArStub({super.key, required this.item});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      body: SafeArea(
        child: Padding(
          padding: const EdgeInsets.all(24),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              const Icon(Icons.construction, size: 72, color: Colors.amber),
              const SizedBox(height: 20),
              const Text(
                'EasyAR em construcao',
                style: TextStyle(
                  color: Colors.white,
                  fontSize: 22,
                  fontWeight: FontWeight.w700,
                ),
                textAlign: TextAlign.center,
              ),
              const SizedBox(height: 12),
              Text(
                'Item: ${item.title}',
                style: const TextStyle(color: Colors.white70),
              ),
              const SizedBox(height: 24),
              Container(
                padding: const EdgeInsets.all(16),
                decoration: BoxDecoration(
                  color: Colors.white.withValues(alpha: 0.06),
                  borderRadius: BorderRadius.circular(12),
                ),
                child: const Text(
                  'A integracao nativa com EasyAR Sense SDK ainda '
                  'nao foi implementada.\n\n'
                  'Pra ativar esse metodo e preciso escrever '
                  'MethodChannel + PlatformView em Kotlin (Android) '
                  'e Swift (iOS) que embrulhem o SDK nativo do EasyAR.\n\n'
                  'Chave Sense ja provisionada nos secrets do projeto.',
                  style: TextStyle(color: Colors.white, height: 1.5),
                ),
              ),
              const SizedBox(height: 24),
              OutlinedButton(
                style: OutlinedButton.styleFrom(
                  foregroundColor: Colors.white,
                  side: const BorderSide(color: Colors.white38),
                ),
                onPressed: () => Navigator.of(context).pop(),
                child: const Text('Voltar'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
