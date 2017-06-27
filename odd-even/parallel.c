#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "../utils.h"
#define ARRAYSIZE 10000

void oddEvenParalelo(int vetor[], int tamanho);

int main(){
  int a[ARRAYSIZE];
  int i, numbers_to_show = 100;
  double start_time, run_time;

  populate_array(a, ARRAYSIZE);

  //armazena o tempo em que o processamento foi iniciado
  start_time = omp_get_wtime();

  //ordena o array
  oddEvenParalelo(a, ARRAYSIZE);

  //exibe o array ordenado
  printf("Ordenado por ordem crescente (exibindo os %d primeiros numeros)\n", numbers_to_show);
  for (i = 0; i < numbers_to_show; i++)
    printf("%d - ", a[i]);
  if (i == numbers_to_show)
    printf("%d\n", a[i]);

  //calcula o tempo de execução
  run_time = omp_get_wtime() - start_time;
  printf("%f segundos", run_time);

  return 0;
}

void oddEvenParalelo(int vetor[], int tamanho) {
  int i, j, temp;
  #pragma omp parallel default(none) shared(vetor, tamanho) private(i, j, temp)
  for(i = 0; i < tamanho; i++ )
  {
    if (i % 2 == 0){
      #pragma omp for
      for (j = 0; j < tamanho; j = j + 2) {
        if( vetor[j] > vetor[j + 1] ) {
          temp = vetor[j];
          vetor[j] = vetor[j + 1];
          vetor[j + 1] = temp;
        }
      }
    } else {
      #pragma omp for
      for (j = 1; j < tamanho -1; j = j + 2) {
        if( vetor[j] > vetor[j + 1] ) {
          temp = vetor[j];
          vetor[j] = vetor[j + 1];
          vetor[j + 1] = temp;
        }
      }
    }
  }
}
