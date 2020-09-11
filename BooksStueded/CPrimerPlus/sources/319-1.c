#include <stdio.h>
void input(char *ar);
void show(char *ar);
int main(void)
{
	int n=10;
	char xx[10];
	input(xx);
	show(xx);
	return 0;
}
void input(char *ar)
{
	int i;
	for(i=0;i<10;i++)
	{
		ar[i]=getchar();
	}
}
void show(char *ar)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d:[%c] ",i+1,ar[i]);
	}
}