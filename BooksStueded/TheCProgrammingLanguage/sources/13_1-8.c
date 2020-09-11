#include <stdio.h>
int main(void)
{
	long space = 0, zbf = 0, hhf = 0;
	char c;
	while((c = getchar()) != EOF)
		if(c == ' ')
			space++;
		else if(c == '\t')
			zbf++;
		else if(c == '\n')
			hhf++;
		else ;
	printf("空格:%ld\n制表符:%ld\n换行符:%ld",space, zbf, hhf);
	return 0;
}