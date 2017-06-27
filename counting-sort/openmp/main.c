#include "parallelCountingSort.h"
#include "serialCountingSort.h"
#include "populateArray.h"

#define ARRAY_SIZE 1000


int main(){
	printf("\nArray size: %d\n\n", ARRAY_SIZE);
	int array [ARRAY_SIZE];
	int i = 0;

	clock_t start, end, duration;

	/* Inicializa um array com números aleatórios */
	populateArray(array, ARRAY_SIZE);

	/* Imprime o array */
	//printArray(array, ARRAY_SIZE);

	/* Armazena o tempo atual do início da execução do algoritmo serial */
	start = clock();

	/* Execução da forma SERIAL do algoritmo COUNTING SORT */
	serialCountingSort(array, ARRAY_SIZE);
	end = clock();
	double time = (float)(end - start) / CLOCKS_PER_SEC;

	
	printf("\nSerial: %f\n", time);

	/* Imprime o array para verificar se está realmente ordenado */
	//printArray(array, ARRAY_SIZE);


	/* Inicializa um novo array com números aleatórios */
	populateArray(array, ARRAY_SIZE);



	/* Armazena o tempo atual do início da execução do algoritmo paralelo */
	start = clock();

	/* Execução da forma PARALELA do algoritmo COUNTING SORT */
	parallelCountingSort(array, ARRAY_SIZE);
	end = clock();
	time = (float)(end - start) / CLOCKS_PER_SEC;


	printf("\nParallel: %f\n\n", time);

	/* Imprime o array para verificar se está de fato ordenado */
	//printArray(array, ARRAY_SIZE);

	return 0;
}
