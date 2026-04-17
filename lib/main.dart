import 'package:flutter/material.dart';
import 'package:permission_handler/permission_handler.dart';

import 'ar_scanner_page.dart';

void main() {
  runApp(const RaNetbilApp());
}

class RaNetbilApp extends StatelessWidget {
  const RaNetbilApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'RA Netbil',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.indigo),
        useMaterial3: true,
      ),
      home: const HomePage(),
    );
  }
}

class HomePage extends StatelessWidget {
  const HomePage({super.key});

  Future<void> _start(BuildContext context) async {
    final status = await Permission.camera.request();
    if (!status.isGranted) {
      if (context.mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(content: Text('Permissao de camera necessaria.')),
        );
      }
      return;
    }
    if (!context.mounted) return;
    Navigator.of(context).push(
      MaterialPageRoute(builder: (_) => const ArScannerPage()),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('RA Netbil')),
      body: Padding(
        padding: const EdgeInsets.all(24),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const Icon(Icons.menu_book, size: 96),
            const SizedBox(height: 16),
            const Text(
              'Aponte a camera para a capa do livro para ver o conteudo em 3D.',
              textAlign: TextAlign.center,
              style: TextStyle(fontSize: 16),
            ),
            const SizedBox(height: 32),
            FilledButton.icon(
              onPressed: () => _start(context),
              icon: const Icon(Icons.camera_alt),
              label: const Text('Escanear capa'),
            ),
          ],
        ),
      ),
    );
  }
}
