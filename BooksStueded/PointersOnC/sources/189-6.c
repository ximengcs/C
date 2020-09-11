#include <stdio.h>
#include <stdlib.h>

char *my_strcpy_end( char *s1, const char *s2 );

int main( void )
{
	char a[10];
	char b[10] = "fsdasdfDS";
	char *p;
	
	p = a+9;
	
	printf( "%p\n", p );
	printf( "%p\n", my_strcpy_end( a, b ) );
	puts( a );
	puts( b );
	
	return EXIT_SUCCESS;
}

char *my_strcpy_end( char *s1, const char *s2 )
{
	while( (*s1++ = *s2++) != '\0' )
		;
	return --s1;
}