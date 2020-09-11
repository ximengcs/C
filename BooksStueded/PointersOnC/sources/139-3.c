#include <stdio.h>
#include <stdlib.h>
#define   SIZE   1000

int ascii_to_integer( char *string );

int main( void )
{
	char characters[SIZE];
	int  num;
	
	num = 0;
	gets( characters );
	num = ascii_to_integer( characters );
	printf( "%d", num );
	
	return EXIT_SUCCESS;
}

int ascii_to_integer( char *string )
{
	int  c;
	
	c = 0;
	while( *string != '\0' ){
		if( *string >= 48 && *string <= 57 ){
			if( c == 0 )
				c = *string - '0';
			else
				c = c*10 + *string - '0';
		}
		else
			return 0;
		string++;
	}
	
	return c;
}