#include <stdio.h>
#include <string.h>
int main(void)
{
	char name[30];
	int count1;
	printf("输入你的名字：");
	scanf("%s",name);
	count1 = strlen(name)+3;
	printf("a:\"%s\"\n",name);
	printf("b:\"%20s\"\n",name);
	printf("c:\"%-20s\"\n",name);
	printf("d:\"%*s\"",count1,name);   //*作用printf事先不知道要设置多少长度
	                                   //*scanf中%d，%d，%d读取最后一个值赋值给变量
	printf("\n%d",count1);             //一个汉子占两个字节。。。
	return 0; 
}