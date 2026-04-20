/// Backends de realidade aumentada disponiveis no app.
/// A escolha e persistida em SharedPreferences via [ArMethodService]
/// e usada em [ArScannerPage] para decidir qual scanner abrir.
enum ArMethod {
  /// arcore_flutter_plugin 0.1.0 (Android) + arkit_plugin (iOS).
  /// Image tracking nativo. Plugin antigo, mais sensivel a qualidade
  /// da imagem de referencia.
  original,

  /// ar_flutter_plugin_2 (ARCore/ARKit modernos).
  /// **NAO faz image tracking** — so plane detection + toque.
  /// Usuario toca na tela e o modelo aparece no ponto tocado.
  planeTap,

  /// MindAR (MediaPipe via WebView).
  /// Image tracking baseado em web. Roda pagina HTML local com
  /// MindAR.js + A-Frame carregada via InAppWebView.
  mindar,

  /// EasyAR Sense (SDK comercial, melhor image tracking do mercado).
  /// Ainda nao integrado — requer 1-2 semanas de codigo nativo.
  /// Botao mostra tela de status com instrucoes.
  easyar,
}

extension ArMethodMeta on ArMethod {
  String get label {
    switch (this) {
      case ArMethod.original:
        return 'Original (ARCore/ARKit)';
      case ArMethod.planeTap:
        return 'Plano + Toque';
      case ArMethod.mindar:
        return 'MindAR (WebView)';
      case ArMethod.easyar:
        return 'EasyAR (em construcao)';
    }
  }

  String get description {
    switch (this) {
      case ArMethod.original:
        return 'Image tracking nativo. Aponte a camera pra capa.';
      case ArMethod.planeTap:
        return 'Nao reconhece a capa. Toque na tela para posicionar o modelo.';
      case ArMethod.mindar:
        return 'Image tracking via WebView + MediaPipe. Exige arquivo .mind compilado.';
      case ArMethod.easyar:
        return 'Integracao nativa pendente. Abre tela com instrucoes.';
    }
  }

  String get storageKey => 'ar_method';
}
