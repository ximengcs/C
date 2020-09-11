#include <stdio.h>
#include <stdlib.h>

struct my_struct{
	int num;
	struct my_struct *next;
};

int main( void )
{
	struct my_struct a = { 5, NULL };
	
	if( (a.next = malloc( sizeof( struct my_struct ) ) ) != NULL ){
		if( (a.next -> next = malloc( sizeof( struct my_struct ) ) ) != NULL ){
			if( (a.next -> next -> next = malloc( sizeof( struct my_struct ) ) ) != NULL ){
				a.next -> next -> next -> next = NULL;
				printf( "分配内存成功" );
				free( a.next -> next -> next );
				free( a.next -> next );
				free( a.next );
				return EXIT_SUCCESS;
			}
			free( a.next -> next );
		}
		free( a.next );
	}
	printf( "内存分配失败" );
	
	return EXIT_FAILURE;
}