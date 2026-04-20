import Flutter
import UIKit

/// PlatformView iOS do EasyAR.
///
/// Fase 2 (atual): chama [EasyArEngineBridge initializeWithKey:] e checa
/// disponibilidade de CameraDevice e ImageTracker. O UI mostra o status
/// real do SDK com linhas ✅/❌. Nenhum preview de camera ainda — isso
/// vem na Fase 3 junto com OpenGL pipeline + image tracking.
///
/// Fase 3: trocar o UIStackView abaixo por uma GLKView que hospeda
/// BGRenderer + BoxRenderer do sample iOS (precisa portar helloar.m,
/// BGRenderer.m, BoxRenderer.m pro plugin). Carregar
/// `referenceImageAsset` copiando o arquivo do Flutter assets pro
/// documents directory e chamar createFromImageFile:storageType:App.
class EasyArPlatformView: NSObject, FlutterPlatformView {
    private let container: UIView
    private let senseKey: String
    private let referenceAsset: String

    private static var engineInitialized: Bool = false
    private static var lastEngineError: String? = nil

    init(
        frame: CGRect,
        viewId: Int64,
        params: [String: Any],
        messenger: FlutterBinaryMessenger
    ) {
        self.senseKey = params["senseKey"] as? String ?? ""
        self.referenceAsset = params["referenceImageAsset"] as? String ?? "?"

        let root = UIView(frame: frame)
        root.backgroundColor = .black
        self.container = root

        super.init()

        // Inicializa a engine apenas uma vez (chamada multipla e no-op mas
        // mantemos o primeiro resultado pra telemetria).
        if !EasyArPlatformView.engineInitialized {
            if let err = EasyArEngineBridge.initialize(withKey: senseKey) {
                EasyArPlatformView.lastEngineError = err
            } else {
                EasyArPlatformView.engineInitialized = true
            }
        }

        buildStatusUI(into: root)
    }

    func view() -> UIView {
        return container
    }

    private func buildStatusUI(into root: UIView) {
        let stack = UIStackView()
        stack.axis = .vertical
        stack.alignment = .leading
        stack.spacing = 8
        stack.translatesAutoresizingMaskIntoConstraints = false

        let title = UILabel()
        title.text = "EasyAR — Fase 2"
        title.font = .systemFont(ofSize: 20, weight: .bold)
        title.textColor = .white

        let subtitle = UILabel()
        subtitle.text = "Validacao do SDK + chave Sense"
        subtitle.font = .systemFont(ofSize: 13)
        subtitle.textColor = .lightGray

        stack.addArrangedSubview(title)
        stack.addArrangedSubview(subtitle)
        stack.addArrangedSubview(spacer(height: 12))

        stack.addArrangedSubview(statusLine(
            label: "Engine.initialize",
            ok: EasyArPlatformView.engineInitialized,
            detail: EasyArPlatformView.lastEngineError ?? "Sense key aceita"
        ))
        stack.addArrangedSubview(statusLine(
            label: "CameraDevice.isAvailable",
            ok: EasyArEngineBridge.isCameraDeviceAvailable(),
            detail: nil
        ))
        stack.addArrangedSubview(statusLine(
            label: "ImageTracker.isAvailable",
            ok: EasyArEngineBridge.isImageTrackerAvailable(),
            detail: nil
        ))

        stack.addArrangedSubview(spacer(height: 12))

        let versionLabel = UILabel()
        versionLabel.text = "SDK: EasyAR Sense \(EasyArEngineBridge.sdkVersion())"
        versionLabel.font = .systemFont(ofSize: 12)
        versionLabel.textColor = .lightGray
        stack.addArrangedSubview(versionLabel)

        let assetLabel = UILabel()
        assetLabel.text = "Asset referencia: \(referenceAsset)"
        assetLabel.font = .systemFont(ofSize: 12)
        assetLabel.textColor = .lightGray
        assetLabel.numberOfLines = 2
        stack.addArrangedSubview(assetLabel)

        stack.addArrangedSubview(spacer(height: 12))

        let next = UILabel()
        next.text = "Proxima: Fase 3 — camera preview + image tracking"
        next.font = .systemFont(ofSize: 12, weight: .medium)
        next.textColor = UIColor(red: 1.0, green: 0.75, blue: 0.2, alpha: 1.0)
        next.numberOfLines = 0
        stack.addArrangedSubview(next)

        root.addSubview(stack)
        NSLayoutConstraint.activate([
            stack.leadingAnchor.constraint(equalTo: root.leadingAnchor, constant: 20),
            stack.trailingAnchor.constraint(lessThanOrEqualTo: root.trailingAnchor, constant: -20),
            stack.centerYAnchor.constraint(equalTo: root.centerYAnchor),
        ])
    }

    private func statusLine(label: String, ok: Bool, detail: String?) -> UIStackView {
        let line = UIStackView()
        line.axis = .vertical
        line.alignment = .leading
        line.spacing = 2

        let main = UILabel()
        main.text = "\(ok ? "✅" : "❌")  \(label)"
        main.font = .systemFont(ofSize: 15, weight: .medium)
        main.textColor = .white
        line.addArrangedSubview(main)

        if let d = detail, !d.isEmpty {
            let sub = UILabel()
            sub.text = d
            sub.font = .systemFont(ofSize: 12)
            sub.textColor = ok ? .lightGray : UIColor(red: 1.0, green: 0.5, blue: 0.5, alpha: 1.0)
            sub.numberOfLines = 0
            line.addArrangedSubview(sub)
        }

        return line
    }

    private func spacer(height: CGFloat) -> UIView {
        let v = UIView()
        v.translatesAutoresizingMaskIntoConstraints = false
        v.heightAnchor.constraint(equalToConstant: height).isActive = true
        return v
    }
}
