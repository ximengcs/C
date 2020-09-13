#pragma once
#include <string.h>
#include <windows.h>
#ifndef   BIT
#define   BIT   unsigned int
void show_bit( BIT num )             //作用：显示BIT类型的二进制码
{
	unsigned int size;
	int   i;
	size = sizeof( BIT ) * 8;
	BIT   ch[size];
	
	i = size - 1;
	while( i >= 0 )
		if( num != 0 ){
			ch[i--] = num%2;
			num /= 2;
		}
		else
			ch[i--] = 0;
	
	i = 0;
	while( i < size ){
		printf( "%d", ch[i] );
		i++;
	}
	putchar( '\n' );
}

void ziku( char ZIKU[100][20] )           //作用将ZIKU数组初始化为英文1-100
{
	int  i, decade, the_unit;
	
	for( i = 0; i < 100; i++ ){
		
		decade   = ((i+1)/10)%10;     //十位
		the_unit = (i+1)%10;          //个位
		
		switch( decade ){
			case 0: {
				if( the_unit == 0 ){
					strcpy( ZIKU[i], "HUNDRED" );
					break;
				}
				else{
					strcpy( ZIKU[i++], "ONE" );
					strcpy( ZIKU[i++], "TWO" );
					strcpy( ZIKU[i++], "THREE" );
					strcpy( ZIKU[i++], "FOUR" );
					strcpy( ZIKU[i++], "FIVE" );
					strcpy( ZIKU[i++], "SIX" );
					strcpy( ZIKU[i++], "SEVEN" );
					strcpy( ZIKU[i++], "EIGHT" );
					strcpy( ZIKU[i],   "NINE" );
					break;
				}
			}
			case 1: {
				strcpy( ZIKU[i++], "TEN" );
				strcpy( ZIKU[i++], "ELEVEN" );
				strcpy( ZIKU[i++], "TWELVE" );
				strcpy( ZIKU[i++], "THIRTEEN" );
				strcpy( ZIKU[i++], "FORTEEN" );
				strcpy( ZIKU[i++], "FIFTEEN" );
				strcpy( ZIKU[i++], "SIXTEEN" );
				strcpy( ZIKU[i++], "SEVENTEEN" );
				strcpy( ZIKU[i++], "EIGHTEEN" );
				strcpy( ZIKU[i],   "NINTEEN" );
				break;
			}
			case 2:{
				if( the_unit == 0 ){
					strcpy( ZIKU[i], "TWENTY" );
					break;
				}
				else{
					strcpy( ZIKU[i], ZIKU[19] );
					strcat( ZIKU[i], "-" );
					strcat( ZIKU[i], ZIKU[ the_unit-1 ] );
					break;
				}
			}
			case 3:{
				if( the_unit == 0 ){
					strcpy( ZIKU[i], "THIRTY" );
					break;
				}
				else{
					strcpy( ZIKU[i], ZIKU[29] );
					strcat( ZIKU[i], "-" );
					strcat( ZIKU[i], ZIKU[ the_unit-1 ] );
					break;
				}
			}
			case 4:{
				if( the_unit == 0 ){
					strcpy( ZIKU[i], "FORTY" );
					break;
				}
				else{
					strcpy( ZIKU[i], ZIKU[39] );
					strcat( ZIKU[i], "-" );
					strcat( ZIKU[i], ZIKU[ the_unit-1 ] );
					break;
				}
			}
			case 5:{
				if( the_unit == 0 ){
					strcpy( ZIKU[i], "FIFTY" );
					break;
				}
				else{
					strcpy( ZIKU[i], ZIKU[49] );
					strcat( ZIKU[i], "-" );
					strcat( ZIKU[i], ZIKU[ the_unit-1 ] );
					break;
				}
			}
			case 6:{
				if( the_unit == 0 ){
					strcpy( ZIKU[i], "SISTY" );
					break;
				}
				else{
					strcpy( ZIKU[i], ZIKU[59] );
					strcat( ZIKU[i], "-" );
					strcat( ZIKU[i], ZIKU[ the_unit-1 ] );
					break;
				}
			}
			case 7:{
				if( the_unit == 0 ){
					strcpy( ZIKU[i], "SEVENTY" );
					break;
				}
				else{
					strcpy( ZIKU[i], ZIKU[69] );
					strcat( ZIKU[i], "-" );
					strcat( ZIKU[i], ZIKU[ the_unit-1 ] );
					break;
				}
			}
			case 8:{
				if( the_unit == 0 ){
					strcpy( ZIKU[i], "EIGHTY" );
					break;
				}
				else{
					strcpy( ZIKU[i], ZIKU[79] );
					strcat( ZIKU[i], "-" );
					strcat( ZIKU[i], ZIKU[ the_unit-1 ] );
					break;
				}
			}
			case 9:{
				if( the_unit == 0 ){
					strcpy( ZIKU[i], "NINTY" );
					break;
				}
				else{
					strcpy( ZIKU[i], ZIKU[89] );
					strcat( ZIKU[i], "-" );
					strcat( ZIKU[i], ZIKU[ the_unit-1 ] );
					break;
				}
			}
		}
	}
}

char *strrstr( const char *s1, const char *s2 )  //查找s2字符串在s1字符串中最后一次的位置
{
	char *last;     //最后一次的指针
	char *current;  //当前的指针
	
	last = NULL;
	
	/*
	** 如果S2不是空字符，则开始查找
	*/
	if( *s2 != '\0' ){
		/*
		** 查找s2在s1中第一次出现的位置
		*/
		current = strstr( s1, s2 );
		/*
		** 寻找下一个匹配位置
		*/
		while( current != NULL ){
			last = current;
			/*
			** LAST+1: 例(s1 = "abcdefghijkabcdefg", s2 = "bc"), 第一次查找后
			** current指向 s1+1 位置，第二次将开始位置指向 last+1 也就是 s1+2
			** (c的位置)就会继续查找
			*/
			current = strstr( last+1, s2 );
		}
	}
	
	return last;
}
	
void setcolor( unsigned short ForeColor, unsigned short BackGroundColor )
{
	HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );//获取当前窗口句柄
	SetConsoleTextAttribute( handle, ForeColor+BackGroundColor*0x10 );//设置颜色
}

//设置光标位置
void setpos( int x, int y )
{
	COORD pos;
	HANDLE handle;
	pos.X = x;
	pos.Y = y;
	handle = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleCursorPosition( handle, pos );
}
#endif