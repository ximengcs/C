#include <stdio.h>
#include <stdlib.h>
#define   INPUT 1000

int main( void )
{
	char characters[INPUT];
	char checksum;
	int c;
	
	checksum = -1;
	while( (c = getchar()) != EOF ){
		putchar(c);
		checksum += c;
	}
	
	printf( "%d\n", checksum );
	return EXIT_SUCCESS;
}