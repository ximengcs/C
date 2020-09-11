#include <stdio.h>
#include <stdlib.h>
#define   SIZE   1000

int main( void )
{
	char characters[SIZE];
	int         c;
	unsigned code;
	
	code = 0;
	while( (c = getchar()) != EOF )
		characters[code++] = c;
	characters[code] = '\0';
	
	code = 0;
	while( (c = characters[code++]) != '\0' )
		if( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) )
			putchar( c - 13 );
		else
			putchar( c );
	
	return EXIT_SUCCESS;
}