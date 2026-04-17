# RA Netbil — Livro em Realidade Aumentada

Flutter app que escaneia a capa de um livro e exibe conteúdo 3D em RA.
Android (ARCore) + iOS (ARKit).

## Como obter os binários (.apk e .ipa)

Você **não precisa** compilar localmente. O CI do GitHub Actions gera os dois
artefatos automaticamente a cada push.

### Setup (uma vez só)
1. Crie um repositório novo no GitHub (pode ser privado).
2. Faça push deste projeto:
   ```bash
   cd C:\.dev\github\ra_netbil2.0
   git init
   git add .
   git commit -m "init"
   git remote add origin git@github.com:SEU_USER/ra_netbil.git
   git push -u origin main
   ```
3. No GitHub, aba **Actions** → workflow **"Build Android APK + iOS IPA"** roda sozinho.

### Baixar os artefatos
1. Abra o run mais recente na aba **Actions**.
2. Role até o final → seção **Artifacts**:
   - `ra-netbil-android-apk` → contém `app-release.apk`.
   - `ra-netbil-ios-ipa-unsigned` → contém `Runner.ipa` (não assinado).
3. Faça upload do `Runner.ipa` no [TestApp.io](https://portal.testapp.io/).
4. O `.apk` você instala direto no Android (ative "origens desconhecidas").

### Rodar manualmente
Na aba **Actions** → workflow → botão **Run workflow**.

## Antes do primeiro build: trocar a capa

O repo inclui um placeholder de 1×1 pixel pra CI compilar. Pra detecção
funcionar, **substitua a capa real** em DOIS lugares com a mesma imagem:

1. `assets/images/book_cover.jpg` (usado pelo Android / ARCore)
2. `ios/Runner/Assets.xcassets/AR Resources.arresourcegroup/book_cover.arreferenceimage/book_cover.jpg`
   (usado pelo iOS / ARKit)

E ajuste a largura real da capa em metros no arquivo:
`ios/Runner/Assets.xcassets/AR Resources.arresourcegroup/book_cover.arreferenceimage/Contents.json`
→ campo `"width"` (ex: `0.15` para uma capa de 15cm de largura).

Valide a qualidade da imagem para ARCore com o
[arcoreimg](https://developers.google.com/ar/develop/augmented-images/arcoreimg).

## Estrutura

```
lib/
├── main.dart                  # Home com botão "Escanear capa"
├── ar_scanner_page.dart       # Switch iOS/Android
├── ar_scanner_android.dart    # ARCore + AugmentedImages
└── ar_scanner_ios.dart        # ARKit + imageTracking
assets/
├── images/book_cover.jpg      # Imagem de referência (Android)
└── models/
ios/Runner/Assets.xcassets/
└── AR Resources.arresourcegroup/
    └── book_cover.arreferenceimage/
        ├── Contents.json      # physical width
        └── book_cover.jpg     # Imagem de referência (iOS)
.github/workflows/build.yml    # CI: APK + IPA
```

## Modelos 3D

- **Android**: o código carrega um `.glb` por URL pública (Duck de exemplo).
  Troque o `objectUrl` em `lib/ar_scanner_android.dart`.
- **iOS**: por enquanto mostra uma esfera laranja nativa (primitiva ARKit).
  Para usar `.glb`/`.usdz`, adicione o arquivo em `assets/models/` e troque
  por `ARKitGltfNode(url: 'assets/models/seu_modelo.glb', assetType: AssetType.flutterAsset)`
  em `lib/ar_scanner_ios.dart`.

## Rodando local (opcional)

### Android
Requer **JDK 17+** e Android SDK. Se tiver Java 8, atualize antes.
```bash
flutter pub get
flutter run     # com device Android conectado via USB
```

### iOS
Precisa de **macOS + Xcode**. Não roda em Windows — use o CI.

## Limitações

- IPA gerado é **não-assinado**. Só instala via TestApp.io, AltStore, Sideloadly
  ou similar. Pra TestFlight/App Store, precisa conta Apple Developer + assinatura
  (adicionar certificados como secrets no workflow).
- Placeholder de imagem é 1×1 — não detecta nada. **Substitua antes de testar.**
- iOS começa com esfera 3D simples; troque por modelo `.glb` quando quiser
  paridade visual com Android.
- Plugins AR usam APIs maduras mas antigas (Sceneform no Android está
  descontinuado — ainda funciona). Para produção a longo prazo, considere
  migrar para SDKs mais atuais (Filament, RealityKit direto).
