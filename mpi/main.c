#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#include "mpiCountingSort.h"

#define ARRAY_SIZE 100

int main(void){
    int my_rank, comm_sz;

    MPI_Init(NULL,NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    mpiCountingSort(my_rank, comm_sz, ARRAY_SIZE, MPI_COMM_WORLD);

    MPI_Finalize();

 	return 0;
}
