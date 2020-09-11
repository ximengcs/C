#include <stdio.h>
#include <string.h>
#define IN 1
#define OUT 0
#define MAXLINE 1000
int get(char *);
int main(void)
{
	char sign[MAXLINE];
	int state, i, s;
	
	state = OUT;
	i = 0;
	get(sign);
	while(sign[i] != '\0')
	{
		if(sign[i] == '\"' || sign[i] == '\'')
		{
			if(state == OUT)
				state = IN;
			else state = OUT;
		}
		if(i != 0 && sign[i] == '/' && sign[i-1] == '/' && state == OUT)
		{
			sign[i-1] = '\0';
			i++;
			while(sign[i] != '\n')
				i++;
			strcat(sign,sign+i);
		}
		if(i != 0 && sign[i] == '*' && sign[i-1] == '/' && state == OUT)
		{
			sign[i-1] = '\0';
			i++;
			while(sign[i] != '*' && sign[i+1] != '/')
				i++;
			i += 2;
			strcat(sign,sign+i);
		}
		i++;
	}
	puts(sign);
	return 0;
}
int get(char s[])
{
	int c, i;
	
	i = 0;
	while((c = getchar()) != EOF)
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}