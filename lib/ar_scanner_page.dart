import 'dart:io' show Platform;

import 'package:flutter/material.dart';

import 'ar_method.dart';
import 'ar_method_service.dart';
import 'ar_scanner_android.dart';
import 'ar_scanner_ios.dart';
import 'ar_scanners/easyar_stub.dart';
import 'ar_scanners/mindar_scanner.dart';
import 'ar_scanners/modern_scanner.dart';
import 'models/catalog.dart';

class ArScannerPage extends StatefulWidget {
  final CollectionItem item;
  const ArScannerPage({super.key, required this.item});

  @override
  State<ArScannerPage> createState() => _ArScannerPageState();
}

class _ArScannerPageState extends State<ArScannerPage> {
  ArMethod? _method;

  @override
  void initState() {
    super.initState();
    ArMethodService.get().then((m) {
      if (mounted) setState(() => _method = m);
    });
  }

  @override
  Widget build(BuildContext context) {
    final method = _method;
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.item.title),
        bottom: method == null
            ? null
            : PreferredSize(
                preferredSize: const Size.fromHeight(28),
                child: Container(
                  alignment: Alignment.centerLeft,
                  padding: const EdgeInsets.fromLTRB(16, 0, 16, 6),
                  child: Text(
                    'Metodo: ${method.label}',
                    style: TextStyle(
                      color: Colors.white.withValues(alpha: 0.85),
                      fontSize: 12,
                    ),
                  ),
                ),
              ),
      ),
      body: method == null
          ? const Center(child: CircularProgressIndicator())
          : _buildScanner(method),
    );
  }

  Widget _buildScanner(ArMethod method) {
    switch (method) {
      case ArMethod.original:
        return Platform.isIOS
            ? ArScannerIos(item: widget.item)
            : ArScannerAndroid(item: widget.item);
      case ArMethod.planeTap:
        return ModernScanner(item: widget.item);
      case ArMethod.mindar:
        return MindArScanner(item: widget.item);
      case ArMethod.easyar:
        return EasyArStub(item: widget.item);
    }
  }
}
