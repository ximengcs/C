#include <stdio.h>
int main(void)
{
	float x,y;
	int j;
	scanf("%f",&x);
	if(x>10)
	{
		y = x*x+1;
		printf("%.2f",y);
	}else if(x<=0)
	{
		y = x*x-1;
		printf("%.2f",y);
	}else {
		y = x*x;
		printf("%.2f",y);
	}
	return 0;
}