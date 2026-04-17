import 'dart:io' show Platform;

import 'package:flutter/material.dart';

import 'ar_scanner_android.dart';
import 'ar_scanner_ios.dart';
import 'models/catalog.dart';

class ArScannerPage extends StatelessWidget {
  final CollectionItem item;
  const ArScannerPage({super.key, required this.item});

  @override
  Widget build(BuildContext context) {
    final Widget scanner = Platform.isIOS
        ? ArScannerIos(item: item)
        : ArScannerAndroid(item: item);
    return Scaffold(
      appBar: AppBar(title: Text(item.title)),
      body: scanner,
    );
  }
}
