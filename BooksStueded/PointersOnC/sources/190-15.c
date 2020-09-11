#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   SIZE   100

void dollars( char *dest, char const *src );

int main( void )
{
	char dollars_from[SIZE];
	char dollars_to[SIZE];
	
	gets( dollars_from );
	dollars( dollars_to, dollars_from );
	puts( dollars_to );
	
	return EXIT_SUCCESS;
}

void dollars( char *dest, char const *src )
{
	size_t src_long;
	int i;
	
	*dest++ = '$';
	
	src_long = strlen( src );
	
	if( src_long < 3 ){
		i = 0;
		*dest++ = '0';
		*dest++ = '.';
		if( src_long == 1 || src_long == 0 )
			*dest++ = '0';
		else
			*dest++ = *(src+src_long-2);
		
		if( src_long == 0 )
			*dest++ = '0';
		else
			*dest++ = *(src+src_long-1);
		*dest = '\0';
		return;
	}
	else{
		i = 0;
		while( *(src+i) != '\0' ){
			*dest++ = *(src+i);
			i++;
			src_long--;
			if( (src_long-2) % 3 == 0 && src_long > 2 )
				*dest++ = ',';
			if( src_long == 2 )
				*dest++ = '.';
		}
		*dest = '\0';
	}
}