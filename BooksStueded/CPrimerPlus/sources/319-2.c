#include <stdio.h>
void input(char *ar);
void show(char *ar);
int main(void)
{
	char num[10];
	input(num);
	show(num);
	return 0;
}
void input(char *ar)
{
	int i;
	char q;
	for(i=0;i<10;i++)
	{
		q=getchar();
		if(q==' '||q=='\t'||q=='\v'||q=='\n')
		{
			ar[i]='\0';
			break;
		}
		else
			ar[i]=q;
	}
}
void show(char *ar)
{
	int i;
	puts(ar);
}