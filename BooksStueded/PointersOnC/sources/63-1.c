#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	double num;
	double temp;
	double a;
	
	a = 1;
	scanf( "%lf", &num );
	do{
		temp = a;
		a = ( a + (num/a) ) / 2;
	}
	while( temp != a );
	
	printf( "%lf", a );
	
	return EXIT_SUCCESS;
}