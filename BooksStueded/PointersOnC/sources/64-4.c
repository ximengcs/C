#include <stdio.h>
#include <stdlib.h>
#define   LONG 100

void copy_n( char [], char [], int );

int main( void )
{
	char dst[LONG];
	char src[LONG];
	int  n;
	
	gets( src );
	scanf( "%d" ,&n );
	
	copy_n( dst, src, n );
	
	puts( dst );
	
	return EXIT_SUCCESS;
}

void copy_n( char dst[], char src[], int n )
{
	int i;
	
	i = 0;
	while( i < n ){
		if( *src != '\0' ){
			*dst = *src;
			dst++;
			src++;
		}
		else if( *src == '\0' ){
			*dst = '\0';
			dst++;
		}
		i++;
	}
	*dst = '\0';
}
	
	