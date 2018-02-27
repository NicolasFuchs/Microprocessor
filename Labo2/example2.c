struct TEST
{
	int  a;
	char b;
	int  c;
	char d;
} test [1000];

int main (void)
{
	for (i=0, i<100 ; i++)
	{
		test[i].a=1;
		test[i].b=2;
		test[i].c=3;
		test[i].d=4;
	}
}
