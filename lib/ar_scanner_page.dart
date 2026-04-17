import 'dart:io' show Platform;

import 'package:flutter/material.dart';

import 'ar_scanner_android.dart';
import 'ar_scanner_ios.dart';

class ArScannerPage extends StatelessWidget {
  const ArScannerPage({super.key});

  @override
  Widget build(BuildContext context) {
    final Widget scanner =
        Platform.isIOS ? const ArScannerIos() : const ArScannerAndroid();
    return Scaffold(
      appBar: AppBar(title: const Text('Scanner AR')),
      body: scanner,
    );
  }
}
