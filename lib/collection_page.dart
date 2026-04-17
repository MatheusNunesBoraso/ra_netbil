import 'package:flutter/material.dart';
import 'package:permission_handler/permission_handler.dart';

import 'ar_scanner_page.dart';
import 'models/catalog.dart';

class CollectionPage extends StatelessWidget {
  final Collection collection;
  const CollectionPage({super.key, required this.collection});

  Future<void> _openScanner(BuildContext context, CollectionItem item) async {
    final status = await Permission.camera.request();
    if (!status.isGranted) {
      if (context.mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(content: Text('Permiss\u00e3o de c\u00e2mera necess\u00e1ria.')),
        );
      }
      return;
    }
    if (!context.mounted) return;
    Navigator.of(context).push(
      MaterialPageRoute(builder: (_) => ArScannerPage(item: item)),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(collection.name),
        backgroundColor: collection.color,
        foregroundColor: Colors.white,
      ),
      body: SafeArea(
        child: ListView.separated(
          padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 16),
          itemCount: collection.items.length,
          separatorBuilder: (_, _) => const SizedBox(height: 10),
          itemBuilder: (context, i) {
            final item = collection.items[i];
            return Material(
              color: Theme.of(context).colorScheme.surfaceContainerHighest,
              borderRadius: BorderRadius.circular(14),
              child: InkWell(
                borderRadius: BorderRadius.circular(14),
                onTap: () => _openScanner(context, item),
                child: Padding(
                  padding: const EdgeInsets.all(16),
                  child: Row(
                    children: [
                      Container(
                        width: 44,
                        height: 44,
                        decoration: BoxDecoration(
                          color: collection.color.withValues(alpha: 0.15),
                          borderRadius: BorderRadius.circular(10),
                        ),
                        child: Icon(collection.icon, color: collection.color),
                      ),
                      const SizedBox(width: 14),
                      Expanded(
                        child: Text(
                          item.title,
                          style: const TextStyle(
                            fontSize: 16,
                            fontWeight: FontWeight.w600,
                          ),
                        ),
                      ),
                      const Icon(Icons.arrow_forward_ios, size: 16),
                    ],
                  ),
                ),
              ),
            );
          },
        ),
      ),
    );
  }
}
