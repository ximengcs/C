#include <stdio.h>
#include <stdlib.h>

char *my_strnchr( char const *str, int ch, int which );

int main( void )
{
	char a[20] = "abcdabcdabcdabcd";
	char *p;
	
	p = a+9;
	
	printf( "%p\n", p );
	printf( "%p\n", my_strnchr( a, 'b', 3 ) );
	
	return EXIT_SUCCESS;
}

char *my_strnchr( char const *str, int ch, int which )
{
	/*
	**因为参数中str指向的值不能改变所以要声明一个const的指针
	*/
	int  times;
	const char *chars;
	
	times = 0;
	chars = NULL;
	while( *str != '\0' && times != which ){
		if( *str == ch ){
			times++;
			chars = str;
		}
		str++;
	}
	
	return (char *)chars;
}
	