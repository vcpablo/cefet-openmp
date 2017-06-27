#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"
#define ARRAYSIZE 10000

int comp1(const void * x, const void * y)
{
	if(*(int*)x < *(int*)y)
		return -1;
	else if(*(int*)x > *(int*)y)
		return 1;
	else
		return 0;
}

int comp2(const void * x, const void * y)
{
	if(*(int*)x < *(int*)y)
		return 1;
	else if(*(int*)x > *(int*)y)
		return -1;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	int v[ARRAYSIZE];
	double time_spent;
	clock_t begin, end;

	populate_array(v, ARRAYSIZE);

	begin = clock();

	qsort(v, 5, sizeof(int), comp1);

        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	
	printf("qSort: Ordem crescente: %f segundos\n\n", time_spent);
	for(int i = 0; i < 5; i++) {
		printf("%d ", v[i]);

        }

	begin = clock();
	
	qsort(v, 5, sizeof(int), comp2);

	end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\n\nOrdem decrescente:  %f segundos\n\n", time_spent);
	for(int i = 0; i < 5; i++) {
		printf("%d ", v[i]);
        }
	
	printf("\n");
	return 0;
}
