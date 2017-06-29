#include <stdio.h>
#include <time.h>
#include "../utils.h"
#define ARRAYSIZE 100

// O shellsort é um algoritmo de ordenação que percorre cada campo do vetor, comparando o atual
// com o próximo, usando o gap como distância entre eles
// Por exemplo: gap = 20, compara v[0] com v[20], v[1], com v[21], v[2] com v[22]
// Na próxima divisão (Usando 2 como exemplo), gap = 10, v[0] com v[10], v[1] com v[11], ..., v[11] com v[21]

void shellsort( int *vet, int size ) {
    int i, j, value;
    int gap = 1;
    
    // Criando o gap para divisão e comparação do sort
    while( gap < size ) {
        // Cada incremento não pode ser múltiplo do anterior (essa fórmula é a de melhor performance)
        gap = 3 * gap + 1;
    }
    
    // As iteração acontecem enquanto o gap for maior ou igual a 1
    // A atribuição gap/=3 é a mesma coisa que gap = ( gap / 3 ) + 1
    while ( gap > 1 ) {
        // No inicio de cada iteração o valor do gap é dividido por 3 para fazer iteração entre mais campos do vetor
        gap /= 3;

        // I inicia a partir do gap
        for( i = gap; i < size; i++ ) {
            value = vet[ i ];
            // Determinando o valor do j
            j = i - gap;

            // Percorrendo o resto do array comparando o i atual com o próximo elemento
            // A distância entre eles é determinada pelo gap
            while ( j >= 0 && value < vet[ j ] ) {
                // Reposicionando o elemento
                vet [ j + gap ] = vet[ j ];
                // J recebe um novo valor para ser usado no while
                j -= gap;
            }


            vet [ j + gap ] = value;
        }
    }
}

int main( void ) {

  int i, vet[ ARRAYSIZE ];

  populate_array( vet, ARRAYSIZE );

  //armazena o tempo em que o processamento foi iniciado
  clock_t begin = clock();
 
  // Ordena os valores
  shellsort( vet, ARRAYSIZE );

  // Calcula o tempo de execução
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%f segundos\n", time_spent);

  return 0;
}