#include <stdio.h>
int chari(void);
int main(void)
{
	int i;
	i = chari();
	printf("%d",i);
}
int chari(void)
{
	int ch;
	while((ch = getchar())!=EOF)
	{
		if(ch>=65 && ch<=90)
		{
			ch = ch-64;
			printf("ch's number is %d\n",ch);
		}
		if((ch>=97 && ch<=122))
		{
			ch=ch-96;
			printf("ch's number is %d\n",ch);
		}
	}
	return ch;
}
