#include <stdio.h>
#include <stdlib.h>
#define   SIZE   1000

int del_substr( char *str, char const *substr );

int main( void )
{
	char chars_one[SIZE] = "ABCDEFGABCDEFG";
	char chars_two[SIZE];
	int  code;
	
	//gets( chars_one );
	gets( chars_two );
	code = del_substr( chars_one, chars_two );
	printf( "(%d) (%s)", code, chars_one );
	
	return EXIT_SUCCESS;
}

int del_substr( char *str, char const *substr )
{
	char *from;
	char *to;
	char *temp_start;
	char *temp_end;
	char *p;
	
	temp_start = NULL;
	temp_end = NULL;
	to = str;
	while( *to != '\0' ){
		p = to;
		from = (char *)substr;
		while( *to++ == *from++ ){
			if( *from == '\0' ){
				temp_start = p;
				temp_end = to;
				break;
			}
		}
		if( temp_start != NULL )
			break;
	}
	
	if( temp_start == NULL )
		return 0;
	else{
		while( *temp_end != '\0' )
			*temp_start++ = *temp_end++;
		*temp_start = '\0';
		return 1;
	}
}
		