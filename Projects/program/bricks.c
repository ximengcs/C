#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "simon.h"
#define   MAP_LONG   20
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
#define   SPACE_     97
#define   SQUARE_N   6*20
#define   SPEED      6

char *PATTERN_WALL   = "■";
char *PATTERN_SPACE  = "  ";
char *PATTERN_SQUARE = "■";
char *PATTERN_BALL   = "■";
char *PATTERN_SHELF  = "■";
char PATTERN_LENTH = 2;

void start( void );
void show( void );
int move_ball( void );
void move_shelf( int ch );
int check( void );
void menu( void );

int main( void )
{
	int ch;
	HANDLE st_output = GetStdHandle( STD_OUTPUT_HANDLE );
	COORD  coord = { 0, 0 };

	while(1){
		system( "cls" );
		menu();
		start();  //初始化
		if( (ch = getch()) == SPACE_ ){ 
			while(1){
				if( kbhit() ){
					ch = getch();
					move_shelf(ch);
				}
				if( move_ball() == -1 ){
					break;
				}
				if( check() == TRUE ){ //检查过关
					printf( "通关" );
					break;
				}
				SetConsoleCursorPosition( st_output, coord );
				show();
			}
		}
		else if( ch == 'b' )
			break;
	}
	system( "cls" );
	
	return EXIT_SUCCESS;
}

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
static int CHECK = 1;

int check( void )
{
	if( CHECK == SQUARE_N ){
		return TRUE;
	}
	else
		return FALSE;
}

void move_shelf( int ch )
{
	if( ch == RIGHT ){
		if( shelf.x+shelf.lenth == MAP_LONG-1 )
			return;
		map[ shelf.y ][ shelf.x ] = SPACE;
		map[ shelf.y ][ shelf.x+shelf.lenth ] = SHELF;
		shelf.x += 1;
	}
	else if( ch == LEFT ){
		if( shelf.x-1 == 0 )
			return;
		map[ shelf.y ][ shelf.x+shelf.lenth-1 ] = SPACE;
		map[ shelf.y ][ shelf.x-1 ] = SHELF;
		shelf.x -= 1;
	}
}

int move_ball( void )
{
	map[ ball.y ][ ball.x ] = SPACE;
	Sleep(100);
	
	if( ball.upright == UP ){
		if( ball.across == RIGHT ){
			if( map[ ball.y ][ ball.x+1 ] == WALL )
				ball.across = LEFT;
			else if( map[ ball.y-1 ][ ball.x ] == WALL )
				ball.upright = DOWN;
			else if( map[ ball.y ][ ball.x+1 ] == SQUARE ){
				map[ ball.y ][ ball.x+1 ] = SPACE;
				CHECK++;
				ball.across = LEFT;
			}
			else if( map[ ball.y-1 ][ ball.x ] == SQUARE ){
				map[ ball.y-1 ][ ball.x ] = SPACE;
				CHECK++;
				ball.upright = DOWN;
			}
			else{
				ball.y -= 1;
				ball.x += 1;
			}
		}
		else{
			if( map[ ball.y ][ ball.x-1 ] == WALL )
				ball.across = RIGHT;
			else if( map[ ball.y-1 ][ ball.x ] == WALL )
				ball.upright = DOWN;
			else if( map[ ball.y ][ ball.x-1 ] == SQUARE ){
				map[ ball.y ][ ball.x-1 ] = SPACE;
				CHECK++;
				ball.across = RIGHT;
			}
			else if( map[ ball.y-1 ][ ball.x ] == SQUARE ){
				map[ ball.y-1 ][ ball.x ] = SPACE;
				CHECK++;
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
			if( map[ ball.y ][ ball.x+1 ] == WALL )
				ball.across = LEFT;
			else if( map[ ball.y+1 ][ ball.x ] == WALL )
				return -1;
			else if( map[ ball.y ][ ball.x+1 ] == SQUARE ){
				map[ ball.y ][ ball.x+1 ] = SPACE;
				CHECK++;
				ball.across = LEFT;
			}
			else if( map[ ball.y+1 ][ ball.x ] == SQUARE ){
				map[ ball.y+1 ][ ball.x ] = SPACE;
				CHECK++;
				ball.upright = UP;
			}
			else if( map[ ball.y+1 ][ ball.x ] == SHELF ){
				ball.upright = UP;
			}
			else{
				ball.y += 1;
				ball.x += 1;
			}
		}
		else{
			if( map[ ball.y ][ ball.x-1 ] == WALL )
				ball.across =RIGHT;
			else if( map[ ball.y+1 ][ ball.x ] == WALL )
				return -1;
			else if( map[ ball.y ][ ball.x-1 ] == SQUARE ){
				map[ ball.y ][ ball.x-1 ] = SPACE;
				CHECK++;
				ball.across = RIGHT;
			}
			else if( map[ ball.y+1 ][ ball.x ] == SQUARE ){
				map[ ball.y-1 ][ ball.x ] = SPACE;
				CHECK++;
				ball.upright = UP;
			}
			else if( map[ ball.y+1 ][ ball.x ] == SHELF ){
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
	
	CHECK = 1;
}

void show( void )
{
	register int i, j;
	
	for( i = 0; i < MAP_HIGH; i++ ){
		for( j = 0; j < MAP_LONG; j++ ){
			if( map[i][j] == WALL ){
				setcolor( 9, 0 );
				printf( PATTERN_WALL );
			}
			else if( map[i][j] == SPACE )
				printf( PATTERN_SPACE );
			else if( map[i][j] == SQUARE ){
				setcolor( 10, 0 );
				printf( PATTERN_SQUARE );
			}
			else if( map[i][j] == BALL ){
				setcolor( 14, 0 );
				printf( PATTERN_BALL );
			}
			else if( map[i][j] == SHELF ){
				setcolor( 12, 0 );
				printf( PATTERN_SHELF );
			}
		}
		putchar( '\n' );
	}
	setcolor( 7, 0 );
}

void menu( void )
{
	int i, j;
	for( i = 0; i < 2; i++ ){
		for( j = 0; j < MAP_LONG; j++ )
			printf( "■" );
		putchar( '\n' );
	}
	
	printf( "■■■■■■■■ 打砖块 ■■■■■■■■\n" );
	printf( "■■■■■■■■■■■■■■■■■■■■\n" );
	printf( "■■■■■■ A ■ 开始游戏  ■■■■■■\n" );
	printf( "■■■■■■■■■■■■■■■■■■■■\n" );
	printf( "■■■■■■ B ■ 退出游戏  ■■■■■■\n" );
	
	for( i = 0; i < 2; i++ ){
		for( j = 0; j < MAP_LONG; j++ )
			printf( "■" );
		putchar( '\n' );
	}
}