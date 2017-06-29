#include <stdio.h>
#include <omp.h>
#include "../utils.h"
#define ARRAYSIZE 100000

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
  double start_time, run_time;

  populate_array( vet, ARRAYSIZE );

  //armazena o tempo em que o processamento foi iniciado
  start_time = omp_get_wtime();

  // Ordena os valores
  shellsort( vet, ARRAYSIZE );

  // Calcula o tempo de execução
  run_time = omp_get_wtime() - start_time;
  printf("%f segundos", run_time);

  return 0;
}
