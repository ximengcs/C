#include <stdio.h>
double power(double x,int y,int i);
int main(void)
{
	int y,i=1;
	double j,x;
	while(1)
	{
		printf("input two number:");
		scanf("%lf%d",&x,&y);
		j=power(x,y,i);	
		printf("j=%lf\n",j);		
	}

}
double power(double x,int y,int i)
{
	if(y==0)
		return 1;
	if(y < 0)
	{
		if(i<=y)
		{
			x=x*x;
			i++;
			power(x,y,i);
		}
		x = 1.0/x;
		return x;
	}
	if(i<=y)
	{
		x=x*x;
		i++;
		power(x,y,i);
	}
	return x;
}
