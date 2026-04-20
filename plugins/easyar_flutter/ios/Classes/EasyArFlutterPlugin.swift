import Flutter
import UIKit

/// Plugin raiz do easyar_flutter no iOS.
///
/// Fase 1: so registra a factory de PlatformView. A factory retorna
/// uma UIView com label "EasyAR — Fase 1". Nenhuma chamada real ao
/// SDK EasyAR acontece ainda — objetivo e validar que o xcframework
/// esta linkado no build e a ponte Flutter <-> Swift funciona.
///
/// Fase 2: inicializar `easyar.Engine` com a chave Sense, abrir camera,
/// renderizar preview dentro da UIView via Metal/EAGL.
public class EasyArFlutterPlugin: NSObject, FlutterPlugin {

    public static func register(with registrar: FlutterPluginRegistrar) {
        let factory = EasyArViewFactory(messenger: registrar.messenger())
        registrar.register(factory, withId: "com.netbil/easyar_view")
    }
}
