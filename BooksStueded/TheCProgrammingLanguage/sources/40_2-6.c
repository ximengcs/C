#include <stdio.h>
void show(int);
int setbits(int,int,int,int);
int main(void)
{
	int x,y,n,p;
	scanf("%d %d %d %d",&x,&p,&n,&y);
	show(x);
	show(y);
	show(setbits(x,p,n,y));
	return 0;
}
int setbits(int x,int p,int n,int y)
{
	int size = sizeof(int) * 8;
	int num = 1,i,j;
	long long zhishu = 1,l = 1;
	if(n == 1)
		num = 1;
	else
	{
		for(i = 1; i < n; i++)
		{
			num = num + l * 2;
			l *= 2;
		}
	}
	for( j = 1 ; j <= size - p; j++)
			zhishu *= 2;
	for(i = 1, l = 0; i <= n ; i++ )
	{
		l = l + zhishu;
		zhishu /= 2;
	}
	x = x | ((num&y)<<(size - ( p + n - 1)));
	return x;
}
void show(int n)
{
	int size = sizeof(int) * 8;
	char ch[size];
	int i;
	for(i = size - 1; i >= 0 ; i--)
	{
		if(n != 0)
		{
			ch[i] = (n % 2) + '0';
			n /= 2;
		}
		else
		{
			ch[i] = '0';
		}
	}
	for(i = 0; i < size ;i++)
	{
		putchar(ch[i]);
	}
	putchar('\n');
}