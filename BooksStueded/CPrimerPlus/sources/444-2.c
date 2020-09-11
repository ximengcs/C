#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void qufan(char *,char *);
void weiyu(char *,char *);
void weihuo(char *,char *);
void weiyiyu(char *,char *);
int main(int argc,char *argv[])
{
	int i;
	if(argc!=3)
	{
		fprintf(stderr,"参数不够");
		exit(1);
	}
	printf("未转换的二进制码：(1)%s  (2)%s\n",argv[1],argv[2]);
	printf("\n经过~转换后:");
	qufan(argv[1],argv[2]);
	printf("\n经过&转换后:");
	weiyu(argv[1],argv[2]);
	printf("\n经过|转换后:");
	weihuo(argv[1],argv[2]);
	printf("\n经过^转换后:");
	weiyiyu(argv[1],argv[2]);
	return 0;
}
void weiyiyu(char *a,char *b)
{
	char c[9];
	int i;
	for(i=7;i>=0;i--)
	{
		if((a[i]=='1' && b[i]=='0')||(a[i]=='0' && b[i]=='1'))
			c[i]='1';
		else
			c[i]='0';
	}
	c[8]='\0';
	puts(c);
}
void weihuo(char *a,char *b)
{
	char c[9];
	int i;
	for(i=7;i>=0;i--)
	{
		if(a[i]=='1'|| b[i]=='1')
			c[i]='1';
		else
			c[i]='0';
	}
	c[8]='\0';
	puts(c);
}
void weiyu(char *a,char *b)
{
	char c[9];
	int i;
	for(i=7;i>=0;i--)
	{
		if(a[i]=='1' && b[i]=='1')
			c[i]='1';
		else
			c[i]='0';
	}
	c[8]='\0';
	puts(c);
}
void qufan(char *a,char *b)
{
	char c[9];
	int i;
	for(i=7;i>=0;i--)
	{
		if(a[i]=='0')
			c[i]='1';
		else if(a[i]=='1')
			c[i]='0';
	}
	c[8]='\0';
	printf("(1)");
	puts(c);
	for(i=7;i>=0;i--)
	{
		if(b[i]=='0')
			c[i]='1';
		else if(b[i]=='1')
			c[i]='0';
	}
	c[8]='\0';
	printf("            (2)");
	puts(c);
}