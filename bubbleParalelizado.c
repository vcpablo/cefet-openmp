#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

#define SIZE 10

void bubble_sort(long array[], long n){
        long c,d,t;

        omp_set_num_threads(4);
        #ifdef _OPENMP
           // printf("ok ok   aiaiaiaiaia");
        #endif // _OPENMP
        #pragma omp parallel for private(d) private(t)
        for(c=0;c<(n-1); c++){
                printf("thread numero %d\n", omp_get_num_threads());
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
   // printf("Informe a quantidade de elementos:\n ");
    //scanf("%ld", &n);

        srand(time(NULL));
    printf("Preenchendo o vetor com valores\n");
    for (c = 0;c<SIZE;c++){
        array[c] = rand()%100000;
      //  printf(" posicao %ld : %ld\n",c,array[c]);
    }

    bubble_sort(array,SIZE);

    printf("Ordenado por ordem ascendente\n");
     for ( c = 0 ; c < SIZE ; c++ )
     printf(" posicao %ld : %ld\n",c,array[c]);

    return 0;

}


