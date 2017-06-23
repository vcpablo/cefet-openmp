#include "parallelCountingSort.h"
#include "serialCountingSort.h"
#include "populateArray.h"

#define ARRAY_SIZE 1000

/* 
sempre utilizar a mesma implementação do algoritmo
o algoritmo para ser paralelizado deve ser implementado em sua forma canonica (sem alteração da forma como é executado dentro do loop)

se o for for criado (i = 0; i < tam ; i++), deve seguir exatamente esta maneira de ser executado

/*************/
/*

RODAR COM 4 e 2 threads

speedup - (Ts) tempo serial /(Tp) tempo paralelo


Eficiência

E = S/p (S = speedup, p = num proc/threads), valores entre 0 e 1 /  o valor ideal é 1

Escalabilidade

capacidade de manter a eficiencia conforme quantidade de trabalho e quantidade de threads aumenta

o programa passa a apresentar perda de escalabilidade a partir do momento em que o aumento de trabalho + aumento de threads gera perda de eficiencia.
*/
*/


int main(){
	printf("\nArray size: %d\n\n", ARRAY_SIZE);
	int array [ARRAY_SIZE];
	int i = 0;

	clock_t start, end, duration;

	/* Populates the array */
	populateArray(array, ARRAY_SIZE);

	/* Prints the array */
//	printArray(array, ARRAY_SIZE);

	/* Timer */
	start = clock();

	/* Serial counting sort execution */
	serialCountingSort(array, ARRAY_SIZE);
	end = clock();
	double time = (float)(end - start) / CLOCKS_PER_SEC;


	printf("\nSerial: %f\n", time);

	/* Checks if elements were really ordered */
	//printArray(array, ARRAY_SIZE);


	/* Populates the array */
	populateArray(array, ARRAY_SIZE);



	/* Timer */
	start = clock();

	/* Parallel counting sort execution */
printf("\n\nStart parallel\n\n");
	parallelCountingSort(array, ARRAY_SIZE);
	end = clock();
	time = (float)(end - start) / CLOCKS_PER_SEC;


	printf("\nParallel: %f\n\n", time);

	/* Prints the array */
	//printArray(array, ARRAY_SIZE);

	/* Checks if elements were really ordered */
	//printArray(array, ARRAY_SIZE);

	return 0;
}
