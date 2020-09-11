#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define   true  1
#define   false 0

int palindrome( char *string );

int main( void )
{
	char a[] = "Madam, I'm Adam";
	char b[] = "dsfdsaafdsasfdd";
	
	printf( "%s\n", palindrome( a ) ? "回文" : "不是回文" );
	printf( "%s",   palindrome( b ) ? "回文" : "不是回文" );
	
	return EXIT_SUCCESS;
}

int palindrome( char *string )
{
	char *end;
	
	end   = string + strlen( string )-1;
	while( string <= end ){
		if( !isalpha(*string) ){
			string++;
			continue;
		}
		if( !isalpha(*end) ){
			end--;
			continue;
		}
		if( tolower(*string) != tolower(*end) )
			return false;
		else{
			string++;
			end--;
		}
	}
	
	return true;
}
	
	