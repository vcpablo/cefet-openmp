#include<stdio.h>
#include<omp.h>
#define ARRAYSIZE 100

int main(void)
{
  int a[] = {81,84,38,9,71,78,49,58,25,8,69,57,36,23,89,62,47,64,77,94,66,12,2,32,26,51,48,55,37,91,13,3,41,97,90,4,59,54,87,35100,74,19,16,33,18,67,20,30,6,93,10,86,14,43,83,79,27,73,21,28,92,98,60,61,46,31,63,53,85,50,80,24,70,72,42,76,68,65,45,95,88,7,1,5,82,96,15,40,29,22,75,39,99,34,11,17,56,52,44};

  int i, j, found = 0, key = 86;
  double start_time, run_time;

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
  printf("%f segundos com %d threads\n\n", run_time, j);

  return 0;
}
