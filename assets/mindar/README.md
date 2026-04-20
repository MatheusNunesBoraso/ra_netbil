# MindAR assets

Esta pasta contem os arquivos estaticos servidos pelo `InAppLocalhostServer`
quando o usuario escolhe o backend **MindAR** no seletor da home.

## Arquivos

- `index.html` — pagina que inicializa MindAR + A-Frame e carrega o modelo 3D.
- `book_cover.mind` — **alvo de tracking compilado** a partir da capa do livro.
  **NAO e gerado automaticamente.** Veja secao abaixo.

## Como gerar o `book_cover.mind`

1. Acesse https://hiukim.github.io/mind-ar-js-doc/tools/compile/
2. Faca upload de `assets/images/book_cover.jpg`
3. Clique em **Start** e espere o compilador processar.
4. Clique em **Download** — o arquivo `targets.mind` sera baixado.
5. Renomeie para `book_cover.mind` e salve aqui.
6. Rode `flutter pub get` e buildo app.

Quando a capa mudar, refaca o processo. Da pra automatizar depois com
`@hiukim/mind-ar-js-tools` (CLI Node) se virar incomodo.
