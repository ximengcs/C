#include <stdio.h>
#include <string.h>
char *l_strchr(char *ar,char *br);
int main(void)
{
	char num_group[40];
	char num;
	int i=1;
	gets(num_group);
	gets(&num);
	printf("%p",l_strchr(num_group,&num));
	return 0;
}
char *l_strchr(char *ar,char *br)
{
	int i=0;
	while(*ar!='\0')
	{
		if(strcmp(ar+i,br)==0)
			return br;
		i++;
	}
	return NULL;
}