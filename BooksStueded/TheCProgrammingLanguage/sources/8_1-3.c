#include <stdio.h>
void showmenu(void);
int main(void)
{
	float fahr, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	showmenu();
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n",fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
void showmenu(void) //打印标题
{
	printf("华氏 摄氏\n");
}