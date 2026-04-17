import 'package:flutter/material.dart';

import 'collection_page.dart';
import 'data/collections.dart';
import 'models/catalog.dart';

class HomePage extends StatelessWidget {
  const HomePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Realidade Aumentada'),
        centerTitle: true,
      ),
      body: SafeArea(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            const Padding(
              padding: EdgeInsets.fromLTRB(20, 16, 20, 12),
              child: Text(
                'Escolha uma cole\u00e7\u00e3o',
                style: TextStyle(fontSize: 20, fontWeight: FontWeight.w600),
              ),
            ),
            Expanded(
              child: GridView.builder(
                padding: const EdgeInsets.fromLTRB(16, 4, 16, 24),
                gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                  crossAxisCount: 2,
                  mainAxisSpacing: 14,
                  crossAxisSpacing: 14,
                  childAspectRatio: 0.95,
                ),
                itemCount: kCollections.length,
                itemBuilder: (context, i) => _CollectionCard(kCollections[i]),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

class _CollectionCard extends StatelessWidget {
  final Collection collection;
  const _CollectionCard(this.collection);

  @override
  Widget build(BuildContext context) {
    return Material(
      color: collection.color,
      borderRadius: BorderRadius.circular(18),
      elevation: 2,
      child: InkWell(
        borderRadius: BorderRadius.circular(18),
        onTap: () => Navigator.of(context).push(
          MaterialPageRoute(
            builder: (_) => CollectionPage(collection: collection),
          ),
        ),
        child: Padding(
          padding: const EdgeInsets.all(16),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Icon(collection.icon, size: 44, color: Colors.white),
              Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                mainAxisSize: MainAxisSize.min,
                children: [
                  Text(
                    collection.name,
                    style: const TextStyle(
                      color: Colors.white,
                      fontSize: 20,
                      fontWeight: FontWeight.w700,
                    ),
                  ),
                  const SizedBox(height: 2),
                  Text(
                    '${collection.items.length} ${collection.items.length == 1 ? "item" : "itens"}',
                    style: TextStyle(
                      color: Colors.white.withValues(alpha: 0.85),
                      fontSize: 13,
                    ),
                  ),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }
}
