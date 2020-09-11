#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void print_tokens( char *line );

int main( void )
{
	char ch[200];
	int c;
	char *i;
	
	i = ch;
	while( (c = getchar()) != EOF )
		*i++ = c;
	*i = '\0';
	
	print_tokens( ch );
	
	return EXIT_SUCCESS;
}

void print_tokens( char *line )
{
	static char whitespace[] = " \t\f\r\v\n";
	char *token;
	
	for( token = strtok( line, whitespace );
		token != NULL;
		token = strtok( NULL, whitespace ) )
		printf( "Next token is %s\n", token );
}