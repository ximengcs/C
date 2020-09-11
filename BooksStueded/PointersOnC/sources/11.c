#include <stdio.h>
#include <conio.h>
typedef struct SNAKE{
	int x;
	int y;
	struct SNAKE *next;
}Snake;

static char *map[SIZE][SIZE];
static Snake *snake_head;
static Snake *food;

void start( void )
{
	int i, j;
	

	for( i = 0; i < SIZE; i++ )
		for( j = 0; j < SIZE; j++ )
			if( i == 0 || i == SIZE-1 || j == 0 || j == SIZE-1 )
				map[i][j] = WALL;
			else
				map[i][j] = SPACE;
			
	//map[ snake_head->y ][ snake_head->x ] = SNAKE_HEAD;
	//map[ food->y ][ food->x ] = FOOD;
}

int main( void )
{
	int ch = RIGHT;
	
	snake_head->x = 3;
	snake_head->y = 3;
	snake_head->next = NULL;

	food->x = 7;
	food->y = 9;
	food->next = NULL;
	
	
	start();
	show();
	
}