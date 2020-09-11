#include <stdio.h>
void Fibonacci(unsigned int i);
int main(void)
{
	unsigned int i;
	while(1)
	{
		scanf("%ld",&i);
		Fibonacci(i);
	}
	return 0;
}
void Fibonacci(unsigned int i)
{
	unsigned int j,a=1,b=1,c=0;
	i--;
	if(i == 0)
		printf("0\n");
	else if(i == 1)
		printf("0 1\n");
	else if(i == 2)
		printf("0 1 1\n");
	else
	{
		printf("0 1 1");
		for(j=3;j<=i;j++)
		{
			c = a+b;
			a = b;
			b = c;          
			printf("% ld",c);
		}
		printf("\n");
	}
}