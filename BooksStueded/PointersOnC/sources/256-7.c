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
	Column *list;
	char input_word[10];
	
	list->index = 'a'-1;
	list->next = NULL;
	list->each = NULL;
	
	scanf( "%s", input_word );
	if( insert( &list, input_word ) == -1 )
		printf( "FAILURE" );
	else
		printf( "SUCCESS" );
	
	return EXIT_SUCCESS;
}

int insert( Column **list, char *word )
{
	Word * word_current;
	Word * word_last;
	Column * column_current;
	Column * column_last;
	Column * temp; //分配索引临时空间
	Word *tmp_word;//分配单词临时空间
	char ch;
	

	word_current = NULL;
	word_last = NULL;
	column_current = (*list)->next;
	column_last = *list;
	while( column_current != NULL ){
		if( *word == column_current->index ){
			word_current = column_current->each;
			break;
		}
		else if( *word > column_current->index )
			break;
		else{
			column_last = column_current;
			column_current = column_current->next;
		}
	}
	
	/*
	** 如果没有找到单词索引，则创建索引
	*/
	if( column_current == NULL ){
		if( (temp = ( Column* )malloc( sizeof( Column ) ) ) == NULL )
			return -1;
		
		temp->index = *word;
		temp->next = column_current;
		column_last->next = temp;
		temp->each = NULL;
		word_current = temp->each;
		word_last = NULL;
	}
	/*
	** 寻找该索引中是否存在该单词
	*/
	while( word_current != NULL ){
		if( strcmp( word, word_current->word ) == 0 )
			break;
		word_last = word_current;
		word_current = word_current->next;
	}
	/*
	** 如果找到该单词，返回假，否则创建，返回真
	*/
	if( word_current != NULL )
		return FALSE;
	else{
		if( (tmp_word = ( Word* )malloc( sizeof(Word) ) ) == NULL )
			return -1;
		tmp_word->word = word;
		tmp_word->next = word_current;
		if( word_last != NULL )
			word_last->next = tmp_word;

		return TRUE;
	}
}