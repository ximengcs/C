#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define   TIME_DE 100
#define   MAP_C    22
#define   MAP_K    22
#define   UP      119
#define   DOWN    115
#define   LEFT     97
#define   RIGHT   100

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

void print( char chars[], unsigned int distance ) //chars为输出文字的数组，ditancce为数组大小
{
	createhandle();
	
	if( CURRENT = 1 ){        //显示缓冲区1
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


static char *true  = "a"; 
static char *false = " ";
//map
static char *map[MAP_C][MAP_K];
static int LAST;
static int a  = MAP_C-4, _a  = MAP_K/2,
		   b1 = MAP_C-3, _b1 = MAP_K/2-1,
		   b2 = MAP_C-3, _b2 = MAP_K/2,
		   b3 = MAP_C-3, _b3 = MAP_K/2+1,
		   c1 = MAP_C-2, _c1 = MAP_K/2-1,
		   c3 = MAP_C-2, _c3 = MAP_K/2+1;


void start_map( void );
void show_map( void );
static void make_tank( int n );
static void run( void );
int decide_tank( int value, int _value );

int main( void )
{
	int n;
	HANDLE st_output = GetStdHandle( STD_OUTPUT_HANDLE );
	
	start_map();
	run();
	SetConsoleActiveScreenBuffer( st_output );
	
	return EXIT_SUCCESS;
}

//run
static void run( void )
{
	int  towards;
	HANDLE handle;
	COORD  coord = { 0, 0 };
	
	handle = GetStdHandle( STD_OUTPUT_HANDLE );
	
	make_tank( 0 );
	system( "cls" );
	show_map();
	while( (towards = getch()) != 'q' ){
		make_tank( towards );
		SetConsoleCursorPosition( handle, coord );
		show_map();
	}
}

//start
void start_map( void )
{
	register int i, j;
	
	for( i = 0; i < MAP_C; i++ )
		for( j = 0 ; j < MAP_K; j++ )
			if( i == 0 || i == MAP_C-1 )
				map[i][j] = true;
			else if( j == 0 || j == MAP_K-1 )
				map[i][j] = true;
			else
				map[i][j] = false;
}

//showtank
void show_map( void )
{
	char chars[ MAP_C+MAP_K ];
	int i, j;
	
	for( i = 0; i < MAP_C*MAP_K; i++ )
		strcpy( chars++, *(*map+i) );
	
	print( chars, MAP_C*2+MAP_K*2 );
}

//maketank
static void make_tank( int n )
{
	if( n == 0 ){
		map[a][_a]   = true;
		map[b1][_b1] = true;
		map[b2][_b2] = true;
		map[b3][_b3] = true;
		map[c1][_c1] = true;
		map[c3][_c3] = true;
		
		LAST = UP;
	}
	else if( n == UP ){
		
		if( LAST == UP && decide_tank( b2 - 1, _b2 ) == 0 )
			return;
		
		if( LAST == UP ){
			a  -= 1;
			b1 -= 1;
			b2 -= 1;
			b3 -= 1;
			c1 -= 1;
			c3 -= 1;
		}
		else if( LAST == DOWN ){
			a  -= 2;
			_b1 -= 2; _b3 += 2;
			c1 += 2; _c1 -= 2;
			c3 += 2; _c3 += 2;
		}
		else if( LAST == LEFT ){
			a   -= 1; _a  += 1;
			b1  -= 1; _b1 -= 1;
			b3  += 1; _b3 += 1;
			_c1 -= 2;
			c3  += 2;
		}
		else if( LAST == RIGHT ){
			a   -= 1; _a  -= 1;
			b1  += 1; _b1 -= 1;
			b3  -= 1; _b3 += 1;
			c1  += 2;
			_c3 += 2;
		}
		
		start_map();
		
		
		map[a][_a]  = true;
		map[b1][_b1] = true;
		map[b2][_b2] = true;
		map[b3][_b3] = true;
		map[c1][_c1] = true;
		map[c3][_c3] = true;
			
		LAST = UP;
	}
	else if( n == DOWN ){

		if( LAST == DOWN && decide_tank( b2 + 1, _b2 ) == 0 )
			return;

		if( LAST == DOWN ){
			a  += 1;
			b1 += 1;
			b2 += 1;
			b3 += 1;
			c1 += 1;
			c3 += 1;
		}
		else if( LAST == UP ){
			a  += 2;
			_b1 += 2; _b3 -= 2;
			c1 -= 2; _c1 += 2;
			c3 -= 2; _c3 -= 2;
		}
		else if( LAST == LEFT ){
			a   += 1; _a  += 1;
			b1  -= 1; _b1 += 1;
			b3  += 1; _b3 -= 1;
			c1  -= 2;
			_c3 -= 2;
		}
		else if( LAST == RIGHT ){
			a   += 1; _a  -= 1;
			b1  += 1; _b1 += 1;
			b3  -= 1; _b3 -= 1;
			_c1 += 2;
			c3  -= 2;
		}
		
		start_map();
		
		map[a][_a]  = true;
		map[b1][_b1] = true;
		map[b2][_b2] = true;
		map[b3][_b3] = true;
		map[c1][_c1] = true;
		map[c3][_c3] = true;
			
		LAST = DOWN;
	}
	else if( n == LEFT ){
		
		if( LAST == LEFT && decide_tank( b2, _b2 - 1 ) == 0 )
			return;
		
		if( LAST == LEFT ){
			_a  -= 1;
			_b1 -= 1;
			_b2 -= 1;
			_b3 -= 1;
			_c1 -= 1;
			_c3 -= 1;
		}
		if( LAST == UP ){
			a  += 1; _a  -= 1;
			b1 += 1; _b1 += 1;
			b3 -= 1; _b3 -= 1;
			_c1 += 2;
			c3 -= 2;
		}
		else if( LAST == DOWN ){
			a   -= 1; _a  -= 1;
			b1  += 1; _b1 -= 1;
			b3  -= 1; _b3 += 1;
			c1  += 2;
			_c3 += 2;
		}
		else if( LAST == RIGHT ){
			_a  -= 2;
			b1  += 2;
			b3  -= 2;
			c1  += 2; _c1 += 2;
			c3  -= 2; _c3 += 2;
		}
		
		start_map();
		
		map[a][_a]  = true;
		map[b1][_b1] = true;
		map[b2][_b2] = true;
		map[b3][_b3] = true;
		map[c1][_c1] = true;
		map[c3][_c3] = true;
			
		LAST = LEFT;
	}
	else if( n == RIGHT ){
		
		if( LAST == RIGHT && decide_tank( b2, _b2 + 1 ) == 0 )
			return;
		
		if( LAST == RIGHT ){
			_a  += 1;
			_b1 += 1;
			_b2 += 1;
			_b3 += 1;
			_c1 += 1;
			_c3 += 1;
		}
		else if( LAST == UP ){
			a   += 1; _a  += 1;
			b1  -= 1; _b1 += 1;
			b3  += 1; _b3 -= 1;
			c1  -= 2;
			_c3 -= 2;
		}
		else if( LAST == DOWN ){
			a   -= 1; _a   += 1;
			b1  -= 1; _b1  -= 1;
			b3  += 1; _b3  += 1;
			_c1 -= 2;
			c3  += 2;
		}
		else if( LAST == LEFT ){
			_a  += 2;
			b1  -= 2; 
			b3  += 2;
			c1  -= 2; _c1 -= 2;
			c3  += 2; _c3 -= 2;
		}
		
		start_map();
		
		map[a][_a]  = true;
		map[b1][_b1] = true;
		map[b2][_b2] = true;
		map[b3][_b3] = true;
		map[c1][_c1] = true;
		map[c3][_c3] = true;
			
		LAST = RIGHT;
	}
}

//decide tank
int decide_tank( int value, int _value )
{
	if( value >= 2 && value <= MAP_C-3 && _value >= 2 && _value <= MAP_K-3 )
		return 1;
	else
		return 0;
}

