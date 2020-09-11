#include <stdio.h>
#define N 5
void show(int show[]);
void copy_a(int ar[],int br[],int n);
void copy_b(int ar[],int br[],int n);
int main(void)
{
	int ar[N]={1,2,3,4,5};
	int br[N];
	int cr[N];
	copy_a(ar,br,N);
	copy_b(ar,cr,N);
	show(ar);
	show(br);
	show(cr);
	return 0;
}
void copy_a(int ar[],int br[],int n)
{
	int i;
	for(i=0;i<n;i++)
		br[i]=ar[i];
}
void copy_b(int ar[],int br[],int n)
{
	int i;
	for(i=0;i<n;i++)
		*(br+i)=*(ar+i);
}
void show(int show[])
{
	int i,j;
	for(i=0;i<N;i++)
		printf("%d ",*(show+i));
	printf("\n");
}