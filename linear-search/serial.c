#include <stdio.h>
#include <time.h>
#include "utils.h"
#define ARRAYSIZE 1000000

int main()
{
  int a[ARRAYSIZE];
  int i, key = 86;

  populate_array(a, ARRAYSIZE);

  //armazena o tempo em que o processamento foi iniciado
  clock_t begin = clock();

  for (i = 0; i < ARRAYSIZE; i++)
  {
    if (a[i] == key)
    {
      printf("%d esta presente na posicao %d.\n", key, i+1);
      break;
    }
  }

  if (i == ARRAYSIZE){
    printf("%d nao está presente no array.\n", key);
  }

  //calcula o tempo de execução
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%f segundos", time_spent);

  return 0;
}
