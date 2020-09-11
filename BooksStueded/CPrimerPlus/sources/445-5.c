#include <stdio.h>
void change(unsigned int,int);
int main(void)
{
	int num,i;
	scanf("%d %d",&num,&i);
	change(num,i);
	return 0;
}
void change(unsigned int a,int b)
{
	int i,s,j;
	int ch[8];
	for(i=7;i>=0;i--)
	{
		ch[i]=a%2;
		a/=2;
	}
	printf("该数字的二进制码为:");
	for(i=0;i<8;i++)
		printf("%d",ch[i]);
	putchar('\n');
	for(i=0;i<b;i++)
	{
		for(j=0;j<=8;j++)
		{
			if(j==0)
				s=ch[0];
			else if(j==8)
				ch[7]=s;
			else
				ch[j-1]=ch[j];
		}
	}
	printf("\n移动%d位后二进制码为：",b);
	for(i=0;i<8;i++)
		printf("%d",ch[i]);
}
