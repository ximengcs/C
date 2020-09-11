#include <stdio.h>
#include <stdlib.h>
#define   true   1
#define   false  0

unsigned int Identity_matrix( int [10][10] );

int main( void )
{
	int chars[10][10] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
	};
	
	printf( "bool: %s", Identity_matrix( chars ) ? "true" : "false" );
	
	return EXIT_SUCCESS;
}

unsigned int Identity_matrix( int chars[10][10] )
{
	int i, j;
	
	for( i = 0; i < 10; i++ )
		for( j = 0; j < 10; j++ )
			if( i == j ){
				if( chars[i][j] != true )
					return false;
			}
			else if( chars[i][j] != false )
				return false;
	
	return true;
}