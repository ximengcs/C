#include <stdio.h>
#include <stdlib.h>

void *my_calloc( size_t element_num, size_t element_size );

int main( void )
{
	
	return EXIT_SUCCESS;
}

void *my_calloc( size_t element_num, size_t element_size )
{
	size_t size;
	size_t *p;
	int i;
	
	/*
	** 总共需要分配的内存大小
	*/
	size = element_num * element_size;
	
	if( (p = malloc( size )) == NULL )
		return p;
	
	for( i = 0; i < size; i++ )
		*(p+i) = 0;
	
	return p;
}
	
	