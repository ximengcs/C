#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define   NUMBER   7

int unisprint( int ch );

int main( void )
{
	int (*fun[NUMBER])( int ) = { iscntrl, isblank, isdigit, islower, isupper, ispunct, unisprint };
	char *chars[NUMBER] = { "iscntrl", "isblank", "isdigit", "islower", "isupper", "ispunct", "noprint" };
	int count[NUMBER] = { 0 };
	int all;
	int ch;
	int i;
	
	all = 0;
	while( (ch = getchar()) != EOF ){
		i = 0;
		while( i < NUMBER ){
			if( (*fun[i])(ch) )
				count[i]++;
			i++;
		}
		all++;
	}
	
	i = 0;
	while( i < NUMBER ){
		printf( "%s : %.0f%%\n", chars[i], count[i]/(float)all*100 );
		i++;
	}
	
	return EXIT_SUCCESS;
}

int unisprint( int ch )
{
	return !isprint(ch);
}