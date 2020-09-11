#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int num[3], temp;
	int i, j;
	
	printf( "请输入三个边长:" );
	scanf( "%d %d %d", &num[0], &num[1], &num[2] );
	
	for( i = 0; i < 3; i++ )
		for( j = i + 1; j < 3; j++ )
			if( num[i] < num[j] ){
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
	
	if( num[0] == num[1] || num[0] == num[2] || num[1] == num[2] ){
		if( num[0] == num[1] && num[0] == num[2] )
			printf( "等边三角形\n" );
		else 	printf( "等腰三角形\n" );
	}
	else if( num[0]*num[0] == num[1]*num[1] + num[2]*num[2] )
		printf("直角三角形\n");
	
	return EXIT_SUCCESS;
}