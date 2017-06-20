#include <stdio.h>
#include <stdlib.h>

/* Prints an array */
void printArray(int * array, int size){

  int curr;
  for(curr = 0; curr < size; curr++){
    printf("%d, ", array[curr]);
  }
  printf("\n");
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

/* Serial counting sort implementation */
void serialCountingSort(int * array, int size){

	int curr = 0;
	int max = maximum(array, size);

	/* Initialize an array with zeros */
	int * counting_array = calloc(max, sizeof(int));

	/* Iterate over the input array, and add count to the appropriate index */
	for(curr = 0; curr < size; curr ++){
		counting_array[array[curr]]++;
	}

	int num = 0;
	curr = 0;
	/* Override the input array to create the sorted list */
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


