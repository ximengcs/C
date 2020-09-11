#include <stdio.h>
#define NUM(X,Y) 1.0/(((1.0/(X))+(1.0/(Y)))/2)
int main(void)
{
	double x,y;
	scanf("%lf %lf",&x,&y);
	printf("两数的调和平均数为:%lf",NUM(x,y));
	return 0;
}