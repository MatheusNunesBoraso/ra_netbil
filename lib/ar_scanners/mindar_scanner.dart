import 'package:flutter/material.dart';
import 'package:flutter/services.dart' show rootBundle;
import 'package:flutter_inappwebview/flutter_inappwebview.dart';

import '../models/catalog.dart';

/// Scanner via WebView. Serve `assets/mindar/index.html` num
/// localhost HTTP (obrigatorio para getUserMedia no iOS WKWebView)
/// e deixa o MindAR.js fazer image tracking pelo navegador.
///
/// O arquivo `book_cover.mind` (alvo compilado) precisa ter sido
/// gerado externamente — ver `assets/mindar/README.md`.
class MindArScanner extends StatefulWidget {
  final CollectionItem item;
  const MindArScanner({super.key, required this.item});

  @override
  State<MindArScanner> createState() => _MindArScannerState();
}

class _MindArScannerState extends State<MindArScanner> {
  static const _port = 8080;

  final _localhostServer = InAppLocalhostServer(
    documentRoot: 'assets',
    port: _port,
  );

  bool _serverReady = false;
  bool _hasTargetFile = true;
  String? _bootError;

  @override
  void initState() {
    super.initState();
    _boot();
  }

  Future<void> _boot() async {
    try {
      await rootBundle.load('assets/mindar/book_cover.mind');
    } catch (_) {
      setState(() => _hasTargetFile = false);
    }

    try {
      await _localhostServer.start();
      if (!mounted) return;
      setState(() => _serverReady = true);
    } catch (e) {
      if (!mounted) return;
      setState(() => _bootError = 'Falha ao iniciar servidor local: $e');
    }
  }

  @override
  void dispose() {
    _localhostServer.close();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    if (_bootError != null) {
      return _errorBox(_bootError!);
    }

    if (!_hasTargetFile) {
      return _errorBox(
        'Arquivo de tracking (book_cover.mind) nao encontrado.\n\n'
        'Gere em https://hiukim.github.io/mind-ar-js-doc/tools/compile\n'
        'e salve em assets/mindar/book_cover.mind.',
      );
    }

    if (!_serverReady) {
      return const Center(child: CircularProgressIndicator());
    }

    return InAppWebView(
      initialUrlRequest: URLRequest(
        url: WebUri('http://localhost:$_port/mindar/index.html'),
      ),
      initialSettings: InAppWebViewSettings(
        mediaPlaybackRequiresUserGesture: false,
        allowsInlineMediaPlayback: true,
        iframeAllow: 'camera; microphone',
        iframeAllowFullscreen: true,
        useOnLoadResource: false,
      ),
      onPermissionRequest: (controller, request) async {
        return PermissionResponse(
          resources: request.resources,
          action: PermissionResponseAction.GRANT,
        );
      },
    );
  }

  Widget _errorBox(String msg) {
    return Container(
      color: Colors.black,
      alignment: Alignment.center,
      padding: const EdgeInsets.all(24),
      child: Text(
        msg,
        style: const TextStyle(color: Colors.white, fontSize: 14, height: 1.4),
        textAlign: TextAlign.center,
      ),
    );
  }
}
