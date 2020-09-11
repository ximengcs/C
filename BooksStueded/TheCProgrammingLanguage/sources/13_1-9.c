#include <stdio.h>
int main(void)
{
	int c1 = '\0', c2;
	while((c2 = getchar()) != EOF)
	{
		if(c1 != ' ' || c2 != ' ')
			putchar(c2);
		c1 = c2;
	}
	return 0;
}