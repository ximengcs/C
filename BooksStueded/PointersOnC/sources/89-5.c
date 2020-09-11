#include <stdio.h>
#include <stdlib.h>
#include "simon.h"

int store_bit_field( int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit );

int main( void )
{
	int     num = 0xffff;
	int  num_to = 0x123;
	int    temp;
	unsigned int  start = 13;
	unsigned int  end = 9;
	
	//scanf( "%d %d %d %d", &num, &num_to, &start, &end );
	
	show_bit( num );
	show_bit( num_to );
	temp = store_bit_field( num, num_to, start, end );
	show_bit( temp );
	printf( "%x", temp );
	
	return EXIT_SUCCESS;
}

int store_bit_field( int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit )
{
	int  mask_start, mask_end, mask_num, i, temp;
	
	i = 2;
	mask_num   = 1;
	mask_start = ending_bit;
	mask_end   = starting_bit;
	temp = 0;
	
	while( i <= mask_end ){
		mask_num *= 2;
		if( i >= mask_start )
			temp += mask_num;
		i++;
	}
	show_bit( temp );
	
	return (original_value & (~temp)) | ((value_to_store << ending_bit) & temp);
}