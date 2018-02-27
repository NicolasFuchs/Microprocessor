#include <unistd.h>
#include <stdio.h>
#include <time.h>

static double diff(struct timespec start, struct timespec end);

int main()
{
   int nb_loop = 1000;
   struct timespec tStart, tEnd;

   // Bad example
   clock_gettime(CLOCK_REALTIME, &tStart);
   int x[5000][100];

   for (int n = 0; n < nb_loop; ++n)
   {
      for (int j=0; j<100; j++)
      {
         for (int i=0; i<5000; i++)
         {
            x[i][j] = x[i][j] *2;
         }
      }
   }

   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("nb secondes :\t%f\n", diff(tStart, tEnd));

   // Good example
   clock_gettime(CLOCK_REALTIME, &tStart);

   int y[5000][100];
   for (int n = 0; n < nb_loop; ++n)
   {
      for (int i=0; i<5000; i++)
      {
         for (int j=0; j<100; j++)
         {
            y[i][j] = y[i][j] *2;
         }
      }
   }

   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("nb secondes :\t%f\n", diff(tStart, tEnd));

   printf("%p\n", &y[0][0]);
   printf("%p\n", &y[0][1]);
   printf("%p\n", &y[1][0]);

   return (0);
}

double diff(struct timespec start, struct timespec end)
{
	double t1, t2;
	t1 = (double)start.tv_sec;
	t1 = t1 + ((double)start.tv_nsec)/1000000000.0;
	t2 = (double)end.tv_sec;
	t2 = t2 + ((double)end.tv_nsec)/1000000000.0;
	return (t2-t1);
}
