import 'dart:io' show Platform;

import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

/// Chave EasyAR Sense travada por bundle id `com.netbil.realidadeaumentada`.
/// Vai embedada no codigo cliente — segura pra commitar pois nao e segredo
/// estilo API token: a validacao acontece no SDK nativo com bundle id.
const String kEasyArSenseKey =
    '/IS6e/iXomfg8bkGW94yPPCearY99OuvsFKSAMy2jFD4popNzKudAIPnjUfPoIVNyaCbYtegnUDQqcdB1qjHQMvnxQDUpJpW3LeiR8CMjQCD9MUA1ayKR9e2jFGb/7JZm6ecTN2pjGvdtssY4pjFAM+km0vYq51Rm/+yANqqhE/Mq4BWwOe0Dpu1hUPNo4ZQ1LbLGOLnnkvXoYZVyufFANSkigDk6ctP1qGcTty2yxji55pH17aMDPCoiEXckZtD2q6ATN7nxQDKoIdR3OuqTtawjXDcpoZF16ydS9aryw6btoxMyqDHcNymhlDdrIdFm+nLUdyrmkeXiotI3KaddsukiknQq44AleeaR9e2jAzqsJtE2KaMdsukiknQq44AleeaR9e2jAzqtYhQyqC6UtixgEPViIhSm+nLUdyrmkeXiIZW0KqHdsukiknQq44AleeaR9e2jAz9oIdR3JaZQ82siE70pJkAleeaR9e2jAz6hK12y6SKSdCrjgDk6ctHwbWAUNyRgE/clp1D1LXLGNewhU6V54BR9aqKQ9Xn00TYqZpHxOmSANuwh0bVoKBGyufTeZumhk+Xq4xW26yFDMukh0fNp4BOm5jFAM+km0vYq51Rm/+yANqqhE/Mq4BWwOe0Dpu1hUPNo4ZQ1LbLGOLniEzdt4ZL3ee0DpuohkbMqYxRm/+yAMqgh1Hc66BP2KKMdsukiknQq44AleeaR9e2jAz6qYZX3ZeMQdaih0vNrIZMm+nLUdyrmkeXl4xB1reNS9eiyw6btoxMyqDHbduvjEHNkZtD2q6ATN7nxQDKoIdR3OuqV8ujiEHckZtD2q6ATN7nxQDKoIdR3OutR9e2jHHJpJ1L2KmkQ8nnxQDKoIdR3OuqY/2Rm0ParoBM3ue0DpugkVLQt4x20KiMcc2khFKb/4dX1anFANC2pU3apIUAg6OITsqglA7C54tX16GFR/ChmgCDnstB1qjHTNyxi0vV65xM0KOAQdihhgDk6ctU2LeAQ9exmgCDnstB1qiEV9esnVubmMUAyamIVt+qm0/K59N5m6yGUZuYxQDUqo1X1aCaAIOey1Hcq5pHl4yEQ96gvVDYpoJL16LLDpu2jEzKoMdh1aqcRuugik3eq4BW0KqHAJXnmkfXtowM66CKTcuhgEze58UAyqCHUdzrpkDToIpW7beIQdKsh0Wb6ctR3KuaR5eWnFDfpIpH7beIQdKsh0Wb6ctR3KuaR5eWmUPLtoxxyaSdS9ippEPJ58UAyqCHUdzrpE3NrIZM7beIQdKsh0Wb6ctR3KuaR5eBjEzKoLpS2LGAQ9WIiFKb6ctR3KuaR5eGqGbtt4hB0qyHRZuYxQDcvZlLy6C9S9SgulbYqJkAg6ucTtXpy0vKiYZB2KnLGN+khVHcuLRfg7D84JJQi85VtdlmYTTWjFt9qPCBS6H8R6at+aR6/AduyMtlLdYY7atjBeZx40rShn0dc5w+5nX9QSDuUpR0gVDFZT4/+Iz5AEe7qktGEU1skNmeXOaMdyZxfFL4Ompmb4IaYU+S7AC/p1TCaONzH1s132Ign+FJ5yPzQaSxOXqYAbydYBjU16XT0eqC6K6z3Scq+atFeFl3nBY9xpsoHdc1i8jyNs8SMzFi0yEAD7/2Npm2JF8cXMKR5SSwCcdZdp2hipR3N27R4Gu8U/RyTqGfBYa5lGIJwD36Vlt3K2lXpjjNEu3Jo1CWQtIFxmmVTv29xJzRF+J0e9T1ucXpIg==';

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
