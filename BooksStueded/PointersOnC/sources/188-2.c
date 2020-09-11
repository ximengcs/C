#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>   // size_t类型在stddef中定义

size_t my_strlen( const char *s, int n );

int main( void )
{
	char chars[10] = { 'a', 'b', 'c', 'd', '\0', 'f', 'g', 'h', 'i', '\0' };
	
	printf( "%d", my_strlen( chars, 10 ) );
	
	return EXIT_SUCCESS;
}

size_t my_strlen( const char *s, int n )
{
	register size_t len;
	
	len = 0;
	while( len < n ){
		if( *s++ == '\0' )
			break;
		len++;
	}
	
	return len;
}