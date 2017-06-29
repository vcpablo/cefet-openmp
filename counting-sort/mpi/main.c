#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#include "mpiCountingSort.h"

#define ARRAY_SIZE 20000

int main(void){
    int my_rank, comm_sz;
    clock_t begin, end;
double time_spent;


    MPI_Init(NULL,NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	begin = clock();
    mpiCountingSort(my_rank, comm_sz, ARRAY_SIZE, MPI_COMM_WORLD);

    MPI_Finalize();

end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	
	printf("CountiMPI: %f segundos\n\n", time_spent);

 	return 0;
}
