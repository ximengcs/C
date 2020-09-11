#include <stdio.h>
#define o 5
void num_group(int ar1[],int [],int *ar3,int n);
void show(int ar[],int n);
int main(void)
{
	int x1[o]={1,2,3,4,5};
	int x2[o]={6,7,8,9,10};
	int x3[o];
	num_group(x1,x2,x3,o);
	show(x1,o);
	printf("\n");
	show(x2,o);
	printf("\n");
	show(x3,o);
	return 0;
}
void num_group(int ar1[],int ar2[],int *ar3,int n)
{
	int i;
	for(i=0;i<n;i++)
		*(ar3+i)=*(ar1+i)+*(ar2+i);
}
void show(int ar[],int n)
{
	int a;
	for(a=0;a<n;a++)
		printf("%d ",ar[a]);
}