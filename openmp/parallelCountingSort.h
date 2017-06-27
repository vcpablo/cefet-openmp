#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

void parallelCountingSort(int array[], int arraySize){
	
	int i, j, count;
	int temp[arraySize];

	/* 
		Distribui o array entre as threads disponíveis a partir da utilização do #pragma parallel for
		
		Variáveis compartilhadas: array, arraySize, temp
		Variáveis privadas: i, j, count
	*/
	

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
		Execução paralelizada da cópia do conteúdo do array temporário para o array passado por referência
	*/

	#pragma omp parallel for shared(array, arraySize, temp) private(i)
	for (i = 0; i < arraySize; i++){
		array[i] = temp[i];
	}
}

