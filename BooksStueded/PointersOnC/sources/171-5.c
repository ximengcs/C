#include <stdio.h>
#include <stdlib.h>
#define   X  3
#define   Y  2
#define   Z  4

void matrix_multiply( int *m1, int *m2, int *r, int x, int y, int z );
void show( int *num, int x, int y );

int main( void )
{
	int  ch_1[X][Y] = {
		{ 2, -6 },
		{ 3, 5  },
		{ 1, -1 }
	};
	int  ch_2[Y][Z] = {
		{ 4, -2, -4, -5 },
		{ -7, -3, 6, 7  }
	};
	int  save[X][Z];
	
	show( *ch_1, X, Y );
	puts( "+" );
	show( *ch_2, Y, Z );
	matrix_multiply( *ch_1, *ch_2, *save, X, Y, Z );
	puts( "=" );
	show( *save, X, Z );
	
	return EXIT_SUCCESS;
}

void matrix_multiply( int *m1, int *m2, int *r, int x, int y, int z )
{
	int i, j;
	int temp, k;
	
	for( i = 0; i < x; i++ ){
		for( j = 0; j < z; j++ ){
			temp = 0;
			for( k = 0; k < y; k++ )
				temp += *(m1+(i*y)+k) * *(m2+(k*z)+j);
			*r++ = temp;
		}
	}
}

void show( int *num, int x, int y )
{
	int i, j;
	
	for( i = 0; i < x; i++ ){
		for( j = 0; j < y; j++ )
			printf( "%4d ", *num++ );
		putchar( '\n' );
	}
}
	