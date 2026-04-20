# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## O que é este repo

App Flutter de Realidade Aumentada: escaneia a capa de um livro e ancora um modelo 3D sobre ela. Suporta Android (ARCore via `arcore_flutter_plugin`) e iOS (ARKit via `arkit_plugin`). Os binários são produzidos **pelo CI do GitHub Actions**, não localmente — a máquina de desenvolvimento é Windows e não tem toolchain iOS.

## Comandos úteis

```bash
flutter pub get                          # instala dependências
flutter analyze                          # único check estático que roda local
flutter test                             # testes Flutter (usar antes de push)
flutter test test/widget_test.dart       # um arquivo específico

# Build local quase nunca é usado:
# - Android local exige JDK 17+ (o sistema aqui tem 8, então falha).
# - iOS local não roda em Windows.
# Para gerar .apk e .ipa, use o workflow .github/workflows/build.yml
# (push para main ou "Run workflow" manual).
```

Cada run do workflow incrementa a versão: `run #N` → `v1.0.N` no `--build-name`/`--build-number` e no nome do artifact (`ra-netbil-v1.0.N.apk` / `ra-netbil-v1.0.N.ipa`).

## Arquitetura em alto nível

### Navegação e dados

```
lib/main.dart (RaNetbilApp)
  └─ home_page.dart (grid das 5 coleções)
       └─ collection_page.dart (lista de itens da coleção + pede Permission.camera)
            └─ ar_scanner_page.dart (switch Platform.isIOS)
                 ├─ ar_scanner_android.dart (ARCore AugmentedImages)
                 └─ ar_scanner_ios.dart    (ARKit imageTracking)
```

- `lib/models/catalog.dart` define `Collection` e `CollectionItem`. Cada item carrega `referenceImageAsset` (path Android/Flutter), `referenceImageName` (nome no AR Resource Group iOS), `model3dUrl` e `physicalWidthMeters`.
- `lib/data/collections.dart` é o catálogo hardcoded das 5 coleções (Prisma, Ativamente, Frisbee, Alcance, Calesita). Enquanto os assets reais de cada livro não chegam, todos os itens apontam para um único placeholder (`book_cover.jpg` + Duck.glb remoto). Trocar por assets reais é só alterar os campos desse arquivo — nenhuma mudança de navegação.
- `CollectionItem.physicalWidthMeters` é usado tanto para a escala do modelo 3D (Vector3 no Android) quanto para o escalonamento conceitual no iOS. Hoje default = 0.21 (livro 21 cm de largura).

### Imagem de referência — DUAS cópias sincronizadas

A mesma capa precisa existir em dois lugares; o CI não copia entre eles:

1. `assets/images/book_cover.jpg` — usado pelo Android (`rootBundle.load` em runtime).
2. `ios/Runner/Assets.xcassets/AR Resources.arresourcegroup/book_cover.arreferenceimage/book_cover.jpg` — empacotado pelo Xcode asset catalog; o nome da imageset (`book_cover`) é o que o Dart referencia via `detectionImagesGroupName: 'AR Resources'`.

Ao trocar a capa, **sempre atualizar ambas** + o campo `"width"` em `Contents.json` (em metros) para a largura física real.

## Pontos sensíveis do CI (`.github/workflows/build.yml`)

Plugins AR usados são antigos (2019-2022) e precisam de patches em runtime:

- **`arcore_flutter_plugin` 0.1.0** não declara `namespace` nem suporta AGP 8+, e usa `compileSdkVersion 29` (sem `android:attr/lStar`). O step **"Patch arcore_flutter_plugin"** edita o `build.gradle` do plugin em `~/.pub-cache` via `sed` antes do build. Se o build Android quebrar com "Namespace not specified", "resource lStar not found", ou "Duplicate class android.support.*", o patch é o primeiro lugar para mexer (`android/app/build.gradle.kts` também exclui `com.android.support` transitivo e desabilita minify/R8 no release — Sceneform tem classes referenciadas via reflection que R8 removeria).

- **Job Android está desligado** (`if: false`) — só iOS roda. Reativar removendo a linha quando precisar.

- **Signing iOS é manual** (não automatic), configurado **no pbxproj** em Release e Profile (CODE_SIGN_IDENTITY="Apple Distribution", PROVISIONING_PROFILE_SPECIFIER="RA Netbil App Store", DEVELOPMENT_TEAM=CDW5CS3MHV). Sem isso, `flutter build ipa` faz preflight procurando cert de Development e falha mesmo quando exportando em `app-store`. Alterar `ios/ExportOptions.plist` e o pbxproj juntos se mudar team/profile.

- **Pipeline iOS faz 3 saídas**: artifact (`.ipa` dentro de zip), upload para App Store Connect via `xcrun altool` (TestFlight), e GitHub Release pública com `.ipa` direto. O upload TestFlight só roda se os 3 secrets `APPSTORE_API_*` estiverem presentes — caso contrário skipa com notice.

- **Podfile** tem `post_install` que adiciona `PERMISSION_CAMERA=1` ao preprocessador. Sem isso, `permission_handler` no iOS retorna `denied` sem mostrar o prompt do sistema. Se adicionar nova permissão (microfone, fotos, etc.) precisa acrescentar a flag correspondente aqui.

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

Arquivos de origem estão fora do repo em `C:\Users\Mathe\ios-signing\` — estrutura separada em `_team/` (reusável para qualquer app da Netbil) e `apps/com.netbil.realidadeaumentada/` (específico deste app, inclui `secrets/*.txt` prontos para colar).

## Identidade do app

- Bundle ID (iOS e Android `applicationId`): `com.netbil.realidadeaumentada`
- Team Apple: NETBIL EDUCACIONAL E INFORMATICA LTDA (`CDW5CS3MHV`)
- Apple Account Holder: Lucia Barbieri (`developer@netbil.com.br`)
- Distribuição: TestFlight (profile tipo App Store — IPAs não instalam direto em iPhone por design da Apple).
