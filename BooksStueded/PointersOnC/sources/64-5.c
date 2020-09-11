#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   SIZE     128
#define   DISTANCE 100

int main( void )
{
	char line[DISTANCE][SIZE];
	char temp[SIZE];
	char last[SIZE];
	int  i, max;
	
	max = 0;
	while( gets(line[max]) != NULL )
		max++;
	
	i = 0;
	while( i <= max ){
		if( strcmp( line[i], temp ) != 0 ){
			if( strcmp( temp, last ) == 0 )
				puts( temp );
			strcpy( temp, line[i] );
		}
		else if( strcmp( temp, line[i] ) == 0 )
			strcpy( last, temp );
		i++;
	}
	
	return EXIT_SUCCESS;
}
		