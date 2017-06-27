#include <stdio.h>
#include <time.h>
#include "../../utils.h"
#define ARRAYSIZE 20000

void serialCountingSort(int * array, int arraySize);

int main()
{
  int a[ARRAYSIZE];
  int i, key = 86;

  populate_array(a, ARRAYSIZE);

  //armazena o tempo em que o processamento foi iniciado
  clock_t begin = clock();

  serialCountingSort(a, ARRAYSIZE);

  //calcula o tempo de execução
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Serial: %f segundos\n\n", time_spent);

  return 0;
}

void serialCountingSort(int * array, int arraySize) {
	int i, j, count;
	int temp[arraySize];

	for(i = 0; i < arraySize; i++){
		count = 0;

		for(j = 0; j < arraySize; j++){
  		if(array[j] < array[i] || ( array[j] == array[i] && j < i ) ){
			  count++;
      }
		}

		temp[count] = array[i];
	}

	for (i = 0; i < arraySize; i++){
		array[i] = temp[i];
	}
}
