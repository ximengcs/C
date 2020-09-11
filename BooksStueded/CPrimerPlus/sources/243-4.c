#include <stdio.h>
double jkz(double x,double y);
int main (void)
{
	double a,b,j;
	while(1)
	{
		if(scanf("%lf%lf",&a,&b)!=2)   //double类型输出输入用lf，no f；！！！
			break;
		j=jkz(a,b);
		printf("j=%.2lf",j);
	}
}
double jkz(double x,double y)
{
	double j;
	j=((1/x)+(1/y))/2;
	j=1.0/j;
	return j;
}