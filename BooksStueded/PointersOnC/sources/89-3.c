#include <stdio.h>
#include <stdlib.h>
#include "simon.h"

unsigned int reverse_bits( unsigned int value );

int main( void )
{
	unsigned int   num;
	unsigned int  temp;
	
	scanf( "%ud", &num );
	printf( "原值二进制码：" );
	show_bit( num );
	
	temp = reverse_bits( num );
	printf( "改变后值为：%u\n", temp );
	printf( "改变后二进制码为：" );show_bit( temp );
	
	return EXIT_SUCCESS;
}

unsigned int reverse_bits( unsigned int value )
{
	int i;
	unsigned int num;
	
	num = 0;
	for( i = 1; i != 0; i <<= 1 ){
		num <<= 1;
		if( value & 1 )
			num |= 1;
		value >>= 1;
	}
	
	return num;
}
	
	
	