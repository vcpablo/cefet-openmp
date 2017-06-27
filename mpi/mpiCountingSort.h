#include <mpi.h>
#include <time.h>

#include "populateArray.h"
#include "printArray.h"
#include "position.h"

void mpiCountingSort(int my_rank, int comm_sz, int size, MPI_Comm group){
    int i, j, counter, innerCounter, localSize, dataSize;
    int array[size];
    position localArray[size/comm_sz], positions[size];

    if(my_rank == 0){
        populateArray(array, size);
        printf("Pre Counting Sort:\n");
	printArray(array, size);
    }

    /* Makes the array to be ordered available */
    MPI_Bcast(array, size, MPI_INT, 0, group);

    localSize = size / comm_sz;

    /* Iterates through the positions of the array of each process */
    for(i = localSize * my_rank, innerCounter = 0; i < localSize * (my_rank+1); i++){
        counter = 0;
        /* Inner loop, responsivle to order the array peace of the current process */
        for(j = 0; j < size; j++){
            if((array[j] < array[i]) || (array[j] == array[i]) && (j < i)){
                counter++;
            }
        }
        localArray[innerCounter].pos = counter;
        localArray[innerCounter].val = array[i];
        innerCounter++;
    }

    dataSize = localSize * sizeof(position);
    /* Gather the local arrays of each process in position variable */
    MPI_Gather(localArray, dataSize, MPI_BYTE, positions, dataSize, MPI_BYTE, 0, group);

    if(my_rank == 0){
        /* Order the array with the new positions */
        for(i = 0; i < size; i++){
            array[positions[i].pos] = positions[i].val;
        }
        printf("\n\n");
        printf("After Counting Sort:\n");
        printArray(array, size);
    }


}
