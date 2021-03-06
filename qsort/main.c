#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"
#define ARRAYSIZE 20000

int compare(const void * x, const void * y)
{
	if(*(int*)x < *(int*)y)
		return -1;
	else if(*(int*)x > *(int*)y)
		return 1;
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

	qsort(v, 5, sizeof(int), compare);

  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("qSort: %f segundos\n\n", time_spent);

	return 0;
}
