#include <stdio.h>
int change(int,int);
int main(void)
{
	int num,point;
	scanf("%d %d",&num,&point);
	printf("返回值:%d",change(num,point));
	return 0;
}
int change(int num,int a)
{
	int i;
	int ch[8];
	for(i=7;i>=0;i--)
	{
		ch[i]=num%2;
		num/=2;
	}
	printf("该数字的二进制码为：");
	for(i=0;i<8;i++)
		printf("%d",ch[i]);
	putchar('\n');
	if(ch[a-1]==1)
		return 1;
	else if(ch[a-1]==0)
		return 0;
}