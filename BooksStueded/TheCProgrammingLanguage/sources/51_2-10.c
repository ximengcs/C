#include <stdio.h>
char lower(char);
int main(void)
{
	char x;
	x = getchar();
	putchar(lower(x));
	return 0;
}
char lower(char a)
{
	return (a >= 65 && a <= 90) ? (a + 32) : a;
}