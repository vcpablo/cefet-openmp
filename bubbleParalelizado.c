/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
#define SIZE 100000
void bubble_sort(long array[], long n){
        long c,d,t;

        omp_set_num_threads(4);
        #pragma omp parallel for private(d) private(t)
        for(c=0;c<(n-1); c++){

            for(d=0;d<n-1;d++){

                if(array[d]>array[d+1]){
                    t = array[d];
                    array[d] = array[d+1];
                    array[d+1] = t;
                }
            }
        }
    }
int main(){
    long array[SIZE],c;
        srand(time(NULL));
    printf("Preenchendo o vetor com valores\n");

    for (c = 0;c<SIZE;c++){
        array[c] = rand()%1000;

    }
    bubble_sort(array,SIZE);

    printf("Ordenado por ordem ascendente\n");
     for ( c = 0 ; c < SIZE ; c++ )
     printf(" posicao %ld : %ld\n",c,array[c]);
    return 0;

}

*/
