#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "../utils.h"
#define ARRAYSIZE 10000

void bubble_sort(int array[], int n);

int main(){
  int a[ARRAYSIZE];
  int c, d, swap, numbers_to_show = 100;
  double start_time, run_time;

  populate_array(a, ARRAYSIZE);

  //armazena o tempo em que o processamento foi iniciado
  start_time = omp_get_wtime();

  //ordena o array
  bubble_sort(a, ARRAYSIZE);

  //exibe o array ordenado
  printf("Ordenado por ordem crescente (exibindo os %d primeiros numeros)\n", numbers_to_show);
  for (c = 0; c < numbers_to_show; c++)
    printf("%d - ", a[c]);
  if (c == numbers_to_show)
    printf("%d\n", a[c]);

    //calcula o tempo de execução
    run_time = omp_get_wtime() - start_time;
    printf("%f segundos", run_time);

  return 0;
}

void bubble_sort(int array[], int n){
  int c,d,t;

  #pragma omp parallel for private(d) private(t)
  for(c = 0; c < (n - 1); c++){
    for(d = 0; d < n - c - 1; d++){
      if(array[d] > array[d + 1]){
        t = array[d];
        array[d] = array[d + 1];
        array[d + 1] = t;
      }
    }
  }
}
