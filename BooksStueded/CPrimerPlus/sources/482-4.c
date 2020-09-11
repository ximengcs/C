#include <stdio.h>
#include <time.h>
void time_a(double);
int main(void)
{
	clock_t b;
	double a;
	int i,s=0;
	b=clock();
	for(i=0;i<1000000000;i++);
	a=(double)((clock()-b))/CLOCKS_PER_SEC;
	printf("%lf",a);
	time_a(a);
	return 0;
}
void time_a(double num)
{
	printf("%lf",num*CLOCKS_PER_SEC);
}