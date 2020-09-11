#include <stdio.h>
void copy_b(int ar[],int br[],int n);
void show(int ar[],int n);
int main(void)
{
	int x1[7]={1,2,3,4,5,6,7};
	int x2[3];
	copy_b(x1+2,x2,3);
	show(x1,7);
	printf("\n");
	show(x2,3);
	return 0;
}
void copy_b(int ar[],int br[],int n)
{
	int i;
	for(i=0;i<n;i++)
		*(br+i)=*(ar+i);
}
void show(int ar[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",*(ar+i));
}