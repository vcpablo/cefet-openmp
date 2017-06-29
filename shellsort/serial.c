#include <stdio.h>
#include <time.h>
#include "../utils.h"
#define ARRAYSIZE 100

void shellsort( int *vet, int size ) {
    int i, j, value;
    int gap = 1;
    
    // Criando o gap para divisão e comparação do sort
    while( gap < size ) {
        // Cada incremento não pode ser múltiplo do anterior, essa fórmula é a de melhor performance
        gap = 3 * gap + 1;
    }
    
    while ( gap > 1 ) {
        // Antes de iniciar a iteração o gap é dividido, para poder comparar objetos mais próximos de acordo com as iterações
        gap /= 3;

        // I inicia a partir do gap
        for( i = gap; i < size; i++ ) {
            value = vet[ i ];
            j = i - gap;

            while ( j >= 0 && value < vet[ j ] ) {
                vet [ j + gap ] = vet[ j ];
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