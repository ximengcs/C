#include <stdio.h>
int strindex(char s[],char t[]);
int main(void)
{
	char s[20],t[20];
	gets(t);
	gets(s);
	printf("%d",strindex(s,t));
	return 0;
}
int strindex(char s[],char t[])
{
	int i, j, k, l = -1;
	for(i = 0; s[i] != '\0'; i++)
	{
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0')
			l = i + 1;
	}
	return l;
}