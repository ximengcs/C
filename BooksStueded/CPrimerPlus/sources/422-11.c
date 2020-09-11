#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
void transform(double a[],double b[],int n,double (*p)(double));
void make(double [],int);
void show(double [],int);
int main(void)
{
	double a[100],b[100];
	int n=100;
	int i;
	make(a,n);
	for(i=0;i<4;i++)
	{
		transform(a,b,n,sin);
		printf("第%d次:\n",i+1);
		printf("原数组:\n");
		show(a,n);
		printf("转换后:\n");
		show(b,n);
	}
	return 0;
}
void show(double ar[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%-6.2lf ",ar[i]);
		if((i+1)%10==0)
			putchar('\n');
	}
}
void make(double ch[],int n)
{
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		ch[i]=rand()%999;
	}
}
void transform(double a[],double b[],int n,double (*p)(double))
{
	int i;
	for(i=0;i<n;i++)
	{
		b[i] = (*p)(a[i]);
	}
}