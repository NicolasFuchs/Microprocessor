#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct _TEST1{
	int a;
	char b;
	int c;
	char d;
} TEST1;

typedef struct _TEST2{
	int a;
	int c;
	char b;
	char d;
} TEST2;

typedef struct _TEST3{
	int a;
	char b __attribute__ ((aligned (4)));
	int c;
	char d __attribute__ ((aligned (4)));
} TEST3;

typedef struct _TEST4{
	int a;
	char b;
	int c __attribute__ ((packed));
	char d;
} TEST4;

typedef struct _TEST5{
	char b;
	char d;
	int a __attribute__ ((packed));
	int c __attribute__ ((packed));
} TEST5;

typedef struct __BUFF3{
	TEST3 buff[100];
} BUFF3;

typedef struct __BUFF5{
	TEST5 buff[100];
} BUFF5;

static int nb_loop = 1000000;
static double diff(struct timespec start, struct timespec end);
static TEST1 test1[1000];
static TEST2 test2[1000];
static TEST3 test3[1000];
static TEST4 test4[1000];
static TEST5 test5[1000];
static BUFF3 buff3;
static BUFF5 buff5;

int main()
{
   struct timespec tStart, tEnd;

   // Test1
   clock_gettime(CLOCK_REALTIME, &tStart);
   for (int n = 0; n < nb_loop; ++n)
   {
	   for (int i=0 ; i<100 ; i++)
	   {
		   test1[i].a = 1;
		   test1[i].b = 2;
		   test1[i].c = 3;
		   test1[i].d = 4;
	   }
   }
   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("Test1:\n");
   printf ("  struct size = %li",sizeof(test1[0]));
   printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));

   // Test2
   clock_gettime(CLOCK_REALTIME, &tStart);
   for (int n = 0; n < nb_loop; ++n)
   {
	   for (int i=0 ; i<100 ; i++)
	   {
		   test2[i].a = 1;
		   test2[i].b = 2;
		   test2[i].c = 3;
		   test2[i].d = 4;
	   }
   }
   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("Test2:\n");
   printf ("  struct size = %li", sizeof(test2[0]));
   printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));

   // Test3
   clock_gettime(CLOCK_REALTIME, &tStart);
   for (int n = 0; n < nb_loop; ++n)
   {
	   for (int i=0 ; i<100 ; i++)
	   {
		   test3[i].a = 1;
		   test3[i].b = 2;
		   test3[i].c = 3;
		   test3[i].d = 4;
	   }
   }
   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("Test3:\n");
   printf ("  struct size = %li", sizeof(test3[0]));
   printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));

   // Test4
   clock_gettime(CLOCK_REALTIME, &tStart);
   for (int n = 0; n < nb_loop; ++n)
   {
	   for (int i=0 ; i<100 ; i++)
	   {
		   test4[i].a = 1;
		   test4[i].b = 2;
		   test4[i].c = 3;
		   test4[i].d = 4;
	   }
   }
   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("Test4:\n");
   printf ("  struct size = %li", sizeof(test4[0]));
   printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));

   // Test5
   clock_gettime(CLOCK_REALTIME, &tStart);
   for (int n = 0; n < nb_loop; ++n)
   {
	   for (int i=0 ; i<100 ; i++)
	   {
		   test5[i].a = 1;
		   test5[i].b = 2;
		   test5[i].c = 3;
		   test5[i].d = 4;
	   }
   }
   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("Test5:\n");
   printf ("  struct size = %li", sizeof(test5[0]));
   printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));

   // Test6
   clock_gettime(CLOCK_REALTIME, &tStart);
   memcpy(&buff3, test3, 100 * sizeof(test3[0]));
   for (int n = 0; n < nb_loop; ++n)
   {
	   for (int i=0 ; i<100 ; i++)
	   {
		   buff3.buff[i].a = 1;
		   buff3.buff[i].b = 2;
		   buff3.buff[i].c = 3;
		   buff3.buff[i].d = 4;
	   }
   }
   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("Test6:\n");
   printf ("  struct size = %li", sizeof(test3[0]));
   printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));

   // Test7
   clock_gettime(CLOCK_REALTIME, &tStart);
   memcpy(&buff3, test3, 100 * sizeof(test3[0]));
   int *t;
   for (int n = 0; n < nb_loop; ++n)
   {
	   t = &(buff3.buff[0].a);
	   for (int i=0 ; i<100 ; i+=4)
	   {
		   *(t) = 1;
		   *(t+1) = 2;
		   *(t+2) = 3;
		   *(t+3) = 4;
		   *(t+4) = 1;
		   *(t+5) = 2;
		   *(t+6) = 3;
		   *(t+7) = 4;
		   *(t+8) = 1;
		   *(t+9) = 2;
		   *(t+10) = 3;
		   *(t+11) = 4;
		   *(t+12) = 1;
		   *(t+13) = 2;
		   *(t+14) = 3;
		   *(t+15) = 4;
		   t += 16;
	   }
   }
   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("Test7:\n");
   printf ("  struct size = %li", sizeof(test3[0]));
   printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));

   // Test8
   clock_gettime(CLOCK_REALTIME, &tStart);
   memcpy(&buff3, test3, 100 * sizeof(test3[0]));
   TEST3 t1;
   t1.a = 1;
   t1.b = 2;
   t1.c = 3;
   t1.d = 4;
   for (int n = 0; n < nb_loop; ++n)
   {
	   for (int i=0 ; i<100 ; i+=4)
	   {
		   memcpy(&buff3.buff[i],&t1,16);
	   }
   }
   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("Test8:\n");
   printf ("  struct size = %li", sizeof(test3[0]));
   printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));

   // Test9
   clock_gettime(CLOCK_REALTIME, &tStart);
   memcpy(&buff5, test5, 100 * sizeof(test5[0]));
   TEST5 t9;
   t9.a = 1;
   t9.b = 2;
   t9.c = 3;
   t9.d = 4;
   for (int n = 0; n < nb_loop; ++n)
   {
	   for (int i=0 ; i<100 ; i+=4)
	   {
		   memcpy(&buff5.buff[i],&t9,10);
	   }
   }
   clock_gettime(CLOCK_REALTIME, &tEnd);
   printf ("Test9:\n");
   printf ("  struct size = %li", sizeof(test5[0]));
   printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));

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
