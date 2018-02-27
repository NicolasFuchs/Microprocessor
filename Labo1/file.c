#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char array [1000];
char *p1;

void abc (void) {}

int main (void)
{
	int a;
	double b;
	a = 10;
	p1 = malloc (10000);
	free (p1);
	b = sqrt(10.0);
	abc();
	printf("array = %p, &p1 = %p, p1 = %p, &a = %p, &b = %p\n",array,&p1,p1,&a,&b);
	return (0);
}
