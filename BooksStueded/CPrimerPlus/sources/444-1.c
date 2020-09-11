#include <stdio.h>
#include <stdlib.h>
int change(char *);
int main(void)
{
	char num[9];
	while(gets(num)!=NULL)
		printf("%s转化为10进制数为:%d\n",num,change(num));
	puts("Bye");
	return 0;
}
int change(char *num)
{
	int i,s=0,z=1;
	for(i=7 ; i>=0 ;i--)
	{
		if(*(num+i)=='0')
			z=z*2;
		else if(*(num+i)=='1')
		{
			s=s+z;
			z=z*2;
		}
		else
		{
			printf("Bye");
			exit(0);
		}
	}
	return s;
}