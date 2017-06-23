#include <stdio.h>
#include <stdlib.h>

/* Populates an array with integers */

void populateArray(int array[], int arraySize){
	int i = 0;

	for(i = 0; i < arraySize; i++){
array[i] = arraySize - i;
		/* If the division per 2 is zero */
/*		if(i % 2 == 0){
			array[i] = i * 2;
		} 

		/* If the division per 2 is NOT zero */
/*		else {
			array[i] = i;
		}*/
	}
}
