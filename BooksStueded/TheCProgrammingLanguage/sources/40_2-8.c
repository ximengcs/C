#include <stdio.h>
unsigned int rightrot(unsigned int,unsigned int);
void show(unsigned int);
int main(void)
{
	unsigned int x,n;
	scanf("%d %d",&x,&n);
	show(x);
	printf("%d",rightrot(x,n));
	return 0;
}
unsigned int rightrot(unsigned int x,unsigned int n)
{
	unsigned int i,num = 0, l = 1, size;
	size = sizeof(unsigned int) * 8;
	for(i = 1; i < n; i++)
	{
		num = num + l * 2;
		l *= 2;
	}
	num ++;
	num = (num & x) << (size - n);
	show(num);
	i = (x >> n) | num;
	show(i);
	return i;
}
void show(unsigned int n)
{
	char ch[sizeof(unsigned int) * 8];
	int size, i;
	size = sizeof(unsigned int) * 8;
	for(i = size - 1; i >=0 ; i--)
	{
		if(n != 0)
		{
			ch[i] = n % 2 + '0';
			n /= 2;
		}
		else
			ch[i] = '0';
	}
	for(i = 0; i < size; i++)
	{
		putchar(ch[i]);
	}
	putchar('\n');
}