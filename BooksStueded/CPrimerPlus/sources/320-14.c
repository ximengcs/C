#include <stdio.h>
int main(void)
{
	long i=0,s=0,z=0,a=1,q,b=0;
	char ch[10]={'\0'};
	char u=0;
	long ar[11]={'\0'};
	gets(ch);
	if(ch[0]==45)
		b++;
	for(i=0;ch[b]>=48&&ch[b]<=57||ch[b]==45;i++,b++)
	{
		if(ch[0]==45)
		{
			u='-';
		}
		ar[i]=ch[b]-48;
		if(ch[b+1]<48||ch[b+1]>57)
			break;
	}
	while(ar[s]!='\0')
		s++;
	for(q=1;q<s;q++)
		a=a*10;
	if(s!=1)
	{
		if(u=='-')
		{
			printf("%c",u);
		}
		for(i=0;i<s;i++)
		{	
			z=z+ar[i]*a;
			a=a/10;
		}
	}
	else z=ar[0];
	printf("%d",z);
	return 0;
}