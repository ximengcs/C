#include <stdio.h>
#include <stdlib.h>

void set_bit( char bit_array[], unsigned bit_number );
void clear_bit( char bit_array[], unsigned bit_number );
void assign_bit( char bit_array[], unsigned bit_number, int value );
int test_bit( char bit_array[], unsigned bit_number );

int main( void )
{
	int  size;
	char array[sizeof(unsigned int)*8 + 1];
	int  bit_number;
	int  value;
	int  i;
	
	size = sizeof(unsigned int)*8;
	i = 0;
	while( i < size )
		array[i++] = '0';
	array[i] = '\0';
	
	puts( array );
	set_bit( array, 4 );
	puts( array );
	clear_bit( array, 4 );
	puts( array );
	assign_bit( array, 6 , 12.12 );
	puts( array );
	printf( "%s", (test_bit( array, 6 ) ? "真" : "假") ); 
	
	return EXIT_SUCCESS;
}

void set_bit( char bit_array[], unsigned bit_number )
{
	bit_array[ bit_number-1 ] = '1';
}

void clear_bit( char bit_array[], unsigned bit_number )
{
	bit_array[ bit_number-1 ] = '0';
}

void assign_bit( char bit_array[], unsigned bit_number, int value )
{
	bit_array[ bit_number-1 ] = value ? '1' : '0';
}

int test_bit( char bit_array[], unsigned bit_number )
{
	return (bit_array[ bit_number-1 ] - '0') ? 1 : 0;
}