#include <stdio.h>
#include <time.h>
#include "../utils.h"
#define ARRAYSIZE 1000000

void shellsort( int *vet, int size ) {
    int i, j, value;
    int gap = 1;
    
    while( gap < size ) {
        gap = 3 * gap + 1;
    }

    while ( gap > 1 ) {
        gap /= 3;

        #pragma omp parallel for private(i,j)
        for( i = gap; i < size; i++ ) {
            value = vet[i];
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