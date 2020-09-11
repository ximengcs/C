#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   NUL   '\0'
#define   SIZE   100

void deblank( char string[] );

int main( void )
{
	char string[SIZE];
	
	gets( string );
	
	deblank( string );
	
	puts( string );
	
	return EXIT_SUCCESS;
}

void deblank( char string[] )
{
	int space;
	int i;
	
	i = 0;
	space = 0;
	while( string[i] != NUL ){
		while( string[i] == ' ' ){
			space++;
			i++;
		}
		if( space > 1 ){
			*(string+i - space) = NUL;
			strcat( string, string + i  - 1 );
			i = i - space;
		}
		space = 0;
		i++;
	}
}