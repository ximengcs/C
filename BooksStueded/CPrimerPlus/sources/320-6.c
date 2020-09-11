#include <stdio.h>
char *strncpy_1(char *ar,char *br,int n);
void show(char *ar);
int main(void)
{
	int q;
	char *a;
	char ch1[40],ch2[20];
	gets(ch2);
	scanf("%d",&q);
	a=strncpy_1(ch1,ch2,q);
	if(a!=NULL)
		printf("%p\n",a);
	show(ch1);
	putchar('\n');
	show(ch2);
	return 0;
}
char *strncpy_1(char *ar,char *br,int n)
{
	int i=0,s=0,j=0;
	while(*(br+i))
	{
		i++;
		j++;
	}
	if((j+1)<n)
	{
		for(i=0;i<n;i++)
		{
			ar[i]=br[i];
		}
		ar[n]='\0';
		return NULL;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			ar[i]=br[i];
		}
		return ar;
	}
}
void show(char *ar)
{
	int i=0;
	while(*(ar+i)!='\0')
	{
		printf("%d:[%c] ",i+1,*(ar+i));
		i++;
	}
}
	