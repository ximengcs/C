#include <stdio.h>
int invert(int,int,int);
void show(int);
int main(void)
{
	int x,p,n;
	scanf("%d %d %d",&x,&p,&n);
	printf("%d",invert(x,p,n));
	return 0;
}
int invert(int x,int p,int n)
{
	int i,j=1,k=0,size;
	size = sizeof(int) * 8;
	for(i = 0; i < (size - p); i ++)
	{
		j *= 2;
	}
	for(i = 0; i < n; i ++)
	{
		k = k + j;
		j /= 2;
	}
	i = k ^ x;
	return i;
}
/*void show(int n)
{
	int size;
	char ch[sizeof(int) * 8];
	size = sizeof(int) * 8;
	int i;
	for(i = size - 1; i >= 0; i--)
	{
		if(n != 0)
		{
			ch[i] = n % 2 + '0';
			n /= 2;
		}
		else
			ch[i] = '0';
	}
	for(i = 0; i < size; i ++)
	{
		putchar(ch[i]);
	}
	putchar('\n');
}*/