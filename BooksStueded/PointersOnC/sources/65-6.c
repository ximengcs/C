#include <stdio.h>
#include <stdlib.h>
#define   SIZE   100
#define   NUL    '\0'

int substr( char dst[], char src[], int start, int len );

int main( void )
{
	char dst[SIZE];
	char src[SIZE];
	int  start, len;
	
	gets( src );
	scanf( "%d %d", &start, &len );
	
	printf( "返回值:%d\n", substr( dst, src, start, len ) );
	puts( dst );
	
	return EXIT_SUCCESS;
}

int substr( char dst[], char src[], int start, int len )
{
	int  n, size_src;
	
	size_src = 0;
	while( src[size_src] != NUL )                     //计算src的大小
		size_src++;
	
	if( start > size_src || start < 0 || len < 0 ){   //如果偏移位置超过边界或start，len小于0
		dst[0] = NUL;                                 //则复制一个NUL，并返回0
		return 0;
	}
	
	src += start;                                     //偏移位置
	
	n = 0;
	while( *src != NUL && n < len ){
		dst[n] = *src;
		n++;
		src++;
	}
	dst[n] = NUL;
	return n;
}