#include <stdio.h>
#include <stdlib.h>
#define  max 8

int queen[max], sum = 0;

void show( void )
{
	int i, j;
	
	for( i = 0; i < max; i++ ){
		for( j = 0; j < max; j++ ){
			if( queen[i] == j )
				printf( "●" );
			else
				printf( "□" );
		}
		putchar( '\n' );
	}
	putchar( '\n' );
	
	sum++;
}

int PLACE( int n )
{
	int i;
	
	i = 0;
	while( i < n ){
		if( queen[ i ] == queen[ n ] ||
			queen[ i ] + i == queen[ n ] + n ||
			queen[ i ] - i == queen[ n ] - n )
			return 1;
		i++;
	}
	
	
	/*for( i = 0; i < n; i++ ){
		if( queen[i] == queen[n] || abs( queen[i]-queen[n] ) == (n-i) ){
			return 1;
		}
	}*/
	
	return 0;
}

void NQUEEN( int n )
{
	int i;
	
	for( i = 0; i < max; i++ ){
		queen[n] = i;
		if( PLACE(n) == 0 ){
			if( n == max-1 ){
				show();
			}
			else{
				NQUEEN(n+1);
			}
		}
	}
}

int main( void )
{
	NQUEEN(0);
	printf( "%d", sum );
	
	return 0;
}