#include <stdio.h>
#include <string.h>
void itob(int,char *,int);
void reverse(char s[]);
int main(void)
{
	int num ,n ;
	char ch[40];
	scanf("%d %d",&num ,&n);
	itob(num ,ch ,n);
	puts(ch);
	return 0;
}
void itob(int num,char *ch,int n)
{
	int i = 0;
	while(num != 0)
	{
		if(n < 10)
		{
			*(ch + i) = num % n + '0';
			num /= n;
			i++;
		}
		else 
		{
			if((num % n) <= 10)
			{
				*(ch + i) = num % n + '0';
				num /= n;
				i++;
			}
			else
			{
				*(ch + i) = num % n + 55;
				num /= n;
				i++;
			}
		}
	}
	if(n == 8)
		ch[i++] = '0';
	else if(n == 16)
	{
		ch[i++] = 'X';
		ch[i++] = '0';
	}
	*(ch + i) = '\0';
	reverse(ch);
}
void reverse(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}