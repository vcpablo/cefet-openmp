#include <stdio.h>
#include <omp.h>
#include "../../utils.h"
#define ARRAYSIZE 20000

int parallelCountingSort(int array[], int arraySize);

int main(void)
{
  int a[ARRAYSIZE];
  int i, found = 0, key, threads;
  double start_time, run_time;


  populate_array(a, ARRAYSIZE);

  //armazena o tempo em que o processamento foi iniciado
  start_time = omp_get_wtime();

  threads = parallelCountingSort(a, ARRAYSIZE);

  //calcula o tempo de execução
  run_time = omp_get_wtime() - start_time;
  printf("Paralelo (OpenMp): %f segundos com %d threads\n\n", run_time, threads);

  return 0;
}

int parallelCountingSort(int array[], int arraySize){

	int i, j, count, threads;
	int temp[arraySize];

	/* Splits the main array through the threads */
	#pragma omp parallel for shared(array, arraySize, temp) private(i, j, count)

	for(i = 0; i < arraySize; i++){
		threads = omp_get_num_threads();
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

	return threads;
}
