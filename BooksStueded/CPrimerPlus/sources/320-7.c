#include <stdio.h>
char *string_in(char *ar,char *br);
void show(char *ar);
int main(void)
{
	char ch1[100]={'\0'},ch2[50]={'\0'};
	char *q;
	gets(ch1);gets(ch2);
	show(ch1);show(ch2);
	q=string_in(ch1,ch2);
	printf("%p",q);
	return 0;
}
char *string_in(char *ar,char *br)
{
	char *q;
	int i,j,k=0,m=0,n=0,w;
	while(ar[m])
		m++;
	while(br[n])
		n++;
	for(i=0;i<m;i++)
	{
		q=&ar[i];
		for(j=0,w=i;j<n;j++,w++)
		{
			if(ar[w]==br[j])
			{
				k++;
				if(br[j+1]=='\0')
					break;
			}
			else
				break;
		}
		if(k==n)
			return q;
		k=0;
	}
	return NULL;
}
void show(char *ar)
{
	int a,m=0;
	while(ar[m])
		m++;
	for(a=0;a<m;a++)
	{
		printf("%2d:[%c][%p] ",a+1,ar[a],&ar[a]);
		if((a+1)%4==0)
			printf("\n");
	}
	printf("\n");
}
	
	
	
	
	