O protótipo baixa um modelo 3D remoto (Duck.glb do repo oficial do Khronos)
ao detectar a capa. Para usar um modelo local:

1. Coloque seu arquivo .glb nesta pasta (ex: book_scene.glb).
2. Em lib/ar_scanner_page.dart, troque o campo `objectUrl` do ArCoreReferenceNode
   para apontar para um asset empacotado ou para um arquivo hospedado em seu proprio servidor.
   O plugin arcore_flutter_plugin aceita URL http(s) publica.
   Para assets locais, copie para armazenamento interno via path_provider e use o path file://.

Formatos recomendados:
- .glb (binario gLTF) -> melhor suporte.
- .gltf + texturas -> funciona, mas exige CORS/URL consistente.

Escala:
- Ajuste vm.Vector3(scale) no codigo. Modelos grandes podem sumir "dentro" da mesa
  ou ficar enormes. Comece com 0.1-0.2 e refine.
