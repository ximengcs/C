#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>

int array_offset( int arrayinfo[], ... );

int main( void )
{
	int  num[] = { 3, 4, 6, 1, 5, -3, 3 };
	int  i;
	
	{system( "cls" );
	printf( "\n%10s%10s", "   下标   ", "  偏移量┃" );
	printf( "%10s%10s", "   下标   ", "  偏移量┃" );
	printf( "%10s%10s", "   下标   ", "  偏移量  \n" );
	i = 0;
	while( i < 30 ){
		if( (i+1) % 10 == 0 && i != 29 )
			printf( "╋" );                   
		else 
			printf( "━" );
		i++;
	}
	putchar( '\n' );
	printf( " 4,1,-3:    %4d  ┃", array_offset( num, 4, 1, -3 ) );
	printf( " 4,1, 3:    %4d  ┃", array_offset( num, 4, 1, 3 ) );
	printf( " 5,1,-3:    %4d    \n", array_offset( num, 5, 1, -3 ) );
	i = 0;
	while( i < 30 ){
		if( (i+1) % 10 == 0 && i != 29 )
			printf( "╋" );                  
		else 
			printf( "━" );
		i++;
	}
	printf( "\n 4,1,-2:    %4d  ┃", array_offset( num, 4, 1, -2 ) );
	printf( " 4,2,-3:    %4d  ┃", array_offset( num, 4, 2, -3 ) );
	printf( " 6,3, 1:    %4d    \n", array_offset( num, 6, 3, 1  ) );
	i = 0;
	while( i < 30 ){
		if( (i+1) % 10 == 0 && i != 29 )
			printf( "┻" );                    
		else 
			printf( "━" );
		i++;
	}
	}
	
	return EXIT_SUCCESS;
}

int array_offset( int arrayinfo[], ... )
{
	va_list lists;
	int temp[20];
	int low, high, loc;
	int size;
	int i;
	int j;
	
	size = *arrayinfo;
	//判断伪数组维数是否正确
	if( size < 1 || size > 10 )
		return -1;
	
	va_start( lists, size );
	
	//用va宏将下标值保存在临时数组中
	i = 0;
	while( i < size )
		temp[i++] = va_arg( lists, int );
	va_end( lists );
	
	//检查arrayinfo中的下标上限下限是否正确匹配
	i = 1;
	while( i < size*2 ){
		if( arrayinfo[i] >= arrayinfo[i+1] )
			return -1;
		i += 2;
	}
	
	//计算返回值
	j = 1;  //arrayinfo下标
	i = 0;  //temp下标
	loc = 0;
	while( i < size ){
		low  = arrayinfo[j++];
		high = arrayinfo[j++];
		
		//判断参数下标是否在范围内
		if( temp[i] < low || temp[i] > high )
			return -1;
		
		if( i == 0 )
			loc = temp[i] - low;
		else
			loc = loc * (high - low + 1) + temp[i] - low;
		i++;
	}
	
	return loc;
}
		
		
		
	
	
	
	
	

