#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define   SIZE   5
#define   TRUE   1
#define   FALSE  0

typedef struct NOTE{
	struct NOTE *next;
	int num;
}Note;

void show( Note *head );
Note *chaintable( int n );
int sll_remove( struct NOTE **rootp, struct NOTE *note );

int main( void )
{
	Note *p;
	Note *o;
	
	p = chaintable( SIZE );
	show( p );
	if( sll_remove( &p, p->next ) == TRUE )
		printf( "已删除" );
	else
		printf( "ERROR" );
	show( p );
	
	return EXIT_SUCCESS;
}

int sll_remove( struct NOTE **rootp, struct NOTE *note )
{
	Note *current;
	
	assert( note != NULL );
	
	while( (current = *rootp) != NULL && current != note )
		rootp = &current->next;
	
	if( current == note ){
		*rootp = current->next;
		free( current );
		return TRUE;
	}
	else
		return FALSE;
}

void show( Note *head )
{
	printf( "头节点地址为:%p 共有%d个有效节点 头节点指向%p\n", head, head->num, head->next );
	head = head->next;
	while( head != NULL ){
		printf( "%p %d \n", head, head->num );
		head = head->next;
	}
}

Note *chaintable( int n )
{
	Note *head;
	Note *p;     //遍历
	Note *tmp;   //临时
	int i;
	
	srand( time(NULL) );
	
	/*
	** 创建头指针
	*/
	if( (head = (Note *)malloc( sizeof( Note ) ) ) == NULL )
		return NULL;
	
	head -> num = 0;
	head -> next = NULL;
	
	p = head;
	
	i = 0;
	while( i < n ){
		/*
		**创建一个Note结构
		*/
		if( (tmp = ( Note * )malloc( sizeof( Note ) ) ) == NULL )
			return NULL;
		
		tmp -> next = NULL;
		tmp -> num = rand()%SIZE+1;
		
		p -> next = tmp;
		
		p = p->next;
		
		head -> num ++;
		
		i++;
	}
	
	return head;
}