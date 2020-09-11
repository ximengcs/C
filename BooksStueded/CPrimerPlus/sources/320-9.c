#include <stdio.h>
void ch_dlt(char *ar);
void show(char *ar);
int main(void)
{
	char ch[100]={'\0'};
	gets(ch);
	show(ch);
	ch_dlt(ch);
	putchar('\n');
	show(ch);
	while(ch[0]!='\n')
	{
		ch[0]='\n';
		gets(ch);
		if(ch[0]!='\n')
			show(ch);
		ch_dlt(ch);
		if(ch[0]!='\n')
			show(ch);
		if(ch[0]!='\n')
			ch[0]='\n';
	}
		
	return 0;
}
void ch_dlt(char *ar)
{
	int i=0,space_j=0,space_m=0,space_n=0,num_m=0,num_j=0;
	while(ar[i])
		i++;
	while(space_n<i)
	{
		while(space_m<i)
		{
			if(ar[space_m]==' ')
			{
				space_j++;
				if(ar[space_m+1]!=' ')
					break;
			}
			space_m++;
		}
		space_m=space_n;
		if(ar[space_m]==' ')
		{
			ar[space_m]=ar[space_m+space_j];
			ar[space_m+space_j]=' ';
		}
		space_j=0;
		space_n++;
	}
		
}
void show(char *ar)
{
	int i=0,j;
	while(ar[i])
		i++;
	for(j=0;j<i;j++)
	{
		putchar(ar[j]);
	}
}