# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## O que é este repo

App Flutter de Realidade Aumentada: escaneia a capa de um livro e ancora um modelo 3D sobre ela. Usa **EasyAR Sense 4.8** como motor de image tracking (escolhido depois que ARCore/ARKit/MindAR falharam em detectar a capa). Os binários são produzidos **pelo CI do GitHub Actions**, não localmente — a máquina de desenvolvimento é Windows e não tem toolchain iOS.

## Comandos úteis

```bash
flutter pub get                          # instala dependências (inclui plugin local)
flutter analyze                          # único check estático que roda local
flutter test                             # testes Flutter

# Build local quase nunca é usado — iOS não roda em Windows,
# Android exige JDK 17+. Use o workflow .github/workflows/build.yml.
```

Cada run do workflow incrementa a versão: `run #N` → `v1.0.N` no `--build-name`/`--build-number` e no nome do artifact (`ra-netbil-v1.0.N.ipa`).

## Arquitetura em alto nível

### Navegação e dados

```
lib/main.dart (RaNetbilApp)
  └─ home_page.dart (grid das 5 coleções)
       └─ collection_page.dart (lista de itens + pede Permission.camera)
            └─ ar_scanner_page.dart
                 └─ EasyArView (do plugin local easyar_flutter)
                      ├─ Android: PlatformView Kotlin → EasyAR.aar
                      └─ iOS: FlutterPlatformView Swift → easyar.xcframework
```

- `lib/models/catalog.dart` define `Collection` e `CollectionItem`. Cada item carrega `referenceImageAsset` (asset Flutter da capa), `model3dUrl` (URL ou asset do GLB) e `physicalWidthMeters`.
- `lib/data/collections.dart` é o catálogo hardcoded das 5 coleções (Prisma, Ativamente, Frisbee, Alcance, Calesita). Enquanto os assets reais não chegam, todos os itens apontam pra um placeholder único.
- `CollectionItem.physicalWidthMeters` define a escala do modelo 3D na ancoragem. Default = 0.21 (livro 21 cm de largura).

### Plugin local `plugins/easyar_flutter/`

Plugin Flutter empacotado **dentro** do repo (não publicado em pub.dev). Referenciado em `pubspec.yaml` via `path: plugins/easyar_flutter`.

```
plugins/easyar_flutter/
├── pubspec.yaml                    # declara plataformas android+ios
├── lib/easyar_flutter.dart         # EasyArView (AndroidView/UiKitView) + kEasyArSenseKey
├── android/
│   ├── build.gradle                # implementation files('libs/EasyAR.aar')
│   ├── libs/EasyAR.aar             # 24 MB, binário EasyAR Sense 4.8
│   └── src/main/kotlin/com/netbil/easyar_flutter/
│       ├── EasyArFlutterPlugin.kt  # registra PlatformView factory
│       ├── EasyArViewFactory.kt
│       └── EasyArView.kt           # PlatformView nativo
└── ios/
    ├── easyar_flutter.podspec      # vendored_frameworks: easyar.xcframework
    ├── easyar.xcframework/         # 15 MB, slices ios-arm64 + simulator
    └── Classes/
        ├── EasyArFlutterPlugin.swift
        ├── EasyArViewFactory.swift
        └── EasyArPlatformView.swift
```

**Estado atual (Fase 1):** PlatformView nos dois lados mostra placeholder "EasyAR — Fase 1". Nenhuma chamada à engine EasyAR acontece ainda. Objetivo = validar ponte + linkagem de binários.

**Próximo (Fase 2):** inicializar `cn.easyar.Engine.initialize(context, kEasyArSenseKey)` no Android e equivalente iOS, abrir câmera via `CameraDeviceSelector` e renderizar preview. Ver sample de referência em `/tmp/easyar_ref/samples/Community/Android/HelloARKotlin/` (extraído do 7z, fora do repo).

**Fase 3:** carregar `referenceImageAsset` como `ImageTarget`, ativar `ImageTracker`, emitir eventos de detecção via MethodChannel.

### Chave Sense

Embedada em `plugins/easyar_flutter/lib/easyar_flutter.dart` como `kEasyArSenseKey`. Travada por bundle ID `com.netbil.realidadeaumentada` — o SDK valida em runtime. **Não é segredo** (é chave cliente, tipo chave pública); safe pra commitar. Se trocar de bundle ID, precisa regenerar em easyar.com e substituir a constante.

## Pontos sensíveis do CI (`.github/workflows/build.yml`)

- **Job Android está desligado** (`if: false`) — só iOS roda. Pra reativar: trocar pra `true`. EasyAR.aar está dentro do plugin, então `flutter pub get` resolve naturalmente.

- **Pipeline iOS**: `pod install` consome o `easyar_flutter.podspec` que declara `vendored_frameworks = 'easyar.xcframework'`. Isso copia o framework pra dentro do build. Se o build quebrar com "framework not found" ou "Undefined symbols for arch arm64: \_easyar_*", checar se o xcframework foi commitado corretamente em `plugins/easyar_flutter/ios/easyar.xcframework/`.

- **Signing iOS é manual** (configurado no pbxproj em Release e Profile). CODE_SIGN_IDENTITY="Apple Distribution", PROVISIONING_PROFILE_SPECIFIER="RA Netbil App Store", DEVELOPMENT_TEAM=CDW5CS3MHV.

- **3 saídas**: artifact IPA, upload TestFlight (via `xcrun altool`, se os `APPSTORE_API_*` secrets existirem), e GitHub Release pública.

- **Podfile** tem `post_install` que adiciona `PERMISSION_CAMERA=1` ao preprocessador — sem isso, `permission_handler` no iOS retorna `denied` sem mostrar prompt. Pra adicionar outra permissão (microfone, fotos), acrescentar a flag correspondente lá.

## Secrets do GitHub Actions

4 obrigatórios (iOS signing) + 3 opcionais (TestFlight auto-upload):

| Secret | Origem |
|---|---|
| `IOS_P12_BASE64` | `~/ios-signing/_team/p12/distribution.p12` em base64 |
| `IOS_P12_PASSWORD` | senha do `.p12` |
| `IOS_PROVISION_BASE64` | `ra_netbil_appstore.mobileprovision` em base64 |
| `IOS_TEAM_ID` | `CDW5CS3MHV` |
| `APPSTORE_API_KEY_ID` | id da API Key do App Store Connect |
| `APPSTORE_API_ISSUER_ID` | UUID do issuer |
| `APPSTORE_API_PRIVATE_KEY` | conteúdo do `.p8` |

Arquivos de origem estão fora do repo em `C:\Users\Mathe\ios-signing\`.

## Identidade do app

- Bundle ID (iOS e Android `applicationId`): `com.netbil.realidadeaumentada`
- Team Apple: NETBIL EDUCACIONAL E INFORMATICA LTDA (`CDW5CS3MHV`)
- Apple Account Holder: Lucia Barbieri (`developer@netbil.com.br`)
- Distribuição: TestFlight (profile tipo App Store — IPAs não instalam direto em iPhone por design da Apple).
