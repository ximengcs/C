#include <stdio.h>
int main(void)
{
	int year;
	printf("输入年号");
	scanf("%d",&year);
	if ((year%4)==0)
	{
		printf("%d年为闰年",year);
	}else {
		printf("%d年不是闰年",year);
	}
	return 0;
}