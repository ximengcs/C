#include <stdio.h>
void readword(char *ar);
void show(char *ar);
int main(void)
{
	char num[40];
	readword(num);
	show(num);
	return 0;
}
void readword(char *ar)
{
	char q;
	int i;
	for(i=0;i<40;i++)
	{
		q=getchar();
		if(q==' '||q=='\t'||q=='\v'||q=='\n')
		{
			*(ar+i)='\0';
			break;
		}
		else
			*(ar+i)=q;
	}
}
void show(char *ar)
{
	puts(ar);
}