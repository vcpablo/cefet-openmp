# Programação em C no Linux com OpenMP

## Instalação

`sudo apt-get update`

`sudo apt-get install gcc`

## Compilação

`gcc programa.c -o executavel`

- `-o`: gera um executável
- `executavel`: nome do executável a ser gerado

Para compilar com o OpenMP:

`gcc -fopenmp programa.c -o executavel`

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


# Links importantes

OpenMP
* https://www.ibm.com/developerworks/br/aix/library/au-aix-openmp-framework/


# Programação em C no Linux com MPI

## Instalação

`sudo apt-get install libopenmpi-dev`

## Compilação

No diretório da aplicação

`make clean`

`make all`


## Execução

`mpiexec − n <number of processes> ./executavel`

# Trabalho

O trabalho valerá 4 pontos consistirá em realizar a implementação do algoritmo de ordenação **Counting Sort** utilizando a biblioteca de paralelização **MPI** e responder às seguintes questões

1. Quais são os dados que deverão ser distribuídos por mensagens? Qual  a função MPI você utilizará? Por quê? (1 ponto)
2. Como o resultado final deverá ser composto? Qual a função do MPI você utilizou? Por quê? (1 ponto)
3. Escreva um programa em C ou Java que “paralelize” o Counting Sort utilizando MPI. (1 ponto)
4. Compare o desempenho da função com a original serial, com a função qsort da biblioteca do C e com a implementação com OpenMP. Explique as diferenças encontradas. Você acha possível o MPI “ganhar” do OpenMP ou do qsort? Por quê? (1 ponto)
5. [Bônus] Descubra como executar o programa MPI de forma distribuída, ou seja, com os processos sendo executados em múltiplos computadores. (1 ponto)

O relatório deverá conter, para cada um dos algoritmos acima:

# Links Úteis
Aula sobre MPI (AVA)
* https://eadfriburgo.cefet-rj.br/pluginfile.php/6048/mod_resource/content/2/PPC-MPI.pdf