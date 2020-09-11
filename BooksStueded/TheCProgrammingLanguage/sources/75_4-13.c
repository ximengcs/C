#include <stdio.h>
#include <string.h>
void reverse(char s[],int,int);
int main(void)
{
	char s[40] = {'\0'};
	gets(s);
	reverse(s,0,strlen(s) - 1);
	puts(s);
	return 0;
}
void reverse(char s[],int i,int j)
{
	char c;
	if( i < j)
		reverse(s,i+1,j-1);
		c = s[i];
		s[i] = s[j];
		s[j] = c;
}