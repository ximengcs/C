#include <stdio.h>
#include <stdlib.h>
#define   SIZE   100000
#define   TRUE   1
#define   FALSE  0

int main( void )
{
	char sign[SIZE];
	char *start_char;
	char *end_char;
	char *temp;
	int  i;
	int  count;
	
	temp       = sign + 2;
	start_char = sign + 2;
	end_char   = sign + SIZE-1;
	
	for( i = 0; i < SIZE; i++ ){
		if( i == 0 || i == 1 )
			*(sign + i) = TRUE;
		else if( (i+1) % 2 == 0 )
			*(sign + i) = FALSE;
		else
			*(sign + i) = TRUE;
	}
	
	count = 3;
	while( start_char < end_char ){
		temp = start_char + 2;
		while( temp < end_char ){
			if( (temp-sign+1) % (start_char-sign+1) == 0 )
				*temp = FALSE;
			temp += 2;
		}
		start_char += 2;
	}
	
	count = 0;
	for( i = 0; i < SIZE; i++ ){
		if( *(sign+i) == TRUE )
			count++;
		if( (i+1) % 1000 == 0 ){
			printf( "%5d", count );
			count = 0;
		}
	}
		
	return EXIT_SUCCESS;
}