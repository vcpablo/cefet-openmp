# Programação em C no Linux

## Instalação

`sudo apt-get update`

`sudo apt-get install gcc`

## Compilação

`gcc programa.c -o executavel`

- `-o`: gera um executável
- `executavel`: nome do executável a ser gerado

## Execução

`./executavel`

# Sugestões

Como vai ter muita gente trabalhando nesse projeto ao mesmo tempo, pra evitar conflitos nos arquivos, é melhor criarmos **uma branch pra cada algoritmo**.

Depois que a implementação estiver terminada, a gente faz o merge.

`git checkout -b bubblesort`

`git add .`

`git commit -m "Bubblesort implementado"`

`git push origin bubblesort`