#include <stdio.h>
int is_within(char ch,char *ar);
int main(void)
{
	char ch[40];
	char a;
	gets(ch);
	a=getchar();
	printf("%d",is_within(a,ch));
	return 0;
}
int is_within(char ch,char *ar)
{
	int i;
	for(i=0;i<40;i++)
	{
		if(ch==*(ar+i))
			return 1;
	}
	return 0;
}