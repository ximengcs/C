#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define   SIZE   10
#define   TRUE   1
#define   FALSE  0

typedef struct NOTE{
	struct NOTE *next;
	struct NOTE *last;
	int num;
}Note;

void show( Note *head );    //显示双向链表
Note *chaintable( int n );  //创建有n个有效节点的双向链表
int dll_remove( struct NOTE *rootp, struct NOTE *note ); //删除第二个参数的节点

int main( void )
{
	Note *p;
	
	p = chaintable( SIZE );
	
	show( p );
	
	if( dll_remove( p, p->next->next ) == TRUE ){
		printf( "删除成功!\n" );
		show( p );
	}
	else
		printf( "删除失败" );
	
	return EXIT_SUCCESS;
}

int dll_remove( struct NOTE *rootp, struct NOTE *note )
{
	Note *current;
	Note *last;
	
	/*
	** 如果待删除的节点为头节点，则返回false
	*/
	if( rootp == note )
		return FALSE;
	
	last = rootp;
	current = rootp->next;
	
	while( current != NULL ){
		if( current == note ){
			last->next = current->next;
			current->next->last = last;
			
			free( current );
			return TRUE;
		}
		last = current;
		current = current->next;
	}
	
	return FALSE;
}
	
	
void show( Note *head )
{
	printf( "头节点地址为:%p 共有%2d个有效节点 头节点指向%p\n", head, head->num, head->next );
	head = head->next;
	while( head != NULL ){
		printf( "[current:%p next:%p last:%p %2d ]\n", head, head->next, head->last, head->num );
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
	head -> last = NULL;
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
		tmp -> last = p;
		tmp -> num = rand()%SIZE+1;
		
		p -> next = tmp;
		
		p = p->next;
		
		head -> num ++;
		
		i++;
	}
	
	return head;
}