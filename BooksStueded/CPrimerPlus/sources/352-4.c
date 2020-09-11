#include <stdio.h>
static int a=0;
int use(void);
int main(void)
{
	int i,j=0,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		j=use();
	}
	printf("共调用了该函数%d次  ",j);
	return 0;
}
int use(void)
{
	a++;
	return a;
}