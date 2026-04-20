import 'package:flutter/material.dart';

import 'ar_method.dart';
import 'ar_method_service.dart';
import 'collection_page.dart';
import 'data/collections.dart';
import 'models/catalog.dart';

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  ArMethod _method = ArMethod.original;

  @override
  void initState() {
    super.initState();
    ArMethodService.get().then((m) {
      if (mounted) setState(() => _method = m);
    });
  }

  Future<void> _pickMethod() async {
    final picked = await showModalBottomSheet<ArMethod>(
      context: context,
      showDragHandle: true,
      builder: (ctx) => ListView(
        shrinkWrap: true,
        padding: const EdgeInsets.symmetric(vertical: 8),
        children: [
          const Padding(
            padding: EdgeInsets.fromLTRB(20, 4, 20, 12),
            child: Text(
              'Metodo de AR',
              style: TextStyle(fontSize: 18, fontWeight: FontWeight.w700),
            ),
          ),
          ...ArMethod.values.map(
            (m) => RadioListTile<ArMethod>(
              value: m,
              groupValue: _method,
              onChanged: (v) => Navigator.of(ctx).pop(v),
              title: Text(m.label),
              subtitle: Text(m.description),
              isThreeLine: true,
            ),
          ),
        ],
      ),
    );

    if (picked != null && picked != _method) {
      await ArMethodService.set(picked);
      if (!mounted) return;
      setState(() => _method = picked);
    }
  }

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
            _MethodBar(method: _method, onTap: _pickMethod),
            const Padding(
              padding: EdgeInsets.fromLTRB(20, 12, 20, 12),
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

class _MethodBar extends StatelessWidget {
  final ArMethod method;
  final VoidCallback onTap;
  const _MethodBar({required this.method, required this.onTap});

  @override
  Widget build(BuildContext context) {
    final scheme = Theme.of(context).colorScheme;
    return Padding(
      padding: const EdgeInsets.fromLTRB(16, 12, 16, 0),
      child: Material(
        color: scheme.surfaceContainerHighest,
        borderRadius: BorderRadius.circular(14),
        child: InkWell(
          borderRadius: BorderRadius.circular(14),
          onTap: onTap,
          child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 14, vertical: 12),
            child: Row(
              children: [
                Icon(Icons.settings_suggest, color: scheme.primary),
                const SizedBox(width: 12),
                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      const Text(
                        'Metodo de AR',
                        style: TextStyle(
                          fontSize: 12,
                          fontWeight: FontWeight.w500,
                        ),
                      ),
                      const SizedBox(height: 2),
                      Text(
                        method.label,
                        style: const TextStyle(
                          fontSize: 15,
                          fontWeight: FontWeight.w700,
                        ),
                      ),
                    ],
                  ),
                ),
                const Icon(Icons.unfold_more, size: 20),
              ],
            ),
          ),
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
