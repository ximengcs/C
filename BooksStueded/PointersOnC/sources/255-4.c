#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define   SIZE   15

typedef struct NOTE{
	struct NOTE *next;
	int num;
}Note;

struct NOTE *sll_reverse( struct NOTE *first );
Note *chaintable( int n );
void show( Note *head );

int main( void )
{
	Note *p;
	
	p = chaintable( SIZE );
	show( p );
	p = sll_reverse( p );
	show( p );
	
	return EXIT_SUCCESS;
}

struct NOTE *sll_reverse( struct NOTE *first )
{
	Note *tmp;
	Note *sll;
	Note *last;
	
	/*
	** 处理开头
	*/
	sll = first->next;
	tmp = sll->next;
	sll->next = NULL;
	
	while( tmp != NULL ){
		last = sll;
		sll = tmp;
		tmp = tmp->next;
		
		sll->next = last;
	}
	
	first->next = sll;
	
	return first;
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