#include <stdio.h>
#define o 5
void num_add(int *ar,int n);
void show(int *ar,int n);
int main(void)
{
	int a,b=0;
	int x1[o]={1,2,3,4,5};
	printf("input a number:");
	scanf("%d",&a);
	while(b<a)
	{
		num_add(x1,o);
		show(x1,o);
		b++;
		printf("\n");
	}
	return 0;
}
void num_add(int *ar,int n)
{
	int i;
	for(i=0;i<n;i++)
		*(ar+i)=(*(ar+i))*2;
}
void show(int *ar,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",*(ar+i));
}