#include <stdio.h>
void ch_fan(char *ar);
void show(char *ar);
int main(void)
{
	char ch1[50]={'\0'};
	gets(ch1);
	show(ch1);
	ch_fan(ch1);
	putchar('\n');
	show(ch1);
	return 0;
}
void ch_fan(char *ar)
{
	int i=0,j,m;
	char ch;
	while(ar[i])
		i++;
	j=i;
	if(i%2!=0)
		i=(i-1)/2;
	else
		i=i/2;
	for(m=0;m<i;m++)
	{
		ch=*(ar+m);
		*(ar+m)=*(ar+(j-(m+1)));
		*(ar+(j-(m+1)))=ch;
	}
}
void show(char *ar)
{
	int i=0,m;
	while(ar[i])
		i++;
	for(m=0;m<i;m++)
		printf("[%d]:[%c] ",m+1,ar[m]);
}
	
	
	
	