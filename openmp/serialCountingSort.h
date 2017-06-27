#include <stdio.h>
#include <stdlib.h>

/* Imprime um array */
void printArray(int * array, int size){

  int curr;
  for(curr = 0; curr < size; curr++){
    printf("| %d, ", array[curr]);
  }
  printf(" | \n");
}

/* Returns the maximum value in an array */ 
int maximum(int * array, int size){

  int curr = 0;
  int max = 0;

  for(curr = 0; curr < size; curr++){
    if(array[curr] > max){ max = array[curr]; }
  }

  return max;
}

/* Implementação Serial #1 do algoritmo COUNTING SORT  */
void serialCountingSort1(int * array, int size){

	int curr = 0;
	int max = maximum(array, size);

	/* Inicializa um arrau de zeros */
	int * counting_array = calloc(max, sizeof(int));

	/* Itera sobre o array principal e adiciona a contagem do valor ao seu respectivo index no aray auxiliar */
	for(curr = 0; curr < size; curr ++){
		counting_array[array[curr]]++;
	}

	int num = 0;
	curr = 0;
	/* Sobrescreve o array principal com os valores ordenados */
	while(curr <= size){
		while(counting_array[num] > 0){
			array[curr] = num;
			counting_array[num]--;
			curr++;

			if(curr > size){ break; }
		}
		num++;
	}
}

/* Implementação serial #2 do algoritmo COUNTING SORT */
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


