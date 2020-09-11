#include <stdio.h>
double power(void);
int main(void)
{
	double j;
	while(1)
	{
		printf("input two number:");
		j=power();	
		printf("j=%lf\n",j);		
	}

}
double power(void)
{
	int y;
	double x,i=1,j=1;
	scanf("%lf%d",&x,&y);
	if(y == 0)
	{
		i = 1;
	}
	if(y < 0)
	{
		y=-y;
		while(j<=y)
		{
			i = i*x;
			j++;
		}
		i = 1.0/i;
	}
	if(y > 0)
	{
		while(j<=y)
		{
			i = i*x;
			j++;
		}
	}
	return i;
}