#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define   MAXLINE 1000

int main( void )
{
	char characters[MAXLINE];
	char temp[MAXLINE];
	int  c;
	int  n;
	int  max;
	int  col;
	
	col = 0;
	n = 0;
	max = 0;
	while( (c = getchar()) != EOF && col < MAXLINE-1 ){
		if( c == '\n' ){
			characters[col] = '\0';
			if( n > max ){
				max = n;
				strcpy( temp, characters );
			}
			n = 0;
			col = 0;
		}
		else{
			characters[col] = c;
			col++;
			n++;
		}
	}	
	
	printf( "%2d:%s", max, temp );
	return EXIT_SUCCESS;
}