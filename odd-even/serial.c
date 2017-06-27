#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils.h"
#define ARRAYSIZE 10000

void oddEvenSerial(int vetor[], int tamanho);

int main(){
  int a[ARRAYSIZE];
  int i, numbers_to_show = 100;

  populate_array(a, ARRAYSIZE);

  //armazena o tempo em que o processamento foi iniciado
  clock_t begin = clock();

  //ordena o array
  oddEvenSerial(a, ARRAYSIZE);

  //exibe o array ordenado
  printf("Ordenado por ordem crescente (exibindo os %d primeiros numeros)\n", numbers_to_show);
  for (i = 0; i < numbers_to_show; i++)
    printf("%d - ", a[i]);
  if (i == numbers_to_show)
    printf("%d\n", a[i]);

  //calcula o tempo de execução
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%f segundos", time_spent);

  return 0;

}

void oddEvenSerial(int vetor[], int tamanho) {
  int temp;

  for(int i = 0; i < tamanho; i++ ) {
    if (i % 2 == 0) {
      for (int j = 0; j < tamanho; j = j + 2) {
        if( vetor[j] > vetor[j + 1] ) {
          temp = vetor[j];
          vetor[j] = vetor[j + 1];
          vetor[j + 1] = temp;
        }
      }
    } else {
      for (int j = 1; j < tamanho - 1; j = j + 2) {
        if( vetor[j] > vetor[j + 1] ) {
          temp = vetor[j];
          vetor[j] = vetor[j + 1];
          vetor[j + 1] = temp;
        }
      }
    }
  }
}
