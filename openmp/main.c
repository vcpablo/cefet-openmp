#include "parallelCountingSort.h"
#include "serialCountingSort.h"
#include "populateArray.h"

#define ARRAY_SIZE 100

int main(){
	printf("\nArray size: %d\n\n", ARRAY_SIZE);
	int array [ARRAY_SIZE];
	int i = 0;

	clock_t start, end, duration;

	/* Populates the array */
	populateArray(array, ARRAY_SIZE);

	/* Timer */
	start = clock();

	/* Serial counting sort execution */
	serialCountingSort(array, ARRAY_SIZE);
	end = clock();
	double time = (float)(end - start) / CLOCKS_PER_SEC;


	printf("Serial: %f", time);

	/* Checks if elements were really ordered */
	//printArray(array, ARRAY_SIZE);


	/* Populates the array */
	populateArray(array, ARRAY_SIZE);

	/* Timer */
	start = clock();

	/* Parallel counting sort execution */
	parallelCountingSort(array, ARRAY_SIZE);
	end = clock();
	time = (float)(end - start) / CLOCKS_PER_SEC;


	printf("\nParallel: %f\n\n", time);

	/* Checks if elements were really ordered */
	//printArray(array, ARRAY_SIZE);

	return 0;
}
