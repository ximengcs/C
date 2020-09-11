#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "simon.h"
#define   TRUE         1
#define   FALSE        0
#define   NUL          -1
#define   SNAKE_HEAD   "囧"
#define   SNAKE_SHAPE  "●"  //●
#define   FOOD         "★"
#define   WALL         "■"
#define   SPACE        "  "
#define   SIZE         20
#define   UP           119
#define   DOWN         115
#define   LEFT         97
#define   RIGHT        100

typedef struct SNAKE{
	int x;
	int y;
	int last_state;
	struct SNAKE *next;
}Snake;

static char *map[SIZE][SIZE];
static Snake snake_head;
static Snake food;

void start();
void show( void );
int move( int value, Snake *snake_head, Snake *food );
void add_snake( Snake *snake_head, Snake *food );
void restart( Snake *snake_head, Snake *food );
void test( Snake *snake_head, Snake *food );
void menu( void );

int main( void )
{
	int ch;
	int o;
	int code;
	int time;
	HANDLE handle;
	COORD  coord = { 0, 0 };
	handle = GetStdHandle( STD_OUTPUT_HANDLE );
	
	time = 150;
	while(1){
		ch = RIGHT;
		system( "cls" );
		menu();
		while( (code = getch()) < 'a' && code > 'c' )
			;
		
		if( code == 'a' ){
			start();
			add_snake( &snake_head, &food );
			SetConsoleCursorPosition( handle, coord );
			show();
			while(1){
				if( kbhit() != 0 )
					if( (ch = getch()) == UP || ch == DOWN || ch == LEFT || ch == RIGHT )
						;
					else
						ch = snake_head.last_state;
				/*
				** 如果吃到食物
				*/
				if( (o = move( ch, &snake_head, &food )) != FALSE ){
					if( o == TRUE )
						add_snake( &snake_head, &food );
					else
						break;
				}
				restart( &snake_head, &food ); // 重新放置
				Sleep(time);
				SetConsoleCursorPosition( handle, coord );
				show();
			}
			printf( "游戏结束，3秒后回到主菜单" );
			Sleep(3000);
		}
		else if( code == 'b' ){
			printf( "设置速度: 请输入蛇移动的速度(0-500):" );
			scanf( "%d", &time );
			time = 500 - time;
		}
		else if( code == 'c' )
			break;
	}
	
	return EXIT_SUCCESS;
}
//检查bug
void test( Snake *snake_head, Snake *food )
{
	Snake *current;
	
	current = snake_head;
	while( current != NULL ){
		printf( "[ %p : %d %d %p ]\n", current, current->x, current->y, current->next );
		current = current->next;
	}
}
/*
** 蛇吃到食物时体长加1,并重新放置食物
*/
void add_snake( Snake *snake_head, Snake *food )
{
	Snake *temp;
	Snake *current;
	
	srand(time(NULL));
	
	/*
	** 给蛇分配内存
	*/
	if( (temp = malloc( sizeof(Snake) ) ) == NULL )
		exit(0);
	*temp = *snake_head;
	snake_head->x = food->x;
	snake_head->y = food->y;
	snake_head->next = temp;
	
	/*
	** 如果该地方可以放置食物，则return
	*/
	while(1){
		food->x = rand()%(SIZE-2)+1;
		food->y = rand()%(SIZE-2)+1;
		/*
		** 检查是否与蛇身体重复,不重复时函数返回
		*/
		current = snake_head;
		while( current != NULL ){
			if( food->x == current->x && food->y == current->y )
				break;
			current = current->next;
		}
		
		if( current == NULL ){
			food->next = NULL;
			return;
		}
	}
}
/*
** 如果吃到食物返回真
*/
int move( int value, Snake *snake_head, Snake *food )
{
	Snake *current;
	Snake *last;
	Snake  temp;
	Snake  temp_last;
	int x, y;
	
	last = snake_head;
	current = snake_head->next;
	
	/*
	** 如果蛇下一步能吃到食物，则返回true,如果碰到墙壁或自身,则返回NUL
	*/
	if( value == UP ){
		if( snake_head->last_state == DOWN )
			value = DOWN;
	}
	else if( value == DOWN ){
		if( snake_head->last_state == UP )
			value = UP;
	}
	else if( value == LEFT ){
		if( snake_head->last_state == RIGHT )
			value = RIGHT;
	}
	else if( value == RIGHT ){
		if( snake_head->last_state == LEFT )
			value = LEFT;
	}
	
	if( value == UP ){
		if( food->x == snake_head->x && food->y == snake_head->y-1 )
			return TRUE;
		if( snake_head->y-1 == 0 )
			return NUL;
		//自身
		x = snake_head->x;
		y = snake_head->y-1;
		while( current != NULL ){
			if( current->x == x && current->y == y )
				return NUL;
			current = current->next;
		}
	}
	else if( value == DOWN ){
		if( food->x == snake_head->x && food->y == snake_head->y+1 )
			return TRUE;
		if( snake_head->y+1 == SIZE-1 )
			return NUL;
		x = snake_head->x;
		y = snake_head->y+1;
		while( current != NULL ){
			if( current->x == x && current->y == y )
				return NUL;
			current = current->next;
		}
	}
	else if( value == LEFT ){
		if( food->x == snake_head->x-1 && food->y == snake_head->y )
			return TRUE;
		if( snake_head->x-1 == 0 )
			return NUL;
		x = snake_head->x-1;
		y = snake_head->y;
		while( current != NULL ){
			if( current->x == x && current->y == y )
				return NUL;
			current = current->next;
		}	
	}
	else if( value == RIGHT ){
		if( food->x == snake_head->x+1 && food->y == snake_head->y )
			return TRUE;
		if( snake_head->x+1 == SIZE-1 )
			return NUL;
		x = snake_head->x+1;
		y = snake_head->y;
		while( current != NULL ){
			if( current->x == x && current->y == y )
				return NUL;
			current = current->next;
		}
	}
	
	last = snake_head;
	current = snake_head->next;
	while( current != NULL ){
		temp = *current;
		current->x = last->x;
		current->y = last->y;
		temp_last = temp;
		last = &temp_last;
		current = current->next;
	}
	
	if( value == UP ){
		snake_head->y -= 1;
		snake_head->last_state = UP;
	}
	else if( value == DOWN ){
		snake_head->y += 1;
		snake_head->last_state = DOWN;
	}
	else if( value == LEFT ){
		snake_head->x -= 1;
		snake_head->last_state = LEFT;
	}
	else if( value == RIGHT ){
		snake_head->x += 1;
		snake_head->last_state = RIGHT;
	}
	
	return FALSE;
}
/*
** 显示
*/
void show( void )
{
	register int i, j;
	
	for( i = 0; i < SIZE ; i++ ){
		for( j = 0; j < SIZE; j++ ){
			if( map[i][j] == SNAKE_HEAD )
				setcolor( 14, 0 );
			else if( map[i][j] == SNAKE_SHAPE )
				setcolor( 9, 0 );
			else if( map[i][j] == FOOD )
				setcolor( 15, 0 );
			else if( map[i][j] == WALL )
				setcolor( 10, 0 );
			else
				setcolor( 7, 0 );
			printf( "%s", map[i][j] );
		}
		putchar( '\n' );
	}
	setcolor( 7, 0 );
}
/*
** 重新布局
*/
void restart( Snake *snake_head, Snake *food )
{
	register int i, j;
	Snake *current;
	
	/*
	** 放置墙和空地
	*/
	for( i = 0; i < SIZE; i++ )
		for( j = 0; j < SIZE; j++ )
			if( i == 0 || i == SIZE-1 || j == 0 || j == SIZE-1 )
				map[i][j] = WALL;
			else
				map[i][j] = SPACE;
	/*
	** 放置蛇
	*/
	map[ snake_head->y ][ snake_head->x ] = SNAKE_HEAD;
	current = snake_head->next;
	while( current != NULL ){
		map[ current->y ][ current->x ] = SNAKE_SHAPE;
		current = current->next;
	}
	/*
	** 放置食物
	*/
	map[ food->y ][ food->x ] = FOOD;
}
/*
** 初始化地图
*/
void start()
{
	int i, j;
	
	snake_head.last_state = RIGHT;
	
	snake_head.x = 3;
	snake_head.y = 3;
	snake_head.next = NULL;

	food.x = 4;
	food.y = 3;
	food.next = NULL;

	for( i = 0; i < SIZE; i++ )
		for( j = 0; j < SIZE; j++ )
			if( i == 0 || i == SIZE-1 || j == 0 || j == SIZE-1 )
				map[i][j] = WALL;
			else
				map[i][j] = SPACE;
			
	map[ snake_head.y ][ snake_head.x ] = SNAKE_HEAD;
	map[ food.y ][ food.x ] = FOOD;
}

void menu( void )
{
	int i, j;
	system( "cls" );
	for( i = 0; i < 20; i++ )
		printf( "%s", WALL );
	putchar( '\n' );
	for( i = 0; i < 8; i++ )
		printf( "%s", WALL );
	printf( "  贪吃蛇  " );
	for( i = 0; i < 7; i++ )
		printf( "%s", WALL );
	putchar( '\n' );
	for( i = 0; i < 20; i++ )
		printf( "%s", WALL );
	putchar( '\n' );
	
	printf( "■■■■■■■ A : 开始游戏 ■■■■■■\n" );
	for( i = 0; i < 20; i++ )
		printf( "%s", WALL );
	putchar( '\n' );
	printf( "■■■■■■■ B : 设置 ■■■■■■■■\n" );
	for( i = 0; i < 20; i++ )
		printf( "%s", WALL );
	putchar( '\n' );
	printf( "■■■■■■■ C : 退出 ■■■■■■■■\n" );
	for( i = 0; i < 20; i++ )
		printf( "%s", WALL );
	putchar( '\n' );
}
	