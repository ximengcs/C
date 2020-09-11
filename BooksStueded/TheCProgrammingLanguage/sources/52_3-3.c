#include <stdio.h>
void  expand(char *,char *);
void show(char *);
int main(void)
{
	char a[10] = {'\0'},b[10] = {'\0'};
	gets(a);
	show(a);
	expand(a,b);
	show(b);
	return 0;
}
void expand(char *a,char *b)
{
	int i ,j ,k ,max ,min ,n = 0, l;
	while(a[n] != '\0')
		n++;
	for(i = 0; i < n; i ++)
	{
		if(a[i] >= 97 && a[i] <= 122)
		{
			if(a[i + 1] == '-')
			{
				i ++;
				if(a[i + 1] >=97 && a[i + 1] <= 122 && a[i + 1] > a[i - 1])
				{
					min = a[i - 1];
					max = a[i + 1];
					l = max - min;
					for(k = 0; k <= l; k ++)
					{
						b[k] = min;
						min = min + 1;
					}
					i ++;
				}
			}
		}
	}
}
void show(char *a)
{
	int i;
	for(i = 0; i < 10; i  ++)
	{
		if(a[i] == '\0')
			break;
		else
			printf("%2c ",a[i]);
	}
	putchar('\n');
}