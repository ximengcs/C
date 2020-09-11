#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 40
struct vals_lei{
	double a[NUM];
	double b[NUM];
};
void fillarray(struct vals_lei *,int n);
void showarray(struct vals_lei,int n);
int mycomp(const void * p1,const void * p2);
int main(void)
{
	struct vals_lei vals;
	fillarray(&vals,NUM);
	showarray(vals,NUM);
	qsort(vals.a,NUM,sizeof(double),mycomp);
	puts("\nSorted list:");
	showarray(vals,NUM);
	return 0;
}
int mycomp(const void *p1,const void *p2)
{
	const struct vals_lei *a1 = (const struct vals_lei *)p1;
	const struct vals_lei *a2 = (const struct vals_lei *)p2;
	if((a1->a) < (a2->a))
		return 1;
	else if((a1->a) == (a2->a))
		return 0;
	else return -1;
}
void showarray(struct vals_lei ar,int n)
{
	int i;
	puts("Random list(a):");
	for(i=0;i<n;i++)
	{
		printf("%9.4f",ar.a[i]);
		if(i%6==5)
			putchar('\n');
	}
	if(i%6!=0)
		putchar('\n');
	puts("Random list(b):");
	for(i=0;i<n;i++)
	{
		printf("%9.4f",ar.b[i]);
		if(i%6==5)
			putchar('\n');
	}
	if(i%6!=0)
		putchar('\n');
}
void fillarray(struct vals_lei *ch,int n)
{
	int i;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		ch->a[i]=(double)rand()/((double)rand()+0.1);
		ch->b[i]=(double)rand()/((double)rand()+0.2);
	}
}