#include <stdio.h>
#include <stdlib.h>

int gcd( int m, int n );

int main( void )
{
	int  m, n;
	
	scanf( "%d %d", &m, &n );
	printf( "%d", gcd( m, n ) );
	
	return EXIT_SUCCESS;
}

int gcd( int m, int n )
{
	int r;
	
	if( m <= 0 || n <= 0 )
		return 0;
	if( m%n == 0 )
		return n;
	if( (r = m%n) > 0 )
		gcd( n, r );
}