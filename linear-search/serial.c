#include <stdio.h>

int main()
{
   int array[100], search, c, n;

   printf("Numero de elementos no array:\n");
   scanf("%d",&n);

   printf("Digite %d inteiro(s)\n", n);

   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);

   printf("Numero a ser procurado:\n");
   scanf("%d", &search);

   for (c = 0; c < n; c++)
   {
      if (array[c] == search)     /* if required element found */
      {
         printf("%d esta presente na posicao %d.\n", search, c+1);
         break;
      }
   }
   if (c == n)
      printf("%d nao está presente no array.\n", search);

   return 0;
}
