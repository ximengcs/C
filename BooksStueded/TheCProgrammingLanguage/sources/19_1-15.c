#include <stdio.h>
double change_h(double);
double change_s(double);
int main(void)
{
	int i;
	
	printf("华氏 摄氏\n");
	for(i = 0; i < 300; i+=20)
		printf("%4d %5.1f\n",i ,change_h(i));
	putchar('\n');
	printf("摄氏 华氏\n");
	for(i = 0; i < 300; i+=20)
		printf("%4d %5.1f\n",i ,change_s(i));
	return 0;
}
double change_h(double h)
{
	double c;
	c = (5.0/9) * (h-32);
	return c;
}
double change_s(double s)
{
	double h;
	h = s / (5.0/9) + 32;
	return h;
}