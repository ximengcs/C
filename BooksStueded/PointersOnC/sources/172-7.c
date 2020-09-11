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
	printf( " 4,2,-3:    %4d  ┃", array_offset( num, 4, 2, -3 ) );
	printf( " 4,1,-1:    %4d    \n", array_offset( num, 4, 1, -1 ) );
	i = 0;
	while( i < 30 ){
		if( (i+1) % 10 == 0 && i != 29 )
			printf( "╋" );                  
		else 
			printf( "━" );
		i++;
	}
	printf( "\n 5,1,-3:    %4d  ┃", array_offset( num, 5, 1, -3 ) );
	printf( " 4,3,-3:    %4d  ┃", array_offset( num, 4, 3, -3 ) );
	printf( " 5,3,-1:    %4d    \n", array_offset( num, 5, 3, -1 ) );
	i = 0;
	while( i < 30 ){
		if( (i+1) % 10 == 0 && i != 29 )
			printf( "╋" );                  
		else 
			printf( "━" );
		i++;
	}
	printf( "\n 6,1,-3:    %4d  ┃", array_offset( num, 6, 1, -3 ) );
	printf( " 4,1,-2:    %4d  ┃", array_offset( num, 4, 1, -2 ) );
	printf( " 6,5, 3:    %4d    \n", array_offset( num, 6, 5, 3 ) );
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
	int low, high, loc, low_last, high_last, loc_temp, model, model_temp;
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
	low = 0;
	high = 0;
	loc_temp = 0;
	model = 0;
	while( i < size ){
		low_last  = low;
		high_last = high;
		low  = arrayinfo[j++];
		if( i != 0 ){
			high = arrayinfo[j-2];
			j++;
		}
		else if( i == 0 )
			j++;
		
		//判断参数下标是否在范围内
		if( temp[i] < low || temp[i] > arrayinfo[j-1] )
			return -1;
		
		if( i == 0 )
			loc = temp[i] - low;
		else if( i == 1 ){
			model = high - low_last + 1;
			loc_temp = loc;
			loc = loc_temp + model * (temp[i] - low);
		}
		else{
			model_temp = loc;
			loc = loc_temp + model * (temp[i-1] - low_last + (temp[i]
					- low) * (high - low_last + 1));
			loc_temp = model_temp;
			model = high - low_last + 1;
		}
			
		i++;
	}
	return loc;
}

