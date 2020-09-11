#include <stdio.h>
#include <stdlib.h>

char *my_strrchr( char const *str, int ch );

int main( void )
{
	char a[20] = "fdsdfgfdasdsdffgfds";
	char *p;
	
	p = a+17;
	
	printf( "%p\n", p );
	printf( "%p", my_strrchr( a, 'd' ) );
	
	return EXIT_SUCCESS;
}

char *my_strrchr( char const *str, int ch )
{
	const char *chars;
	
	chars = NULL;
	while( *str != '\0' ){
		if( *str == ch )
			chars = str;
		str++;
	}
	
	/*
	**强制转换不出现警告 
	*/
	return (char *)chars;
}
	
	