#include <stdlib.h>
#include <stdio.h>
#define   SIZE   100

char *my_string( void );

int main( void )
{
	char *str;
	
	if( (str = my_string()) != NULL )
		puts( str );
	else
		puts( "NULL" );
	
	return EXIT_SUCCESS;
}

char *my_string( void )
{
	char *new;
	char count;
	int  ch;
	int  size;
	
	if( (new = malloc( SIZE * sizeof( char ) )) == NULL )
		return new;
	
	size  = SIZE;
	count = 0;
	while( (ch = getchar()) != EOF ){
		
		if( count > size ){
			size += SIZE;
			if( (new = realloc( new, size * sizeof(char) ) ) == NULL )
				return new;
		}
		*(new+count) = ch;
		count++;
	}
	*(new+count) = '\0';
	
	if( count < size )
		if( (new = realloc( new, (count+1)*sizeof(char) ) ) == NULL )
			return new;
	return new;
}