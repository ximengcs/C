#include <stdio.h>
int main(void)
{
	float c,f;
	printf("输入华氏温度");
	scanf("%f",&f);
	c = 5.0/9.0*(f-32);    //乘号不能省略
	printf("%.2f华氏温度=%.2f摄氏温度",f,c);
	return 0;
}