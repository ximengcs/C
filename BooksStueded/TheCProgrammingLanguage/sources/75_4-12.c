#include <stdio.h>
#include <string.h>
void itoa(int,char *);
void reverse(char s[]);
int main(void)
{
	char num[40] = {'\0'};
	int i;
	scanf("%d",&i);
	itoa(i,num);
	reverse(num);
	puts(num);
	return 0;
}
void itoa(int n,char *num)
{
	int i, s;
	if(n < 0)
	{
		num[0] = '-';
		n = -n;
		num ++;
	}
	if(n != 0)
	{
		itoa(n / 10,num + 1);
		*num = n % 10 + '0';
	}
}
void reverse(char s[])
{
	int c, i ,j;
	if(s[0] == '-')
		s++;
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}