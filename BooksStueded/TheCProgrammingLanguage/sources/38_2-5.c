#include <stdio.h>
int any(char *s1, char *s2);
int main(void)
{
	char a[10],b[10];
	gets(a);
	gets(b);
	printf("%d",any(a,b));
	return 0;
}
int any(char *s1,char *s2)
{
	int count = 0,i,j;
	while(s2[count] != '\0')
		count++;
	for(i = 0; i < count ; i++)
	{
		if(strncmp(s1 + i,s2,count) == 0)
			return i;
	}
	return -1;
}