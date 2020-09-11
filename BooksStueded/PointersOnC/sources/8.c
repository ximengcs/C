#include <stdio.h>
#include <windows.h>

int main( void )
{
	char  c;
	int   i;
	
	//获取默认标准显示缓冲区句柄
	HANDLE hOutput;
	COORD  coord = { 0, 0 };
	hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	
	//创建新的缓冲区 
	HANDLE hOutBuf = 
		CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, 
			FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, 
			CONSOLE_TEXTMODE_BUFFER, NULL );
	//设置新的缓冲区为活动显示缓冲
	SetConsoleActiveScreenBuffer( hOutBuf );
	//隐藏两个缓冲区的光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo( hOutput ); SetConsoleCursorInfo
	SetConsoleCursorInfo( hOutBuf );SetConsoleCursorPosition
	//双缓冲处理显示
	DWORDbytes = 0;
	chardata[800];

	while(1){
		for( c = 'a'; c < 'z'; c++ ){
			SetConsoleCursorPosition( hOutput, coord );
			for( i = 0; i < 800; i++ )
				printf( "%c", c );
		}
		ReadConsoleOutputCharacterA( hOutput, data, 800, coord );
		WriteConsoleOutputCharacterA( hOutBuf, data, 800, coord );
	}
	
	return 0;
}