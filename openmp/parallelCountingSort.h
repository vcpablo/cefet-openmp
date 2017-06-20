#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

void parallelCountingSort(int array[], int arraySize){
	
	int i, j, count;
	int *temp = malloc(arraySize*sizeof(int));

	/* Splits the main array through the threads */

	#pragma omp parallel for shared(array, arraySize, temp) private(i, j, count)
	for(i = 0; i < arraySize; i++){
		count = 0;
		
		for(j = 0; j < arraySize; j++){
	    		if(array[j] < array[i]){
				count++;
		    	} else if(array[j] == array[i] && j < i){
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

	free(temp);
}

