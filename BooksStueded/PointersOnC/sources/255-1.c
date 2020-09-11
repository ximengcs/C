#include <stdio.h>
#include <stdlib.h>

typedef struct NOTE{
	struct NOTE *next;
	int num;
}Note;

int count( Note * );

int main( void )
{
	Note head = { NULL, 0 };
	Note **root;
	int i, j;
	
	root = &head.next;
	j = 0;
	scanf( "%d", &i );
	while( j < i ){
		if( (*root = malloc( sizeof(Note) ) ) == NULL ){
			printf( "分配链表错误!" );
			exit( EXIT_FAILURE );
		}
		j++;
		root = &(*root)->next;
	}
	*root = NULL;

	printf( "%d", count( &head ) );
	
	return EXIT_SUCCESS;
}

int count( Note *p )
{
	int num;
	
	
	num = 0;
	while( p != NULL ){
		num++;
		p = p->next;
	}
	
	return num;
}