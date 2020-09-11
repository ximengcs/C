#include <stdio.h>
#define pi 3.14159    //define后定义变量不用等号
int main(void)
{
	float r,c,s;
	printf("输入圆的半径");
	scanf("%f",&r);
	c=2*pi*r;
	s=pi*r*r;
	printf("圆的周长为%.2f\n圆的面积为%.2f",c,s);
	return 0;
}