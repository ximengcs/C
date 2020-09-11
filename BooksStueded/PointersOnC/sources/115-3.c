#include <stdio.h>
#include <stdlib.h>
#define   SIZE   1000

void reverse_string( char *string );

int main( void )
{
	char characters[SIZE];
	
	gets( characters );
	reverse_string( characters );
	puts( characters );
	
	return EXIT_SUCCESS;
}

void reverse_string( char *string )
{
	char *chars_end;
	char  ch;
	
	chars_end = string;
	while( *chars_end != '\0' )
		chars_end++;
	chars_end -= 1;            //指向字符串NUL字符前一个字符 
	
	while( chars_end > string ){
		ch = *chars_end;
		*chars_end = *string;
		*string = ch;
		chars_end--;
		string++;
	}
}