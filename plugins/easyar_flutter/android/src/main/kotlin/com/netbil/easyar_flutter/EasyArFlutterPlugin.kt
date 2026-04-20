package com.netbil.easyar_flutter

import io.flutter.embedding.engine.plugins.FlutterPlugin

/**
 * Plugin raiz do easyar_flutter.
 *
 * Registra a [EasyArViewFactory] para criar PlatformViews do tipo
 * `com.netbil/easyar_view` quando o Dart pedir (`AndroidView(viewType: ...)`).
 *
 * Fase 1: a factory retorna um placeholder View com texto "Inicializando
 * EasyAR...". Nada da engine nativa e chamado ainda — o objetivo e so
 * validar que a ponte Flutter <-> nativo funciona e que o `EasyAR.aar`
 * esta corretamente linkado no build.
 */
class EasyArFlutterPlugin : FlutterPlugin {
    override fun onAttachedToEngine(binding: FlutterPlugin.FlutterPluginBinding) {
        binding.platformViewRegistry.registerViewFactory(
            "com.netbil/easyar_view",
            EasyArViewFactory(binding.binaryMessenger)
        )
    }

    override fun onDetachedFromEngine(binding: FlutterPlugin.FlutterPluginBinding) {
        // Na Fase 2 aqui vai o Engine.dispose() ou equivalente.
    }
}
