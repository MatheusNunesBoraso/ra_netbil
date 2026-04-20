import Flutter
import UIKit

/// PlatformView iOS do EasyAR.
///
/// Fase 1: exibe um UIView preto com labels mostrando que a ponte
/// Flutter <-> Swift funciona e os creationParams chegaram.
///
/// Fase 2: substituir por uma UIView contendo EAGLLayer ou MTKView,
/// chamar `easyar.Engine.initialize(with: senseKey)`, criar camera
/// e image tracker, e renderizar preview.
class EasyArPlatformView: NSObject, FlutterPlatformView {
    private let container: UIView

    init(
        frame: CGRect,
        viewId: Int64,
        params: [String: Any],
        messenger: FlutterBinaryMessenger
    ) {
        let root = UIView(frame: frame)
        root.backgroundColor = .black

        let stack = UIStackView()
        stack.axis = .vertical
        stack.alignment = .center
        stack.distribution = .equalSpacing
        stack.spacing = 8
        stack.translatesAutoresizingMaskIntoConstraints = false

        let title = UILabel()
        title.text = "EasyAR — Fase 1"
        title.font = .systemFont(ofSize: 18, weight: .semibold)
        title.textColor = .white

        let subtitle = UILabel()
        subtitle.numberOfLines = 0
        subtitle.textAlignment = .center
        subtitle.textColor = .lightGray
        subtitle.font = .systemFont(ofSize: 14)
        let asset = params["referenceImageAsset"] as? String ?? "?"
        subtitle.text = """
        Ponte Flutter <-> nativo OK
        Asset: \(asset)
        Proxima fase: camera + detecao
        """

        stack.addArrangedSubview(title)
        stack.addArrangedSubview(subtitle)
        root.addSubview(stack)

        NSLayoutConstraint.activate([
            stack.centerXAnchor.constraint(equalTo: root.centerXAnchor),
            stack.centerYAnchor.constraint(equalTo: root.centerYAnchor),
            stack.leadingAnchor.constraint(greaterThanOrEqualTo: root.leadingAnchor, constant: 16),
            stack.trailingAnchor.constraint(lessThanOrEqualTo: root.trailingAnchor, constant: -16),
        ])

        self.container = root
        super.init()
    }

    func view() -> UIView {
        return container
    }
}
