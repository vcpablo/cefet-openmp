#include <stdio.h>
#include <stdlib.h>

/* Popula um array com números inteiros */

void populateArray(int array[], int arraySize){
	int i = 0;

	for(i = 0; i < arraySize; i++){
		array[i] = arraySize - i;
		/* Se a divisão por 2 for zero */
		/*if(i % 2 == 0){
			array[i] = i * 2;
		}*/ 

		/* Se o resto da divisão NÃO for zero */
		/*else {
			array[i] = i;
		}*/
	}
}
