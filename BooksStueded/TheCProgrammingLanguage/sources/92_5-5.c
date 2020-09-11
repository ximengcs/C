#include <stdio.h>
void strncpy_(char *s1,const char *s2,int n);
void strncat_(char *s1,const char *s2,int n);
int strncmp_(const char *s1,const char *s2,int n);
int main(void)
{
	char s1[40],s2[40];
	int n;
	gets(s1);
	gets(s2);
	scanf("%d",&n);
	printf("%d",strncmp_(s1,s2,n));
	return 0;
}
int strncmp_(const char *s1,const char *s2,int n)
{
	int i;
	for(i = 0; ((*(s1 + i) == *(s2 + i)) && (i <= n)) || *(s1 + i) == '\0' || *(s2 + i) == '\0'; i++)
		if(i == n)
			return 0;
	return *(s1 + i) - *(s2 + i);
}
void strncpy_(char *s1,const char *s2,int n)
{
	int i = 0;
	while( (*(s1 + i) = *(s2 + i)) != '\0' && i < n)
		i++;
	*(s1 + i) = '\0';
}
void strncat_(char *s1,const char *s2,int n)
{
	int i = 0;
	while( *(++s1) != '\0')
		;
	while( (*(s1 + i) = *(s2 + i)) != '\0' && i < n)
		i++;
	*(s1 + i) = '\0';
}