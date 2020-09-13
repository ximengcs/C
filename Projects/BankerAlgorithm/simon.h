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

//设置颜色
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

//隐藏光标
void hide_console(void) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { 1, 0 };
	SetConsoleCursorInfo( console, &cci );
}

//显示光标
void show_console(void) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { 1, 1 };
	SetConsoleCursorInfo( console, &cci );
}

void set_console_size(int length, int kidth) {
	char result[] = "mode con: cols=    lines=   ";
	if( length < 10 ) {
		result[15] = length+48;
	} else if( length < 100 ) {
		result[15] = (length)/10+48;
		result[16] = (length)%10+48;
	} else if( length < 1000 ) {
		result[15] = (length)/100+48;
		result[16] = ((length)%100)/10+48;
		result[17] = (length)%10+48;
	}
	if( kidth < 10 ) {
		result[25] = kidth+48;
	} else if( kidth < 100 ) {
		result[25] = (kidth)/10+48;
		result[26] = (kidth)%10+48;
	} else if( kidth < 1000 ) {
		result[25] = (kidth)/100+48;
		result[26] = ((kidth)%100)/10+48;
		result[27] = (kidth)%10+48;
	}
	system(result);
}

#endif