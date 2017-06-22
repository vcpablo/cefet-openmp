#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, size_t n)
{
  if (n > 1)
  {
    size_t i;
    srand(time(NULL));
    for (i = 0; i < n - 1; i++)
    {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      int t = arr[j];
      arr[j] = arr[i];
      arr[i] = t;
    }
  }
}

void populate_array(int *arr, int size)
{
  int i;

  for (i = 0; i < size; i++){
    arr[i] = i + 1;
  }

  shuffle(arr, size);
}
