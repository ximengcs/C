#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

static HANDLE b;

int main( void )
{
	char *p = "fdssffjdhkfhsdkadsfhjadsf";
	
	static HANDLE A;
	HANDLE hOutput;
	hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	int i;
	
	/*
	** 创建屏幕缓冲区
	*/
	HANDLE hNewConsole =
		CreateConsoleScreenBuffer( GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
	/*
	** (可选项)隐藏光标
	*/
	//CONSOLE_CURSOR_INFO cci = { 1, 0 };
	//SetConsoleCurcorInfo( hNewConsole, 
	
	/*
	** 写入显示的东西
	*/
	//WriteConsole( hOutput, p, strlen(p), NULL, NULL );
	//while(1){
		WriteConsole( hNewConsole, p, strlen(p), NULL, NULL );
		
		/*
		** 激活
		*/
		SetConsoleActiveScreenBuffer( hNewConsole );
		//SetConsoleCursorPosition( hNewConsole, coord );
		system( "exit" );
		SetConsoleActiveScreenBuffer( hOutput );
		SetConsoleActiveScreenBuffer( hNewConsole );
		getchar();
		SetConsoleActiveScreenBuffer( hOutput );
		
		
	//}
	
	
	return EXIT_SUCCESS;
}