#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define NB_STRUCT 1000
#define NB_LOOP 10000

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
	char b;
	char d;
	int a __attribute__ ((packed));
	int c __attribute__ ((packed));
} TEST4;

typedef struct _TEST5{
	char b __attribute__ ((packed));
	char d __attribute__ ((packed));
	int a __attribute__ ((aligned (4)));
	int c __attribute__ ((aligned (4)));
} TEST5;

static double diff(struct timespec start, struct timespec end);
static TEST1 test1[NB_STRUCT]; 
static TEST2 test2[NB_STRUCT];
static TEST3 test3[NB_STRUCT];
static TEST4 test4[NB_STRUCT];
static TEST5 test5[NB_STRUCT];

void test_1();
void test_2();
void test_3();
void test_4();
void test_5();

int main()
{
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
}

void test_1()
{
	struct timespec tStart, tEnd;
	clock_gettime(CLOCK_REALTIME, &tStart);
	for (int loop=0 ; loop<NB_LOOP ; loop++)
	{
		for (int i=0 ; i<NB_STRUCT ; i++)
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
}

void test_2()
{
	struct timespec tStart, tEnd;
	clock_gettime(CLOCK_REALTIME, &tStart);
	for (int loop=0 ; loop<NB_LOOP ; loop++)
	{	
		for (int i=0 ; i<NB_STRUCT ; i++)
		{
			test2[i].a = 1;
			test2[i].b = 2;
			test2[i].c = 3;
			test2[i].d = 4;
		}
	}
	clock_gettime(CLOCK_REALTIME, &tEnd);
	printf ("Test2:\n");
	printf ("  struct size = %li",sizeof(test2[0]));
	printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));
}

void test_3()
{
	struct timespec tStart, tEnd;
	clock_gettime(CLOCK_REALTIME, &tStart);
	for (int loop=0 ; loop<NB_LOOP ; loop++)
	{
		for (int i=0 ; i<NB_STRUCT ; i++)
		{
			test3[i].a = 1;
			test3[i].b = 2;
			test3[i].c = 3;
			test3[i].d = 4;
		}
	}
	clock_gettime(CLOCK_REALTIME, &tEnd);
	printf ("Test3:\n");
	printf ("  struct size = %li",sizeof(test3[0]));
	printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));
}


void test_4()
{
	struct timespec tStart, tEnd;
	clock_gettime(CLOCK_REALTIME, &tStart);
	for (int loop=0 ; loop<NB_LOOP ; loop++)
	{
		for (int i=0 ; i<NB_STRUCT ; i++)
		{
			test4[i].a = 1;
			test4[i].b = 2;
			test4[i].c = 3;
			test4[i].d = 4;
		}
	}
	clock_gettime(CLOCK_REALTIME, &tEnd);
	printf ("Test4:\n");
	printf ("  struct size = %li",sizeof(test4[0]));
	printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));
}


void test_5()
{
	struct timespec tStart, tEnd;
	clock_gettime(CLOCK_REALTIME, &tStart);
	for (int loop=0 ; loop<NB_LOOP ; loop++)
	{	
		for (int i=0 ; i<NB_STRUCT ; i++)
		{
			test5[i].a = 1;
			test5[i].b = 2;
			test5[i].c = 3;
			test5[i].d = 4;
		}
	}
	clock_gettime(CLOCK_REALTIME, &tEnd);
	printf ("Test5:\n");
	printf ("  struct size = %li",sizeof(test5[0]));
	printf ("  nb secondes :\t%f\n", diff(tStart, tEnd));
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


