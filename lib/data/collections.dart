import 'package:flutter/material.dart';

import '../models/catalog.dart';

/// Placeholder unico enquanto os assets reais nao chegam.
/// Quando cada item tiver sua capa/modelo, trocar apenas os campos
/// `referenceImageAsset`, `referenceImageName` e `model3dUrl` abaixo.
const _placeholderImage = 'assets/images/book_cover.jpg';
const _placeholderImageName = 'book_cover';
const _placeholderModel =
    'https://raw.githubusercontent.com/KhronosGroup/glTF-Sample-Models/master/2.0/Duck/glTF-Binary/Duck.glb';

CollectionItem _placeholder(String id, String title) => CollectionItem(
      id: id,
      title: title,
      referenceImageAsset: _placeholderImage,
      referenceImageName: _placeholderImageName,
      model3dUrl: _placeholderModel,
    );

final List<Collection> kCollections = [
  Collection(
    id: 'prisma',
    name: 'Prisma',
    color: const Color(0xFF7C3AED),
    icon: Icons.auto_awesome,
    items: [
      _placeholder('prisma_03', 'Livro 03'),
      _placeholder('prisma_04', 'Livro 04'),
      _placeholder('prisma_05', 'Livro 05'),
      _placeholder('prisma_06', 'Livro 06'),
    ],
  ),
  Collection(
    id: 'ativamente',
    name: 'Ativamente',
    color: const Color(0xFFEF4444),
    icon: Icons.bolt,
    items: [
      _placeholder('ativamente_1', '1\u00ba ano'),
      _placeholder('ativamente_2', '2\u00ba ano'),
      _placeholder('ativamente_3', '3\u00ba ano'),
      _placeholder('ativamente_4', '4\u00ba ano'),
      _placeholder('ativamente_5', '5\u00ba ano'),
    ],
  ),
  Collection(
    id: 'frisbee',
    name: 'Frisbee',
    color: const Color(0xFF10B981),
    icon: Icons.sports_baseball,
    items: [
      _placeholder('frisbee_1', '1\u00ba ano'),
      _placeholder('frisbee_2', '2\u00ba ano'),
      _placeholder('frisbee_3', '3\u00ba ano'),
      _placeholder('frisbee_4', '4\u00ba ano'),
      _placeholder('frisbee_5', '5\u00ba ano'),
    ],
  ),
  Collection(
    id: 'alcance',
    name: 'Alcance',
    color: const Color(0xFF3B82F6),
    icon: Icons.flag,
    items: [
      _placeholder('alcance_6', '6\u00ba ano'),
      _placeholder('alcance_7', '7\u00ba ano'),
      _placeholder('alcance_8', '8\u00ba ano'),
      _placeholder('alcance_9', '9\u00ba ano'),
    ],
  ),
  Collection(
    id: 'calesita',
    name: 'Calesita',
    color: const Color(0xFFF59E0B),
    icon: Icons.attractions,
    items: [
      _placeholder('calesita_1', '1\u00ba ano'),
      _placeholder('calesita_2', '2\u00ba ano'),
      _placeholder('calesita_3', '3\u00ba ano'),
      _placeholder('calesita_4', '4\u00ba ano'),
      _placeholder('calesita_5', '5\u00ba ano'),
    ],
  ),
];
