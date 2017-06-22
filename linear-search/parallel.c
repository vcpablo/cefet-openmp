#include <stdio.h>
#include <omp.h>
#include "../utils.h"
#define ARRAYSIZE 1000000

int main(void)
{
  int a[ARRAYSIZE];
  int i, j, found = 0, key = 86;
  double start_time, run_time;

  populate_array(a, ARRAYSIZE);

  //armazena o tempo em que o processamento foi iniciado
  start_time = omp_get_wtime();

  //o código dentro do bloco do pragma será paralelizado
  //cada thread terá uma cópia da variável "i"
  #pragma omp parallel private(i)
  {
    int start, noofsteps;

    if(found == 0)
    {
      j = omp_get_num_threads();

      //posição onde a busca será iniciada
      start = (omp_get_thread_num()) * (ARRAYSIZE / j);

      //número de verificações a serem feitas nessa thread
      noofsteps = start + (ARRAYSIZE / j);

      if(ARRAYSIZE % j != 0)
        noofsteps += (ARRAYSIZE % j);

      //faz a iteração, procurando o elemento
      for(i = start; i < noofsteps; i++){
        if(key == a[i]) {
          printf("elemento encontrado na thread %d na posicao %d\n", omp_get_thread_num(), i + 1);
          found = 1;
          break;
        }
      }
    }
  }

  //calcula o tempo de execução
  run_time = omp_get_wtime() - start_time;
  printf("%f segundos com %d threads", run_time, j);

  return 0;
}
