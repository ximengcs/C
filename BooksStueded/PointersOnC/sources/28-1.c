#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	printf( "%d %d %d\n", increment(10), increment(0), increment(-10) );
	printf( "%d %d %d", negate(10), negate(0), negate(-10) );
	
	return EXIT_SUCCESS;
}