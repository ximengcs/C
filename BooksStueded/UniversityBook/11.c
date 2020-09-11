#include <stdio.h>
int main(void)
{
	int m;
	char size;
	scanf("%d",&m);
	if(m<=127&m>=0)
	{
		size = m;
		printf("数字%d的ASCII为%c",m,size);
	}
	else printf("错误！");
	printf("\n按任意键退出...");
	getchar();
	return 0;
}