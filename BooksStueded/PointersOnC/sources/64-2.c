#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int num, temp;
	
	num  = 1;
	printf( "1 " );
	while( num <= 100 ){
		temp = 2;
		while( temp < num ){
			if( num % temp == 0 )
				break;
			else if( temp == num-1 )
				printf( "%d ", num );
			temp ++;
		}
		num ++;
	}
	
	return EXIT_SUCCESS;
}