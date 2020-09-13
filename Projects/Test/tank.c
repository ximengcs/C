#include "simon.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct {
	int x;
	int y;
}Ball;

typedef struct {
	int x;
	int y;
	int direct;
}Tank;

void display(void);
void display_tank(void);
void operate(int key);
void reflesh_tank();

Tank *tank;
Ball *ball;

int main(void) {
	system("cls");
	set_console_size(100,26);
	hide_console();
	
	tank = (Tank *)malloc(sizeof(Tank));
	ball = (Ball *)malloc(sizeof(Ball));
	
	tank->x = 44;
	tank->y = 22;
	ball->x = 0;
	ball->y = 0;
	
	display();
	display_tank();
	int key;
	while(1) {
		key = getch();
		if(key == 'q')
			break;
		else
			operate(key);
	}
	
	show_console();
	set_console_size(100,26);
}

void operate(int key) {
	reflesh_tank();
	if(key == 'w' && tank->y > 2) {
		tank->y --;
	} else if(key == 's' && tank->y < 22) {
		tank->y ++;
	} else if(key == 'a' && tank->x > 4) {
		tank->x -=2;
	} else if(key == 'd' && tank->x < 94) {
		tank->x +=2;
	}
	display_tank();
}

void reflesh_tank() {
	setcolor(7,0);
								setpos(tank->x,tank->y-1);printf("　");
	setpos(tank->x-2,tank->y);printf("　");setpos(tank->x,tank->y);printf("　");setpos(tank->x+2,tank->y);printf("　");
	setpos(tank->x-2,tank->y+1);printf("　");							setpos(tank->x+2,tank->y+1);printf("　");
}

void display_tank(void) {
	setcolor(4,14);
							  setpos(tank->x,tank->y-1);printf("■");
	setpos(tank->x-2,tank->y);printf("■");setpos(tank->x,tank->y);printf("■");setpos(tank->x+2,tank->y);printf("■");
	setpos(tank->x-2,tank->y+1);printf("■");							setpos(tank->x+2,tank->y+1);printf("■");
	
	setcolor(7,0);
}

void display(void) {
	int i = 0, j = 0;
	for( i = 0; i < 25; i++ )
		for( j = 0; j < 50; j++ )
			if( i > 0 && i < 24 && (j > 0 && j < 49) )
				printf("　");
			else
				printf("■");
}