#include <stdio.h>
#include <omp.h>
#include "../utils.h"
#define ARRAYSIZE 10000

void parallelCountingSort(int array[], int arraySize);

int main(void)
{
  int a[ARRAYSIZE];
  int i, threads, found = 0, key;
  double start_time, run_time;

  populate_array(a, ARRAYSIZE);

  //armazena o tempo em que o processamento foi iniciado
  start_time = omp_get_wtime();

  parallelCountingSort(a, ARRAYSIZE);

  //calcula o tempo de execução
  run_time = omp_get_wtime() - start_time;
  printf("%f segundos com %d threads", run_time, threads);

  return 0;
}

void parallelCountingSort(int array[], int arraySize){

	int i, j, count;
	int temp[arraySize];

	/* Splits the main array through the threads */
	#pragma omp parallel for shared(array, arraySize, temp) private(i, j, count)
	for(i = 0; i < arraySize; i++){
		count = 0;

		for(j = 0; j < arraySize; j++){
  		if(array[j] < array[i] || ( array[j] == array[i] && j < i ) ){
				count++;
		  }
		}

		temp[count] = array[i];
	}

	/*
		Parallelized execution to copy from temp (temp) to main array (array)
		using array, arraySize and temp as shared vars and i as private var.
	*/

	#pragma omp parallel for shared(array, arraySize, temp) private(i)
	for (i = 0; i < arraySize; i++){
		array[i] = temp[i];
	}
}
