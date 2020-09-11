#include <stdio.h>
#include <stdlib.h>
#define   SIZE   1000

int main( void )
{
	char characters[SIZE];
	int  c;
	int  code;
	
	code = 0;
	while( (c = getchar()) != EOF ){
		if( c >= 65 && c <= 90 )
			characters[code++] = c + 32;
		else characters[code++] = c;
	}
	characters[code] = '\0';
	
	printf( "%s", characters );
	
	return EXIT_SUCCESS;
}