#include <stdio.h>
void strcat1(char *s1,const char *s2);
int main(void)
{
	char s1[40],s2[10];
	gets(s1);
	gets(s2);
	strcat1(s1,s2);
	puts(s1);
	return 0;
}
void strcat1(char *s1,const char *s2)
{
	int i = 0, j = 0;
	while( *(s1 + i) != '\0')
		i++;
	while( (*(s1 + i) = *(s2 + j)) != '\0')
	{
		i++;
		j++;
	}
}	