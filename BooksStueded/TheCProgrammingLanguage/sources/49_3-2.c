#include <stdio.h>
void espace(char *,char *);
int main(void)
{
	char a[10];
	char b[10];
	gets(b);
	espace(a,b);
	return 0;
}
void espace(char *a,char *b)
{
	int i = 0, code;
	while((code = *(b + i)) != '\0')
	{
		switch(code)
		{
			case '\n':{
				*(a + i) = '\\';
				i++;
				*(a + i) = 'n';
				i++;
				break;
			}
			case '\t':{
				*(a + i) = '\\';
				i++;
				*(a + i) = 't';
				i++;
				break;
			}
			default :{
				*(a + i) = code;
				i++;
				break;
			}
		}
	}
	*(a + i) = '\0';
	printf("%s",a);
}
	