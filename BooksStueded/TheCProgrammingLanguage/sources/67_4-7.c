void ungstch(int c);
void ungets(char s[])
{
	while( *s != '\0')
		ungetch(*(s++));
}