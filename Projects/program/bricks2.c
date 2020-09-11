#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define   MAP_LONG   40
#define   MAP_HIGH   20  
#define   THING_SIZE 5
#define   WALL       1
#define   SPACE      0
#define   SQUARE     2
#define   BALL       3
#define   SHELF      4
#define   UP         119
#define   DOWN       115
#define   LEFT       97
#define   RIGHT      100
#define   SPACE_     32

char *PATTERN_WALL   = "■";
char *PATTERN_SPACE  = "  ";
char *PATTERN_SQUARE = "★";
char *PATTERN_BALL   = "●";
char *PATTERN_SHELF  = "◆";
char PATTERN_LENTH = 2;

void start( void );
void show( void );
void test( void );
int move_ball( void );
void move_shelf( int ch );
int check( void );

int main( void )
{
	int ch;
	
	HANDLE st_output = GetStdHandle( STD_OUTPUT_HANDLE );
	
	start();  //初始化
	show();
	//if( (ch = getch()) == SPACE_ ){  //按空格开始
	//	show();
		while(1){
			ch = FALSE;
			if( kbhit() ){
				ch = getch();
			}
			if( move_ball() == -1 ){
				break;
			}
			move_shelf(ch);
			if( check() == TRUE ){ //检查过关
				printf( "通关" );
				break;
			}
		}
	//}
	
	SetConsoleActiveScreenBuffer( st_output );
	return EXIT_SUCCESS;
}

struct {
	unsigned int last_time;
	unsigned int current_time;
}times;

struct {
	int x;
	int y;
	int upright;
	int across;
}ball;

struct {
	int x;
	int y;
	int lenth;
}shelf;

static int map[ MAP_HIGH ][ MAP_LONG ];

int check( void )
{
	int i, j;
	
	for( i = 0; i < MAP_LONG; i++ )
		for( j = 0; j < MAP_HIGH; j++ )
			if( map[i][j] == SQUARE )
				return FALSE;
	return TRUE;
}

void move_shelf( int ch )
{
	if( shelf.x+shelf.lenth == MAP_LONG-1 || shelf.x-shelf.lenth == 0 )
		return;
	
	if( ch == RIGHT ){
		map[ shelf.y ][ shelf.x ] = SPACE;
		map[ shelf.y ][ shelf.x+shelf.lenth ] = SHELF;
	}
	else if( ch == LEFT ){
		map[ shelf.y ][ shelf.x ] = SPACE;
		map[ shelf.y ][ shelf.x-shelf.lenth ] = SHELF;
	}
}

int move_ball( void )
{
	times.current_time = time(NULL);
	
	if( times.current_time >= times.last_time+1 )
		times.last_time = times.current_time;
	else
		return;
	
	map[ ball.y ][ ball.x ] = SPACE;
	
	if( ball.upright == UP ){
		if( ball.across == RIGHT ){
			if( map[ ball.y ][ ball.x+1 ] == WALL ){
				ball.y -= 1;
				ball.x -= 1;
				ball.across = LEFT;
			}
			else if( map[ ball.y-1 ][ ball.x ] == WALL ){
				ball.x += 1;
				ball.y += 1;
				ball.upright = DOWN;
			}
			else if( map[ ball.y ][ ball.x+1 ] == SQUARE ){
				map[ ball.y ][ ball.x+1 ] = SPACE;
				ball.y -= 1;
				ball.x -= 1;
				ball.across = LEFT;
			}
			else if( map[ ball.y-1 ][ ball.x ] == SQUARE ){
				map[ ball.y-1 ][ ball.x ] = SPACE;
				ball.y += 1;
				ball.x += 1;
				ball.upright = DOWN;
			}
			else{
				ball.y -= 1;
				ball.x += 1;
			}
		}
		else{
			if( map[ ball.y ][ ball.x-1 ] == WALL ){
				ball.y -= 1;
				ball.x += 1;
				ball.across = LEFT;
			}
			else if( map[ ball.y-1 ][ ball.x ] == WALL ){
				ball.x -= 1;
				ball.y += 1;
				ball.upright = DOWN;
			}
			else if( map[ ball.y ][ ball.x-1 ] == SQUARE ){
				map[ ball.y ][ ball.x-1 ] = SPACE;
				ball.y -= 1;
				ball.x += 1;
				ball.across = LEFT;
			}
			else if( map[ ball.y-1 ][ ball.x ] == SQUARE ){
				map[ ball.y-1 ][ ball.x ] = SPACE;
				ball.y += 1;
				ball.x -= 1;
				ball.upright = DOWN;
			}
			else{
				ball.y -= 1;
				ball.x -= 1;
			}
		}
	}
	else{
		if( ball.across == RIGHT ){
			if( map[ ball.y ][ ball.x+1 ] == WALL ){
				ball.y += 1;
				ball.x -= 1;
				ball.across = LEFT;
			}
			else if( map[ ball.y+1 ][ ball.x ] == WALL ){
				return -1;
			}
			else if( map[ ball.y ][ ball.x+1 ] == SQUARE ){
				map[ ball.y ][ ball.x+1 ] = SPACE;
				ball.y += 1;
				ball.x -= 1;
				ball.across = LEFT;
			}
			else if( map[ ball.y+1 ][ ball.x ] == SQUARE ){
				map[ ball.y-1 ][ ball.x ] = SPACE;
				ball.y -= 1;
				ball.x += 1;
				ball.upright = UP;
			}
			else if( map[ ball.y+1 ][ ball.x ] == SHELF ){
				ball.y -= 1;
				ball.x += 1;
			}
			else if( map[ ball.y ][ ball.x+1 ] == SHELF ){
				ball.y -= 1;
				ball.x += 1;
			}
			else{
				ball.y += 1;
				ball.x += 1;
			}
		}
		else{
			if( map[ ball.y ][ ball.x-1 ] == WALL ){
				ball.y += 1;
				ball.x += 1;
				ball.across =RIGHT;
			}
			else if( map[ ball.y+1 ][ ball.x ] == WALL ){
				return -1;
			}
			else if( map[ ball.y ][ ball.x-1 ] == SQUARE ){
				map[ ball.y ][ ball.x-1 ] = SPACE;
				ball.y += 1;
				ball.x += 1;
				ball.across = RIGHT;
			}
			else if( map[ ball.y+1 ][ ball.x ] == SQUARE ){
				map[ ball.y-1 ][ ball.x ] = SPACE;
				ball.y -= 1;
				ball.x -= 1;
				ball.upright = UP;
			}
			else{
				ball.y += 1;
				ball.x -= 1;
			}
		}
	}
	
	map[ ball.y ][ ball.x ] = BALL;
}

void test( void )
{
	int i, j;
	for( i = 0; i < MAP_HIGH; i++ ){
		for( j = 0; j < MAP_LONG; j++ )
			printf( "%2d", map[i][j] );
			putchar( '\n' );
	}
}

void start( void )
{
	int i, j;
	
	/*
	** 初始化地图
	*/
	for( i = 0; i < MAP_HIGH; i++ ){
		for( j = 0; j < MAP_LONG; j++ ){
			if( i == 0 || i == MAP_HIGH-1 || j == 0 || j == MAP_LONG-1 )
				map[i][j] = WALL;
			else if( i <= 6 )
				map[i][j] = SQUARE;
			else
				map[i][j] = SPACE;
		}
	}
	/*
	** 初始化板
	*/
	shelf.x = MAP_LONG/2-1;
	shelf.y = MAP_HIGH-2;
	shelf.lenth = 4;
	map[ shelf.y ][ shelf.x ] = SHELF;
	map[ shelf.y ][ shelf.x+1 ] = SHELF;
	map[ shelf.y ][ shelf.x+2 ] = SHELF;
	map[ shelf.y ][ shelf.x+3 ] = SHELF;
	/*
	** 初始化球
	*/
	ball.x = MAP_LONG/2;
	ball.y = MAP_HIGH-3;
	ball.upright = UP;
	ball.across = RIGHT;
	map[ ball.y ][ ball.x ] = BALL;
	/*
	** 初始化时间
	*/
	times.last_time = time(NULL);
}

/**********************************************双缓冲显示**********************************************/

static int CURRENT = -1;//用来标识当前为第几个缓冲区, 如果为-1，则没有缓冲区
static int CURRENT_ = 0;//用来标识当前缓冲区已输入多少字符
HANDLE output_one;
HANDLE output_two;
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
	CURRENT_++;
	
	if( CURRENT == 1 ){        //显示缓冲区1
		WriteConsole( output_one, chars, distance, NULL, NULL );   //将chars的内容写入缓冲区1
		if( CURRENT_ == MAP_LONG*MAP_HIGH ){
			SetConsoleActiveScreenBuffer( output_one );                //设置缓冲区1为当前可见缓冲区
			SetConsoleCursorPosition( output_one, coord );             //设置缓冲区1的光标为0，0
			CURRENT_= 0;
			CURRENT = 0;
		}
	}
	else{                     //显示缓冲区2
		WriteConsole( output_two, chars, distance, NULL, NULL );
		if( CURRENT_ == MAP_LONG*MAP_HIGH ){
			SetConsoleActiveScreenBuffer( output_two );
			SetConsoleCursorPosition( output_two, coord );
			CURRENT = 1;
			CURRENT_= 0;
		}
	}
}

void show( void )
{
	register int i, j;
	
	for( i = 0; i < MAP_HIGH; i++ ){
		for( j = 0; j < MAP_LONG; j++ ){
			if( map[i][j] == WALL )
				print( PATTERN_WALL, PATTERN_LENTH );
			else if( map[i][j] == SPACE )
				print( PATTERN_SPACE, PATTERN_LENTH );
			else if( map[i][j] == SQUARE )
				print( PATTERN_SQUARE, PATTERN_LENTH );
			else if( map[i][j] == BALL )
				print( PATTERN_BALL, PATTERN_LENTH );
			else if( map[i][j] == SHELF )
				print( PATTERN_SHELF, PATTERN_LENTH );
		}
	}
}