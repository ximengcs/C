#include <stdio.h>
#define MAXLINE 1000
int getline(char s[],int lim);
int main(void)
{
	char s[MAXLINE];
	int max, len;
	
	while((len = getline(s,MAXLINE)) > 0)
		if(len >= 80)
			printf("%d:%s",len,s);
	return 0;
}
int getline(char s[],int lim)
{
	int i, j, c;
	
	j = 0;
	i = 0;
	while((c = getchar()) != EOF && c != '\n')
		if(i < lim-2)
		{
			s[j] = c;
			j++;
			i++;
		}
	if(c == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return i;
}