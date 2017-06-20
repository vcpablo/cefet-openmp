#include <stdio.h>
#define ARRAYSIZE 100

int main()
{
  int a[] = {81,84,38,9,71,78,49,58,25,8,69,57,36,23,89,62,47,64,77,94,66,12,2,32,26,51,48,55,37,91,13,3,41,97,90,4,59,54,87,35100,74,19,16,33,18,67,20,30,6,93,10,86,14,43,83,79,27,73,21,28,92,98,60,61,46,31,63,53,85,50,80,24,70,72,42,76,68,65,45,95,88,7,1,5,82,96,15,40,29,22,75,39,99,34,11,17,56,52,44};
  int i, key = 86;

  for (i = 0; i < ARRAYSIZE; i++)
  {
    if (a[i] == key)
    {
      printf("%d esta presente na posicao %d.\n", key, i+1);
      break;
    }
  }
  if (i == ARRAYSIZE)
    printf("%d nao está presente no array.\n", key);

  return 0;
}
