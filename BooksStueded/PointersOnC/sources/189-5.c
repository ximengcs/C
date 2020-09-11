#include <stdio.h>
#include <stdlib.h>

void my_strncat( char *dest, char *src, int dest_len );

int main( void )
{
	char a[10] = "adfsasd";
	char b[10] = "DSDSFAF";
	
	my_strncat( a, b, 10 );
	puts( a );
	
	return EXIT_SUCCESS;
}

void my_strncat( char *dest, char *src, int dest_len )
{
	int i;
	
	i = 0;
	while( *(dest+i) != '\0' )
		i++;
	
	while( i < dest_len-1 || *src == '\0' ){
		*(dest+i) = *src++;
		i++;
	}
}
	