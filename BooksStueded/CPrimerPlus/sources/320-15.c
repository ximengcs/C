#include <stdio.h>
#include <string.h>
void bill_1(char *ar);
void bill_2(char *ar);
void bill_3(char *ar);
int main(int argc,char *argv[])
{
	int code;
	char ch[100]={'\0'};
	char qr[][3]={{'-','p','\0'},{'-','u','\0'},{'-','l','\0'}};
	gets(ch);
	if(strcmp(argv[1],qr[0])==0)
		code=1;
	if(strcmp(argv[1],qr[1])==0)
		code=2;
	if(strcmp(argv[1],qr[2])==0)
		code=3;
	switch(code)
	{
		case 1:bill_1(ch);break;
		case 2:bill_2(ch);break;
		case 3:bill_3(ch);break;
	}
	return 0;
}
void bill_3(char *ar)
{
	int i=0,s;
	while(ar[i]!='\0')
		i++;
	for(s=0;s<i;s++)
	{
		if(ar[s]>=65&&ar[s]<=90)
			ar[s]=ar[s]+32;
	}
	bill_1(ar);
}
void bill_2(char *ar)
{
	int i=0,s;
	while(ar[i]!='\0')
		i++;
	for(s=0;s<i;s++)
	{
		if(ar[s]>=97&&ar[s]<=122)
			ar[s]=ar[s]-32;
	}
	bill_1(ar);
}
void bill_1(char *ar)
{
	int i=0,s;
	while(ar[i]!='\0')
		i++;
	for(s=0;s<i;s++)
	{
		putchar(ar[s]);
	}
}