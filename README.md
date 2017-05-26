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

# Trabalho

O trabalho consistirá em um entregar um relatório analisando como 6 algoritmos podem ser
paralelizados utilizando a biblioteca OpenMP. São eles:

1. Bubblesort
2. Odd-Even Transposition Sort
3. CountSort
4. Shellsort
5. Binary search
6. Linear search

O relatório deverá conter, para cada um dos algoritmos acima:

1. Uma descrição do algoritmo serial
2. Uma descrição do algoritmo paralelizado. Essa descrição deverá salientar quais os
principais pontos da implementação.
3. Uma comparação de desempenho entre os algoritmos serial e paralelo (considere
vetores com elementos de 10 milhões de posições), sob os critérios de **Speedup**,
**Eficiência**, e **Escalabilidade**.
4. Uma análise da utilização da cache pelo programa (utilize o analisador de cache
**Valgrind**). Procure explicar a alta/baixa taxa de **cache miss** observada, sob a ótica do
**compartilhamento falso**.

# Sugestões

Como vai ter muita gente trabalhando nesse projeto ao mesmo tempo, pra evitar conflitos nos arquivos, é melhor criarmos **uma branch pra cada algoritmo**.

Depois que a implementação estiver terminada, a gente faz o merge.

`git checkout -b bubblesort`

`git add .`

`git commit -m "Bubblesort implementado"`

`git push origin bubblesort`


