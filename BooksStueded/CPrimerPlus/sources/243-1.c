#include <stdio.h>
float mini (float x,float y);
int main(void)
{                                                              //驱动程序...{
	float ce,ce2,rt;
	printf("please input two number:(q to quit)");
	while(scanf("%f%f",&ce,&ce2) == 2)
	{
		rt=mini(ce,ce2);
		printf("rt=%.2f\n",rt);
		printf("please input two number:(q to quit)");
	}
	printf("OK!!!");
}																//驱动程序...}
float mini(float x,float y)
{
	if(x < y)
		return x;
	return y;
}