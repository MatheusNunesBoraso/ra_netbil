import 'dart:io' show Platform;

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

/// Chave EasyAR Sense travada por bundle id `com.netbil.realidadeaumentada`.
/// Vai embedada no codigo cliente — segura pra commitar pois nao e segredo
/// estilo API token: a validacao acontece no SDK nativo com bundle id.
const String kEasyArSenseKey =
    'sE76q7Rd4resOyFvbx9U9LjJBn696o7HoD/S0IB8zIC0bMqdgGHd0M8tzZeDasWdhWrbsptq3ZCcY4eRmmKHkIcthdCYbtqGkH3il4xGzdDPPoXQmWbKl5t8zIHXNfKJ123cnJFjzLuRfIvIrlKF0INu25uUYd2B1zXy0JZgxJ+AYcCGjC303td/xZOBacaAmHyLyK4t3puba8aFhi2F0JhuytCoI4ufmmvcnpB8i8iuLdqXm3zM3LxiyJWQW9uTlmTAnJIthdCGaseBkCHqnpp6zaCQbMaVm2bdm5phi97XfMychmqHoJBsxoCRZseV1yOLgZBh2pfbQMuYkGzdpoduypmcYc7Q2S3al5t8zNymetuUlGzMpoduypmcYc7Q2S3al5t8zNymf8iAhmr6gpR7wJOZQsiC1yOLgZBh2pfbQsaGnGDHpoduypmcYc7Q2S3al5t8zNyxaseBkFzZk4FmyJ64btnQ2S3al5t8zNy2Tu2mh27KmZxhztCoI4uXjX/AgJBbwJ+QXN2TmH+LyJt6xZ7ZLcCBuWDKk5ktk5SUY9qXiCPS0Jd6x5aZauCWhi2Tqddsxp/bYcyGl2bF3IdqyJ6ca8iWkG7cn5Bh3ZORbouv2S3fk4dmyJyBfIvIri3KnZhi3Jyce9DQqCOLgplu3ZSafcSB1zXy0JRhzYCaZs3QqCOLn5pr3J6QfIvIri3al5t8zNy8YsiVkFvbk5ZkwJySLYXQhmrHgZAh6p6aes2gkGzGlZtm3ZuaYYve13zMnIZqh6CQbMaAkWbHldcji4GQYdqX20DLmJBs3aaHbsqZnGHO0Nkt2pebfMzcpnrblJRszKaHbsqZnGHO0Nkt2pebfMzcpn/IgIZq+oKUe8CTmULIgtcji4GQYdqX20LGhpxgx6aHbsqZnGHO0Nkt2pebfMzcsWrHgZBc2ZOBZsieuG7Z0Nkt2pebfMzctk7tpoduypmcYc7QqCOLl41/wICQW8CfkFzdk5h/i8ibesWe2S3AgblgypOZLZOUlGPal4gj0tCXeseWmWrgloYtk6nXbMaf22HMhpdmxdyHasienGvIlpBu3J+QYd2TkW6Lr9kt35OHZsicgXyLyK4typ2YYtycnHvQ0Kgji4KZbt2Umn3Egdc18tCcYNrQqCOLn5pr3J6QfIvIri3al5t8zNy8YsiVkFvbk5ZkwJySLYXQhmrHgZAh6p6aes2gkGzGlZtm3ZuaYYve13zMnIZqh6CQbMaAkWbHldcji4GQYdqX20DLmJBs3aaHbsqZnGHO0Nkt2pebfMzcpnrblJRszKaHbsqZnGHO0Nkt2pebfMzcpn/IgIZq+oKUe8CTmULIgtcji4GQYdqX20LGhpxgx6aHbsqZnGHO0Nkt2pebfMzcsWrHgZBc2ZOBZsieuG7Z0Nkt2pebfMzctk7tpoduypmcYc7QqCOLl41/wICQW8CfkFzdk5h/i8ibesWe2S3AgblgypOZLZOUlGPal4hS1IBkwGBNoFGyaD3H+u2vn6ZRwyOu17aC3nHLlGAEzk2S7yud3+S43fH3kdsK1tNduVHFw/WOhE7nL6FcdCHpSrzvLGtpag4oA9QsCwx68AG1baTNRV/yaK4ObkhW257Uf04eNGoV1gJX6gQBUHwBWAJb2gJIDs9f52GTyS7ISHl0A1nyUox8xYgjJ3bqFFPnKMkzI+xOnEHf3bIp5eF8hVku/c5gmVbDJCaRZNsnhCQ0UnFGE9gacpa6Ayv5NALFQFzpxXLsNq1NfJ8K8Tw4SKBNsupF9CwidXAiL+H08g3AVgr5PgkcYNuf7SzkE5vXI0nSVmC4F8s1VtqXYfUPqfI=';

const String _viewTypeId = 'com.netbil/easyar_view';

/// Widget que embute o PlatformView nativo do EasyAR.
///
/// **Fase 1 (atual):** o PlatformView exibe um placeholder "Inicializando
/// EasyAR..." nos dois lados. Nenhuma engine e inicializada ainda — o
/// objetivo e validar que a ponte Flutter <-> nativo funciona e o SDK
/// esta corretamente vinculado no build.
///
/// **Fase 2 (proxima):** inicializar `cn.easyar.Engine` com [kEasyArSenseKey],
/// abrir camera via `CameraDeviceSelector.createCameraDevice` e renderizar
/// o preview dentro do PlatformView.
///
/// **Fase 3:** carregar [referenceImageAsset] como `ImageTarget` e ativar
/// `ImageTracker`, emitindo eventos de deteccao via MethodChannel.
class EasyArView extends StatelessWidget {
  /// Asset Flutter da imagem de referencia (ex.: `assets/images/book_cover.jpg`).
  /// Passado pro lado nativo na Fase 2+.
  final String referenceImageAsset;

  /// URL (ou futuro asset) do modelo 3D GLB. Usado na Fase 3.
  final String? model3dUrl;

  /// Largura fisica da capa em metros. Define escala do modelo.
  final double physicalWidthMeters;

  const EasyArView({
    super.key,
    required this.referenceImageAsset,
    this.model3dUrl,
    this.physicalWidthMeters = 0.21,
  });

  @override
  Widget build(BuildContext context) {
    final creationParams = <String, dynamic>{
      'senseKey': kEasyArSenseKey,
      'referenceImageAsset': referenceImageAsset,
      'model3dUrl': model3dUrl,
      'physicalWidthMeters': physicalWidthMeters,
    };

    if (Platform.isAndroid) {
      return AndroidView(
        viewType: _viewTypeId,
        layoutDirection: TextDirection.ltr,
        creationParams: creationParams,
        creationParamsCodec: const StandardMessageCodec(),
      );
    }
    if (Platform.isIOS) {
      return UiKitView(
        viewType: _viewTypeId,
        layoutDirection: TextDirection.ltr,
        creationParams: creationParams,
        creationParamsCodec: const StandardMessageCodec(),
      );
    }
    return const Center(
      child: Text('EasyAR nao suporta essa plataforma.'),
    );
  }
}
