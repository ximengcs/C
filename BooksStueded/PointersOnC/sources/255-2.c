#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define   SIZE   10

typedef struct NOTE{
	struct NOTE *next;
	int num;
}Note;

Note *select( Note *head, int num );
Note *chaintable( int n );
void show( Note *head );

int main( void )
{
	Note *p;
	int num;
	
	p = chaintable( SIZE );
	show( p );
	
	printf( "输入要查找的数字:" );
	scanf( "%d", &num );
	printf( "该数的地址为:%p", select( p, num ) );
	
	return EXIT_SUCCESS;
}

Note *select( Note *head, int num )
{
	while( head != NULL ){
		if( head -> num == num )
			return head;
		head = head -> next;
	}
	return NULL;
}

void show( Note *head )
{
	printf( "头节点地址为:%p 共有%d个有效节点 \n", head, head->num );
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
