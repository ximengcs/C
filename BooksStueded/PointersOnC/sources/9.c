#include <stdio.h>
#include <stdlib.h>
#define   SIZE  8
#define   true  1
#define   false 0

int queen[SIZE];
int sum = 0;

void show_count( void );
void show( void );
int broke( int queen_n );
void check( int queen_n );

int main( void )
{
	check(0);
	printf( "%d", sum );
	
	return EXIT_SUCCESS;
}

void check( int queen_n )
{
	int i; //位置
	
	for( i = 0; i < SIZE; i++ ){
		queen[ queen_n ] = i;
		if( broke( queen_n ) == true ){
			if( queen_n == SIZE-1 )
				show();
				//show_count();
			else
				check( queen_n+1 );
		}
	}
}

int broke( int queen_n )
{
	int i; //从第0个开始检查
	
	i = 0;
	/*while( i < queen_n ){
		if( queen[ i ] == queen[ queen_n ] ||
			queen[ i ] + i == queen[ queen_n ] + queen_n ||
			queen[ i ] - i == queen[ queen_n ] - queen_n )
			return false;
		i++;
	}*/
	
	for( i = 0; i < queen_n; i++ ){
		if( queen[i] == queen[queen_n] || abs( queen[i]-queen[queen_n] ) == (queen_n-i) ){
			return false;
		}
	}
	
	return true;
}

void show_count( void )
{
	sum++;
}
	
void show( void )
{
	int i, j;
	
	for( i = 0; i < SIZE; i++ ){
		for( j = 0; j < SIZE; j++ )
			printf( "%s", queen[i] == j ? "●" : "□" );
		putchar( '\n' );
	}
	putchar( '\n' );
	sum++;
}
