#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   SIZE   101

char SIGNS[] = "the";
char SPACE[] = " \n\f\r\v\t";

int main( void )
{
	int  count;
	char ch[SIZE];
	char *chars;
	
	count = 0;
	while( gets(ch) != NULL ){
		for( chars = strtok( ch, SPACE ); chars != NULL;
			 chars = strtok( NULL, SPACE ) ){
				if( strcmp( chars, SIGNS ) == 0 )
					count++;
		}
	}
	
	printf( "%s出现的次数: %d\n", SIGNS, count );
	
	return EXIT_SUCCESS;
}
		