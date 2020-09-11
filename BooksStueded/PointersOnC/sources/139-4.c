#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

int max_list( int n, ... );

int main( void )
{
	int n;
	
	srand( time(NULL) );
	n = max_list( 3, rand(), rand(), -1 );
	printf( "最大值:%d\n", n );
	n = max_list( 4, rand(), rand(), rand(), -1 );
	printf( "最大值:%d\n", n );
	n = max_list( 5, rand(), rand(), rand(), rand(), -1 );
	printf( "最大值:%d\n", n );
	n = max_list( 6, rand(), rand(), rand(), rand(), rand(), -1 );
	printf( "最大值:%d\n", n );
	n = max_list( 10, rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), -1 );
	printf( "最大值:%d\n", n );
	
	return EXIT_SUCCESS;
}

int max_list( int n, ... )
{
	va_list var_arg;
	int  i;
	int  max;
	
	i = 0;
	max = 0;
	va_start( var_arg, n );
	while( ( i = va_arg( var_arg, int) ) != -1 )
		if( i > max )
			max = i;
	va_end( var_arg );
	return max;
}