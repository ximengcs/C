#include <stdio.h>
#include <math.h>
int main(void)
{
	float x1,x2,x3,x4,a,b,c;
	scanf("%fxx+%fx+c=0",&a,&b,&c);
	if(a==0)
	{
		x1 = -b/c;
		printf("x=%.2f",x1);
	}else if((b*b-4*a*c) > 0)
	{
		x2 = (-b+sqrt(b*b-4*a*c))/(2*a);
		x3 = (-b-sqrt(b*b-4*a*c))/(2*a);
		printf("x1=%.2f,x2=%.2f",x2,x3);
	}else if((b*b-4*a*c) == 0)
	{
		x4 = -b/(2*a);
		printf("x=%.2f",x4);
	}else {
		printf("无解");
	}
	return 0;
}