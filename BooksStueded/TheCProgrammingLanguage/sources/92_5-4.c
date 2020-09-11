#include <stdio.h>
int strend(char *,char *);
int main(void)
{
	char s1[10],s2[10];
	gets(s1);
	gets(s2);
	printf("%d",strend(s1,s2));
	return 0;
}
int strend(char *s,char *t)
{
	char *n = t;
	while( *(++t) != '\0' )
		;
	while( *(++s) != '\0' )
		;
	while( *(t--) == *(s--) )
		if(t == n)
			return 1;
	return 0;
}