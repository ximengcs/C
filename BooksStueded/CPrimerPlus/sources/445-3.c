#include <stdio.h>
int sum_point(int);
int main(void)
{
	int num;
	scanf("%d",&num);
	printf("数字共有%d位打开",sum_point(num));
	return 0;
}
int sum_point(int num)
{
	int ch[9];
	int i,s=0;
	for(i=7;i>=0;i--)
	{
		ch[i]=num%2;
		num/=2;
	}
	ch[8]='\0';
	printf("该数字的二进制码：");
	for(i=0;i<8;i++)
		printf("%d",ch[i]);
	putchar('\n');
	for(i=0;i<8;i++)
		if(ch[i]==1)
			s++;
	return s;
}