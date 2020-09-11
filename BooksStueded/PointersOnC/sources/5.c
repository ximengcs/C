#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   TRUE   1
#define   FALSE  0

typedef struct WORD{
	char *word;
	struct WORD *next;
}Word;

typedef struct COLUMN{
	char index;
	struct COLUMN *next;
	struct WORD *each;
}Column;
	
int insert( Column **list, char *word );
	
int main( void )
{
	Column list = { 'a'-1, NULL, NULL };
	
	
	return EXIT_SUCCESS;
}