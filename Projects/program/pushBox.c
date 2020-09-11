#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "simon.h"  //变换颜色
#define   HIGH   20
#define   LENTH  20
#define   FALSE   0
#define   TRUE    1
#define   NUL    -1
#define   SIZE   20
#define   UP    119
#define   DOWN  115
#define   LEFT   97
#define   RIGHT 100
#define   GUAN    2

struct { 
	int x;
	int y;
	int sign_state;
	int last_move;
}person;

struct boxes{
	int x;
	int y;
	int finish_state;
};

struct signs{
	int x;
	int y;
};

static char *map[HIGH][LENTH];
static struct boxes box[SIZE];
static struct signs sign[SIZE];
static int wall[HIGH][LENTH];
static char *pattern_wall   = "■";
static char *pattern_person = "♀"; 
static char *pattern_sign   = "☆";
static char *pattern_box    = "◆";
static char *pattern_finish = "★";
static char *pattern_null   = "  ";

/*
** 控制
*/
void customs( void );
void show( void );
void make_person( int n );
void make_box_sign( int n );
void make_wall( int n );
void run( int n );
int  move_person( int ch );
void move_box( int i_box );
int check( void );

/*
** 界面
*/
void view_main( void );

int main( void )
{
	HANDLE handle;
	COORD  coord_two = { 0, 3 };
	
	handle = GetStdHandle( STD_OUTPUT_HANDLE );
	
	int choice;
	int n;
	int c;
	int i_box;
	int i, j;
	
	view_main();
	while( (choice = getch()) != 'q' ){
		if( choice == 'x' ){
			n = 1;
			while( n <= GUAN ){
				system( "cls" );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				printf( "\n■ 当前模式 ■ 闯关模式 ■■■ 第%02d关 ■\n", n );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
				run(n);
				while( (c = getch()) != 'q' ){
					if( (i_box = move_person(c)) != NUL )
						move_box(i_box);
					SetConsoleCursorPosition( handle, coord_two );
					show();
					if( check() == TRUE )
						break;
				}
				if( c == 'q' )
					break;
				SetConsoleCursorPosition( handle, coord_two );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
				printf( "■■■■■■■ 恭喜过关！ ■■■■■■■" );
				printf( "\n■■■■■■ 按任意键继续.. ■■■■■■\n" );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
				for( i = 0; i < 16; i++ ){
					for( j = 0; j < 20; j++ )
						printf( "  " );
					putchar( '\n' );
				}
				getch();
				n++;
			}
			if( c != 'q' ){
				for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
				printf( "■■■■■■■ 恭喜通关！ ■■■■■■■" );
				printf( "\n■■■■■■ 按任意键继续.. ■■■■■■\n" );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
				for( i = 0; i < 16; i++ ){
					for( j = 0; j < 20; j++ )
						printf( "  " );
					putchar( '\n' );
				}
				getch();
			}
		}
		else if( choice == 'y' ){
			system( "cls" );
			for( i = 0; i < 20; i++ )
					printf( "■" );
				printf( "\n■ 当前模式 ■ 自由模式 ■■■■■■■■\n" );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
			printf( "■ 请输入关卡 ■■■■■■■■■■■■■\n" );
			for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
			while( scanf( "%d", &n ) == 1 && (n > GUAN || n < 1 ) ){
				SetConsoleCursorPosition( handle, coord_two );
				printf( "■■  输入关卡超出范围！请重新输入  ■■\n" );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				printf( "\n        \r" );
			}
			system( "cls" );
			for( i = 0; i < 20; i++ )
					printf( "■" );
				printf( "\n■ 当前模式 ■ 自由模式 ■■■ 第%02d关 ■\n", n );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
			run(n);
			while( (c = getch()) != 'q' ){
				if( (i_box = move_person(c)) != NUL )
						move_box(i_box);
					SetConsoleCursorPosition( handle, coord_two );
					show();
					if( check() == TRUE )
						break;
			}
			if( c != 'q' ){
				SetConsoleCursorPosition( handle, coord_two );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
				printf( "■■■■■■■ 恭喜过关！ ■■■■■■■" );
				printf( "\n■■■■■■ 按任意键继续.. ■■■■■■\n" );
				for( i = 0; i < 20; i++ )
					printf( "■" );
				putchar( '\n' );
				for( i = 0; i < 16; i++ ){
					for( j = 0; j < 20; j++ )
						printf( "  " );
					putchar( '\n' );
				}
				getch();
			}
		}
		system( "cls" );
		view_main();
	}

	return EXIT_SUCCESS;
}

/*
** 检查是否过关
*/
int check( void )
{
	int i;
	while( box[i].finish_state != NUL ){
		if( box[i].finish_state == FALSE )
			return FALSE;
		i++;
	}
	return TRUE;
}

/*
** 移动人
*/
int move_person( int ch )
{
	int i, j;
	
	if( ch == UP ){
		/*
		** 如果前面有箱子
		*/
		i = 0;
		while( box[i].finish_state != NUL ){
			if( person.y-1 == box[i].y && person.x == box[i].x ){
				if( wall[ person.y-2 ][ person.x ] == TRUE )
					return NUL;
				/*
				** 判断箱子后面是否还有箱子
				*/
				j = 0;
				while( box[j].finish_state != NUL ){
					if( i == j ){
						j++;
						continue;
					}
					if( person.y-2 == box[j].y && person.x == box[j].x )
						return NUL;
					j++;
				}
			}
			i++;
		}
		/*
		** 判断移动后是否超界
		*/
		if( wall[ person.y-1 ][ person.x ] == TRUE )
			return NUL;
		else{
			/*
			** 如果脚下有标记
			*/
			if( person.sign_state == TRUE ){
				map[ person.y ][ person.x ] = pattern_sign;
				person.sign_state = FALSE;
			}
			else
				map[ person.y ][ person.x ] = pattern_null;
			person.y--;
		}
		person.last_move = UP;
	}
	if( ch == DOWN ){
		/*
		** 如果前面有箱子
		*/
		i = 0;
		while( box[i].finish_state != NUL ){
			if( person.y+1 == box[i].y && person.x == box[i].x ){
				if( wall[ person.y+2 ][ person.x ] == TRUE )
					return NUL;
				/*
				** 判断箱子后面是否还有箱子
				*/
				j = 0;
				while( box[j].finish_state != NUL ){
					if( i == j ){
						j++;
						continue;
					}
					if( person.y+2 == box[j].y && person.x == box[j].x )
						return NUL;
					j++;
				}
			}
			i++;
		}
		/*
		** 判断移动后是否超界
		*/
		if( wall[ person.y+1 ][ person.x ] == TRUE )
			return NUL;
		else{
			/*
			** 如果脚下有标记
			*/
			if( person.sign_state == TRUE ){
				map[ person.y ][ person.x ] = pattern_sign;
				person.sign_state = FALSE;
			}
			else
				map[ person.y ][ person.x ] = pattern_null;
			person.y++;
		}
		person.last_move = DOWN;
	}
	if( ch == LEFT ){
		/*
		** 如果前面有箱子
		*/
		i = 0;
		while( box[i].finish_state != NUL ){
			if( person.x-1 == box[i].x && person.y == box[i].y ){
				if( wall[ person.y ][ person.x-2 ] == TRUE )
					return NUL;
				/*
				** 判断箱子后面是否还有箱子
				*/
				j = 0;
				while( box[j].finish_state != NUL ){
					if( i == j ){
						j++;
						continue;
					}
					if( person.x-2 == box[j].x && person.y == box[j].y )
						return NUL;
					j++;
				}
			}
			i++;
		}
		/*
		** 判断移动后是否超界
		*/
		if( wall[ person.y ][ person.x-1 ] == TRUE )
			return NUL;
		else{
			/*
			** 如果脚下有标记
			*/
			if( person.sign_state == TRUE ){
				map[ person.y ][ person.x ] = pattern_sign;
				person.sign_state = FALSE;
			}
			else
				map[ person.y ][ person.x ] = pattern_null;
			person.x--;
		}
		person.last_move = LEFT;
	}
	if( ch == RIGHT ){
		/*
		** 如果前面有箱子
		*/
		i = 0;
		while( box[i].finish_state != NUL ){
			if( person.x+1 == box[i].x && person.y == box[i].y ){
				if( wall[ person.y ][ person.x+2 ] == TRUE )
					return NUL;
				/*
				** 判断箱子后面是否还有箱子
				*/
				j = 0;
				while( box[j].finish_state != NUL ){
					if( i == j ){
						j++;
						continue;
					}
					if( person.x+2 == box[j].x && person.y == box[j].y )
						return NUL;
					j++;
				}
			}
			i++;
		}
		/*
		** 判断移动后是否超界
		*/
		if( wall[ person.y ][ person.x+1 ] == TRUE )
			return NUL;
		else{
			/*
			** 如果脚下有标记
			*/
			if( person.sign_state == TRUE ){
				map[ person.y ][ person.x ] = pattern_sign;
				person.sign_state = FALSE;
			}
			else
				map[ person.y ][ person.x ] = pattern_null;
			person.x++;
		}
		person.last_move = RIGHT;
	}
	/*
	** 移动坐标改变后的人;
	*/
	map[ person.y ][ person.x ] = pattern_person;
	/*
	** 如果下一次踩到标记
	*/
	i = 0;
	while( box[i].finish_state != NUL ){
		if( person.x == sign[i].x && person.y == sign[i].y ){
			person.sign_state = TRUE;
			break;
		}
		i++;
	}
	/*
	** 如果下一次踩到箱子
	*/
	i = 0;
	while( box[i].finish_state != NUL ){
		if( person.x == box[i].x && person.y == box[i].y )
			return i;
		i++;
	}
	
	return NUL;
}
/*
** 如果人推动到箱子，则移动箱子
*/

void move_box( int i_box )
{
	int i;
	
	box[i_box].finish_state = FALSE;
	if( person.last_move == UP )
		box[i_box].y--;
	else if( person.last_move == DOWN )
		box[i_box].y++;
	else if( person.last_move == LEFT )
		box[i_box].x--;
	else if( person.last_move == RIGHT )
		box[i_box].x++;
	
	i = 0;
	while( box[i].finish_state != NUL ){
		if( box[i_box].x == sign[i].x && box[i_box].y == sign[i].y ){
			box[i_box].finish_state = TRUE;
			break;
		}
		i++;
	}
	
	if( box[i_box].finish_state != TRUE )
		map[ box[i_box].y ][ box[i_box].x ] = pattern_box;
	else
		map[ box[i_box].y ][ box[i_box].x ] = pattern_finish;
}

/*
** 将箱子，人，标记放到地图中
*/
void customs( void )
{
	int i, j;
	
	/*
	** 设置墙
	*/
	for( i = 0; i < HIGH; i++ )
		for( j = 0; j < LENTH; j++ )
			if( wall[i][j] == TRUE )
				map[i][j] = pattern_wall;
			else
				map[i][j] = pattern_null;
	/*
	** 人
	*/
	map[ person.y ][ person.x ] = pattern_person;
	/*
	** 箱子和标记
	*/
	for( i = 0 ; box[i].finish_state != NUL ; i++ ){
		map[ box[i].y ][ box[i].x ] = pattern_box;
		map[ sign[i].y ][ sign[i].x ] = pattern_sign;
	}
}

/*
** 根据关卡设置人的坐标
*/
void make_person( int n )
{
	if( n == 1 ){
		person.x = 11;
		person.y = 11;
		person.sign_state = FALSE;
		person.last_move  = NUL;
	}
	else if( n == 2 ){
		person.x = 7;
		person.y = 7;
		person.sign_state = FALSE;
		person.last_move  = NUL;
	}
}
	
/*
** 设置墙
*/
void make_wall( int n )
{
	int i, j;
	
	if( n == 1 ){
		for( i = 0; i < HIGH; i++ )
			for( j = 0; j < LENTH; j++ )
					wall[i][j] = TRUE;
		wall[6][7] = FALSE;
		wall[6][8] = FALSE;
		wall[6][9] = FALSE;
		wall[6][11] = FALSE;
		wall[6][12] = FALSE;
		wall[7][7] = FALSE;
		wall[7][9] = FALSE;
		wall[7][11] = FALSE;
		wall[7][12] = FALSE;
		wall[8][7] = FALSE;
		wall[8][8] = FALSE;
		wall[8][9] = FALSE;
		wall[8][10] = FALSE;
		wall[8][11] = FALSE;
		wall[8][12] = FALSE;
		wall[9][7] = FALSE;
		wall[9][9] = FALSE;
		wall[9][11] = FALSE;
		wall[9][12] = FALSE;
		wall[10][7] = FALSE;
		wall[10][8] = FALSE;
		wall[10][9] = FALSE;
		wall[10][11] = FALSE;
		wall[10][12] = FALSE;
		wall[11][11] = FALSE;
		wall[11][12] = FALSE;
		
		/*
		** 边缘
		*/
		for( i = 5; i <= 14; i++ )
			wall[4][i] = FALSE;
		for( i = 5; i <= 13; i++ )
			wall[i][5] = FALSE;
		for( i = 5; i <= 13; i++ )
			wall[i][14] = FALSE;
		for( i = 5; i <= 13; i++ )
			wall[13][i] = FALSE;
		for( i = 6; i <= 9; i++ )
			wall[12][i] = FALSE;
	}
	else if( n == 2 ){
		for( i = 0; i < HIGH; i++ )
			for( j = 0; j < LENTH; j++ )
					wall[i][j] = TRUE;
		wall[7][7] = FALSE;
		wall[7][8] = FALSE;
		wall[7][9] = FALSE;
		wall[8][7] = FALSE;
		wall[8][8] = FALSE;
		wall[8][9] = FALSE;
		wall[9][7] = FALSE;
		wall[9][8] = FALSE;
		wall[9][9] = FALSE;
		wall[9][13] = FALSE;
		wall[10][9] = FALSE;
		wall[10][13] = FALSE;
		wall[11][9] = FALSE;
		wall[11][10] = FALSE;
		wall[11][11] = FALSE;
		wall[11][12] = FALSE;
		wall[11][13] = FALSE;
		wall[12][8] = FALSE;
		wall[12][9] = FALSE;
		wall[12][10] = FALSE;
		wall[12][12] = FALSE;
		wall[12][13] = FALSE;
		wall[13][8] = FALSE;
		wall[13][9] = FALSE;
		wall[13][10] = FALSE;
		
		for( i = 5; i <= 15; i++ )
			wall[5][i] = FALSE;
		for( i = 5; i <= 15; i++ )
			wall[15][i] = FALSE;
		for( i = 6; i <= 14; i++ )
			wall[i][5] = FALSE;
		for( i = 6; i <= 14; i++ )
			wall[i][15] = FALSE;
		for( i = 11; i <= 14; i++ )
			wall[i][6] = FALSE;
		for( i = 11; i <= 14; i++ )
			wall[6][i] = FALSE;
		for( i = 11; i <= 14; i++ )
			wall[7][i] = FALSE;
		wall[8][11] = FALSE;
		wall[9][11] = FALSE;
	}
	
}
/*
** 设置箱子和标记
*/
void make_box_sign( int n )	
{
	if( n == 1 ){
		box[0].x = 11;
		box[0].y = 7;
		box[0].finish_state = FALSE;
		box[1].x = 11;
		box[1].y = 8;
		box[1].finish_state = FALSE;
		box[2].x = 11;
		box[2].y = 9;
		box[2].finish_state = FALSE;
		box[3].finish_state = NUL;
		sign[0].x = 12;
		sign[0].y = 7;
		sign[1].x = 12;
		sign[1].y = 8;
		sign[2].x = 12;
		sign[2].y = 9;
	}
	else if( n == 2 ){
		box[0].x = 8;
		box[0].y = 8;
		box[0].finish_state = FALSE;
		box[1].x = 9;
		box[1].y = 8;
		box[1].finish_state = FALSE;
		box[2].x = 8;
		box[2].y = 9;
		box[2].finish_state = FALSE;
		box[3].finish_state = NUL;
		sign[0].x = 13;
		sign[0].y = 9;
		sign[1].x = 13;
		sign[1].y = 10;
		sign[2].x = 13;
		sign[2].y = 11;
	}
}

void view_main( void )
{
	int i;
	system( "cls" );
	for( i = 0; i < 20; i++ )
		printf( "■" );
	putchar( '\n' );
	for( i = 0; i < 8; i++ )
		printf( "■" );
	printf( " 推箱子 " );
	for( i = 0; i < 8; i++ )
		printf( "■" );
	putchar( '\n' );
	for( i = 0; i < 20; i++ )
		printf( "■" );
	putchar( '\n' );
	printf( "■    输入模式前的字母选择对应模式    ■\n" );
	for( i = 0; i < 20; i++ )
		printf( "■" );
	putchar( '\n' );
	printf( "■■■■■  X ■ 闯关模式 ■■■■■■■\n" );
	for( i = 0; i < 20; i++ )
		printf( "■" );
	putchar( '\n' );
	printf( "■■■■■  Y ■ 自由模式 ■■■■■■■\n" );
	for( i = 0; i < 20; i++ )
		printf( "■" );
	putchar( '\n' );
	printf( "■■■■■  Q ■ 退出游戏 ■■■■■■■\n" );
	for( i = 0; i < 20; i++ )
		printf( "■" );
	putchar( '\n' );
}
		
void show( void )
{
	register int i, j;
	
	for( i = 0; i < LENTH; i++ ){
		for( j = 0; j < HIGH; j++ )
			if( map[i][j] == pattern_box){
				setcolor( 10, 0 );
				printf( "%s", map[i][j] );
			}
			else if( map[i][j] == pattern_sign ){
				setcolor( 6, 0 );
				printf( "%s", map[i][j] );
			}
			else if( map[i][j] == pattern_finish ){
				setcolor( 4, 0 );
				printf( "%s", map[i][j] );
			}
			else if( map[i][j] == pattern_person ){
				setcolor( 11, 0 );
				printf( "%s", map[i][j] );
			}
			else{
				setcolor( 9, 0 );
				printf( "%s", map[i][j] );
			}
		putchar( '\n' );
	}
	setcolor( 7, 0 );
}
/*
** 运行关卡
*/
void run( int n )
{
	make_box_sign(n);
	make_wall(n);
	make_person(n);
	customs();
	show();
}
