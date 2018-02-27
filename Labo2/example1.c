#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
   // Bad example
   int x[5000][100];
   for (int j=0; j<100; j++)
   {
      for (int i=0; i<5000; i++)
      	x[i][j] = x[i][j] * 2;
   }

   printf("%p\n", &x[0][0]);
   printf("%p\n", &x[0][1]);
   printf("%p\n", &x[1][0]);

   // Good example
   int y[5000][100];
   for (int i=0; i<5000; i++)
   {
      for (int j=0; j<100; j++)
      	y[i][j] = y[i][j] * 2;
   }

   printf("%p\n", &y[0][0]);
   printf("%p\n", &y[0][1]);
   printf("%p\n", &y[1][0]);
}




