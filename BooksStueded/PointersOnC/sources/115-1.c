#include <stdio.h>
#include <stdlib.h>

char *find_char( char const *source, char const *chars );

int main( void )
{
	char *characters_one;
	char *characters_two;
	char *temp;
	
	characters_one = "ABCDEF";
	characters_two = "XRCQEF";
	temp = find_char( characters_one, characters_two );
	
	if( temp == NULL )
		printf( " NULL !! " );
	else
		printf( "%s", temp );
	
	return EXIT_SUCCESS;
}

char *find_char( char const *source, char const *chars )
{	
	while( *chars != '\0' ){
		if( *source == *chars )
			return (char *)source;
		source++;
		chars++;
	}
	return NULL;
}