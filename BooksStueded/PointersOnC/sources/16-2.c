#include <stdio.h>
#include <stdlib.h>
#define   MAXLINE 1000
#define   NUMBER  0

void get( char [], int max );

int main( void )
{
	char line[MAXLINE];
	int n, a;
	
	n = NUMBER;
	a = 1;
	get( line, MAXLINE );
	while( line[n] != '\0' ){
		if( n == 0 )
			printf( "%2d:", a++);
		else if( line[n] == '\n' )
			printf( "\n%2d:", a++);
		else
			putchar( line[n] );
		
		n++;
	}
	
	return EXIT_SUCCESS;
}

void get( char line[], int max )
{
	int c;
	
	while( (c = getchar()) != EOF ){
		*line = c;
		line++;
	}
	*line = '\0';
}