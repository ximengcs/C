#include <windows.h>
#define   LONG    40
#define   HIGH    40

static void print( char chars[], unsigned int distance );

int main( void )
{
	char ch[ LONG*HIGH ];
	int c;
	register int i;
	HANDLE st_output = GetStdHandle( STD_OUTPUT_HANDLE );
	COORD  coord = { 0, 0 };
	
	/*c = 'a';
	while( c <= 'z' ){
		for( i = 0; i < LONG*HIGH; i++ )
			*(ch+i) = c;
		print( ch, LONG*HIGH );
		Sleep(100);
		c++;
	}
	SetConsoleActiveScreenBuffer( st_output );*/
	
	
	system( "cls" );
	c = 'a';
	while( c <= 'z' ){
		for( i = 0; i < LONG*HIGH; i++ )
			putchar( c );
		SetConsoleCursorPosition( st_output, coord );
		c++;
		Sleep(100);
	}
	
	/*c = 'a';
	while( c <= 'z' ){
		system( "cls" );
		for( i = 0; i < LONG*HIGH; i++ )
			putchar( c );
		c++;
	}*/
		
}

static int CURRENT = -1;//用来标识当前为第几个缓冲区, 如果为-1，则没有缓冲区
static HANDLE output_one;
static HANDLE output_two;
COORD  coord = { 0, 0 };  //用来回到缓冲区0,0
CONSOLE_CURSOR_INFO cci = { 1, 0 };  //设置隐藏控制台光标参数

void createhandle( void )
{
	if( CURRENT == -1 ){
		output_one = CreateConsoleScreenBuffer( GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL );	//缓冲区1
		output_two = CreateConsoleScreenBuffer( GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL ); //缓冲区2
		SetConsoleCursorInfo( output_one, &cci );//设置缓冲区1的光标不可见
		SetConsoleCursorInfo( output_two, &cci );//设置缓冲区2的光标不可见
		CURRENT = 1;
	}
}

static void print( char chars[], unsigned int distance ) //chars为输出文字的数组，ditancce为数组大小
{
	createhandle();
	
	if( CURRENT == 1 ){        //显示缓冲区1
		WriteConsole( output_one, chars, distance, NULL, NULL );   //将chars的内容写入缓冲区1
		SetConsoleActiveScreenBuffer( output_one );                //设置缓冲区1为当前可见缓冲区
		SetConsoleCursorPosition( output_one, coord );             //设置缓冲区1的光标为0，0
		CURRENT = 0;
	}
	else{                     //显示缓冲区2
		WriteConsole( output_two, chars, distance, NULL, NULL );
		SetConsoleActiveScreenBuffer( output_two );
		SetConsoleCursorPosition( output_two, coord );
		CURRENT = 1;
	}
}