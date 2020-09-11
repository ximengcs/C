#include <stdio.h>
#include <stdlib.h>

char *my_chars( void );

int main( void )
{
	char *str;
	
	str = my_chars();
	
	printf( "size: %d\n", *str++ );
	
	while( *str != '\0' )
		putchar( *str++ );
	
	return EXIT_SUCCESS;
}

char *my_chars( void )
{
	char *tmp;
	char *new;
	int ch;
	
	new = NULL;
	if( scanf( "%d", &ch ) == 1 && ch > 0 ){
		if( (tmp = new = malloc( ch * sizeof(int) ) ) == NULL )
				return new;
		*tmp++ = ch;
		while( (ch = getchar()) != EOF )
				*tmp++ = ch;
		*tmp = '\0';
	}
	
	return new;
}