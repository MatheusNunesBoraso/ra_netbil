import 'package:flutter/material.dart';

class Collection {
  final String id;
  final String name;
  final Color color;
  final IconData icon;
  final List<CollectionItem> items;

  const Collection({
    required this.id,
    required this.name,
    required this.color,
    required this.icon,
    required this.items,
  });
}

class CollectionItem {
  final String id;
  final String title;

  /// Asset path da imagem de referencia (usada pelo ARCore no Android).
  /// Nome da reference image no iOS AR Resource Group.
  final String referenceImageAsset;
  final String referenceImageName;

  /// URL ou asset local do modelo 3D (glb/gltf).
  final String model3dUrl;

  /// Largura fisica da capa em metros (usada pelo iOS e para escalar o modelo).
  final double physicalWidthMeters;

  const CollectionItem({
    required this.id,
    required this.title,
    required this.referenceImageAsset,
    required this.referenceImageName,
    required this.model3dUrl,
    this.physicalWidthMeters = 0.15,
  });
}
