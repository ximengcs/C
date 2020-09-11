#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define   UP     119
#define   DOWN   115
#define   LEFT    97
#define   RIGHT  100
#define   TRUE     1
#define   FALSE    0
#define   NUL     -1
#define   LENTH   20
#define   HIGH    20
#define   SIZE    10  //箱子数量

static char *map[HIGH][LENTH];
static int person[2];
static int box[SIZE][2];
static int sign[SIZE][2];
static char *pattern_person = "●";//●¤◎○■
static char *pattern_box = "¤";
static char *pattern_wall = "■";
static char *pattern_change = " ";
static char *pattern_sign = "○";
static char *space = "  ";
static int person_last_state = 0;
static int box_size = 0;
static sign_ = FALSE;

int move( int c );
void show( void );
void customs( int n );
void make_person( int n );
void make_box( int n );
void make_sign( int n );
void m_box( int i );

int main( void )
{
	int ch;
	int i_box;
	
	system( "cls" );
	make_person(1);
	make_box(1);
	make_sign(1);
	customs(1);
	while(1){
		system( "cls" );
		show();
		ch = getch();
		if( ( i_box = move( ch ) ) != NUL )
			m_box( i_box );
		if( ch == 'q' )
			break;
	}
	
	return EXIT_SUCCESS;
}
/*
** 玩家移动
*/
int move( int c )
{
	int i;
	
	if( c == UP ){
		/*
		** 如果前面有箱子
		*/
		i = 0;
		while( i < box_size ){
			if( person[1] == box[i][1] )
				if( person[0]-1 == box[i][0] )
					if( person[0]-2 == 0 )
						return NUL;
			i++;
		}
		
		/*
		** 如果碰到墙壁，则不移动
		*/
		if( person[0]-1 == 0 )
			return NUL;
		else{
			/*
			** 如果”脚下“有标记
			*/
			if( sign_ == FALSE )
				map[ person[0] ][ person[1] ] = space;
			else{
				map[ person[0] ][ person[1] ] = pattern_sign;
				sign_ = FALSE;
			}
			person[0]--;
		}
		
		person_last_state = UP;
	}
	else if( c == DOWN ){
		i = 0;
		while( i < box_size ){
			if( person[1] == box[i][1] )
				if( person[0]+1 == box[i][0] )
					if( person[0]+2 == HIGH-1 )
						return NUL;
			i++;
		}
		
		
		if( person[0]+1 == HIGH-1 )
			return NUL;
		else{
			if( sign_ == FALSE )
				map[ person[0] ][ person[1] ] = space;
			else{
				map[ person[0] ][ person[1] ] = pattern_sign;
				sign_ = FALSE;
			}
			person[0]++;
		}
		
		person_last_state = DOWN;
	}
	else if( c == LEFT ){
		i = 0;
		while( i < box_size ){
			if( person[0] == box[i][0] )
				if( person[1]-1 == box[i][1] )
					if( person[1]-2 == 0 )
						return NUL;
			i++;
		}
		
		
		if( person[1]-1 == 0 )
			return NUL;
		else{
			if( sign_ == FALSE )
				map[ person[0] ][ person[1] ] = space;
			else{
				map[ person[0] ][ person[1] ] = pattern_sign;
				sign_ = FALSE;
			}
			person[1]--;
		}

		person_last_state = LEFT;
	}
	else if( c == RIGHT ){
		i = 0;
		while( i < box_size ){
			if( person[0] == box[i][0] )
				if( person[1]+1 == box[i][1] )
					if( person[1]+2 == LENTH-1 )
						return NUL;
			i++;
		}
		
		if( person[1]+1 == LENTH-1 )
			return NUL;
		else{
			if( sign_ == FALSE )
				map[ person[0] ][ person[1] ] = space;
			else{
				map[ person[0] ][ person[1] ] = pattern_sign;
				sign_ = FALSE;
			}
			person[1]++;
		}

		person_last_state = RIGHT;
	}
	
	/*
	** 移动坐标改变后的人
	*/
	map[ person[0] ][ person[1] ] = pattern_person;
	
	/*
	** 如果下一次踩到标记
	*/
	i = 0;
	while( i < box_size ){
		if( person[0] == sign[i][0] && person[1] == sign[i][1] ){
			sign_ = TRUE;
			break;
		}
		i++;
	}
	
	/*
	** 如果下一次踩到箱子
	*/
	i = 0;
	while( i < box_size ){
		if( person[0] == box[i][0] && person[1] == box[i][1] )
			return i;
		i++;
	}
	
	return NUL;
}



/*
** 移动箱子
*/
void m_box( int i )
{
	if( person_last_state == UP ){
		box[i][0]--;
		map[ box[i][0] ][ box[i][1] ] = pattern_box;
	}
	else if( person_last_state == DOWN ){
		box[i][0]++;
		map[ box[i][0] ][ box[i][1] ] = pattern_box;
	}
	else if( person_last_state == LEFT ){
		box[i][1]--;
		map[ box[i][0] ][ box[i][1] ] = pattern_box;
	}
	else if( person_last_state == RIGHT ){
		box[i][1]++;
		map[ box[i][0] ][ box[i][1] ] = pattern_box;
	}
}

/*
** 打印棋盘
*/
void show( void )
{
	register int i, j;
	
	for( i = 0; i < HIGH; i++ ){
		for( j = 0; j < LENTH; j++ )
			printf( "%s", map[i][j] );
		putchar( '\n' );
	}
}

/*
** 设置关卡地图，参数为第几关
*/
void customs( int n )
{
	int i, j;
	
	if( n == 1 ){
		/*
		** 设置围墙
		*/
		for( i = 0; i < HIGH; i++ ){
			for( j = 0; j < LENTH; j++ ){
				if( i == 0 || i == HIGH-1 || j == 0 || j == LENTH-1 )
					map[i][j] = pattern_wall;
				else
					map[i][j] = space;
			}
		}
		/*
		** 设置人的位置
		*/
		map[ person[0] ][ person[1] ] = pattern_person;
		/*
		** 设置箱子位置
		*/
		map[ box[0][0] ][ box[0][1] ] = pattern_box;
		/*
		** 设置标记位置
		*/
		map[ sign[0][0] ][ sign[0][1] ] = pattern_sign;
	}
}
	
void make_person( int n )
{
	if( n == 1 ){
		person[0] = 8;
		person[1] = 8;
	}
}

void make_box( int n )
{
	if( n == 1 ){
		box[0][0] = 5;
		box[0][1] = 5;
		box_size++;
	}
}

void make_sign( int n )
{
	if( n == 1 ){
		sign[0][0] = 7;
		sign[0][1] = 7;
	}
}