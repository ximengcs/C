#include <stdio.h>
#define LINE 1000
int getline(char [],int lim);
void reverse(char []);
int main(void)
{
	char sign[LINE];
	int n;
	
	n = 0;
	while((n = getline(sign,LINE)) != 0)
	{
		reverse(sign);
		printf("%s",sign);
	}
	return 0;
}
int getline(char s[],int lim)
{
	int i, c;
	
	i = 0;
	while((c = getchar()) != EOF && c != '\n' && i < lim-1)
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
void reverse(char s[])
{
	int m, n, c;
	
	n = 0;
	m = 0;
	while(s[n] != '\0' && s[n] != '\n')
		n++;
	n--;
	while( n > m )
	{
		c = s[n];
		s[n] = s[m];
		s[m] = c;
		n--;
		m++;
	}
}