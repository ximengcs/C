#include <math.h>
#include <stdio.h>
struct J_adress{
	double district;
	double Jiaodu;
};
struct Z_adress{
	double x_adress;
	double y_adress;
};
struct Z_adress change(struct J_adress);
int main(void)
{
	struct J_adress a;
	struct Z_adress b;
	printf("输入向量的长度和角度:");
	scanf("%lf %lf",&a.district,&a.Jiaodu);
	b=change(a);
	printf("转换后的向量X坐标为:%lf Y的坐标为:%lf",b.x_adress,b.y_adress);
	return 0;
}
struct Z_adress change(struct J_adress ch)
{
	struct Z_adress c;
	c.x_adress=ch.district * cos(ch.Jiaodu);
	c.y_adress=ch.district * sin(ch.Jiaodu);
	return c;
}