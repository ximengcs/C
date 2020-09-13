#pragma once
#include "simon.h"
#include <windows.h>
#include "data.h"

#define LINECOLOR 12
#define FONDCOLOR 15
#define BACKGROUND 0
#define GREY 15
#define MENUBAKC 11

int set_line_color(void) {
	setcolor(LINECOLOR,BACKGROUND);
}

int set_font_color(void) {
	setcolor(FONDCOLOR,BACKGROUND);
}

int set_background(void) {
	setcolor(11,BACKGROUND);
}

int show_info(int mask) {
	setpos(0,0);
	int i = 0;
	int j = 0;
	for( i = 0; i < 9; i++ ){
		for( j = 0; j < 9; j++ ) {
			if( (i >=3 && i <= 5 && ( (j >= 0 && j <= 2) || (j >= 6 && j <= 8) )) || (((i>=0 && i<=2) || (i>=6 && i<=8)) && j>=3 && j<=5) )
				set_line_color();
			else
				set_font_color();
			if( state_3[i][j] == 1 )
				setcolor(10,0);
			
			if( content[i][j] == -1 )
				printf(" □");
			else
				printf("%3d",content[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	if( mask != 0 ) {
		for( i = 0; i < 9; i++ ){
			for( j = 0; j < 9; j++ ) {
				printf("%3d",state_3[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

//显示9*9
int show_3_2(void) {
	setpos(0,0);
	printf("┏━┳━┳━┓");set_background();printf("┏━┳━┳━┓");set_font_color();printf("┏━┳━┳━┓");												set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃");												set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┣━╋━╋━┫");set_background();printf("┣━╋━╋━┫");set_font_color();printf("┣━╋━╋━┫");												set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃");	                                            set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┣━╋━╋━┫");set_background();printf("┣━╋━╋━┫");set_font_color();printf("┣━╋━╋━┫");												set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃");                                             set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┗━┻━┻━┛");set_background();printf("┗━┻━┻━┛");set_font_color();printf("┗━┻━┻━┛");												set_font_color();printf("　　　　　　　　　　　　　　　\n");
	set_background();printf("┏━┳━┳━┓");set_font_color();printf("┏━┳━┳━┓");set_background();printf("┏━┳━┳━┓");set_font_color();           set_font_color();printf("　　　　　　　　　　　　　　　\n");
	set_background();printf("┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃");set_font_color();			set_font_color();printf("　　　　　　　　　　　　　　　\n");
	set_background();printf("┣━╋━╋━┫");set_font_color();printf("┣━╋━╋━┫");set_background();printf("┣━╋━╋━┫");set_font_color();           set_font_color();printf("　　　　　　　　　　　　　　　\n");
	set_background();printf("┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃");set_font_color();			set_font_color();printf("　　　　　　　　　　　　　　　\n");
	set_background();printf("┣━╋━╋━┫");set_font_color();printf("┣━╋━╋━┫");set_background();printf("┣━╋━╋━┫");set_font_color();           set_font_color();printf("　　　　　　　　　　　　　　　\n");
	set_background();printf("┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃");set_font_color();			set_font_color();printf("　　　　　　　　　　　　　　　\n");
	set_background();printf("┗━┻━┻━┛");set_font_color();printf("┗━┻━┻━┛");set_background();printf("┗━┻━┻━┛");set_font_color();           set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┏━┳━┳━┓");set_background();printf("┏━┳━┳━┓");set_font_color();printf("┏━┳━┳━┓");												set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃");                                             set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┣━╋━╋━┫");set_background();printf("┣━╋━╋━┫");set_font_color();printf("┣━╋━╋━┫");                                             set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃");                                             set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┣━╋━╋━┫");set_background();printf("┣━╋━╋━┫");set_font_color();printf("┣━╋━╋━┫");                                             set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃");                                             set_font_color();printf("　　　　　　　　　　　　　　　\n");
	printf("┗━┻━┻━┛");set_background();printf("┗━┻━┻━┛");set_font_color();printf("┗━┻━┻━┛");                                             set_font_color();printf("　　　　　　　　　　　　　　　\n");
}

//显示16*16
int show_4(void) {
	setpos(0,0);
	set_font_color();printf("┏━┳━┳━┳━┓");set_background();printf("┏━┳━┳━┳━┓");set_font_color();printf("┏━┳━┳━┳━┓");set_background();printf("┏━┳━┳━┳━┓\n");
	set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃\n");
	set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫\n");
	set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃\n");
	set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫\n");
	set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃\n");
	set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫\n");
	set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃\n");
	set_font_color();printf("┗━┻━┻━┻━┛");set_background();printf("┗━┻━┻━┻━┛");set_font_color();printf("┗━┻━┻━┻━┛");set_background();printf("┗━┻━┻━┻━┛\n");
	set_background();printf("┏━┳━┳━┳━┓");set_font_color();printf("┏━┳━┳━┳━┓");set_background();printf("┏━┳━┳━┳━┓");set_font_color();set_font_color();printf("┏━┳━┳━┳━┓\n");
	set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();set_font_color();printf("┃　┃　┃　┃　┃\n");
	set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();set_font_color();printf("┣━╋━╋━╋━┫\n");
	set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();set_font_color();printf("┃　┃　┃　┃　┃\n");
	set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();set_font_color();printf("┣━╋━╋━╋━┫\n");
	set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();set_font_color();printf("┃　┃　┃　┃　┃\n");
	set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();set_font_color();printf("┣━╋━╋━╋━┫\n");
	set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();set_font_color();printf("┃　┃　┃　┃　┃\n");
	set_background();printf("┗━┻━┻━┻━┛");set_font_color();printf("┗━┻━┻━┻━┛");set_background();printf("┗━┻━┻━┻━┛");set_font_color();set_font_color();printf("┗━┻━┻━┻━┛\n");
	set_font_color();printf("┏━┳━┳━┳━┓");set_background();printf("┏━┳━┳━┳━┓");set_font_color();printf("┏━┳━┳━┳━┓");set_background();printf("┏━┳━┳━┳━┓\n");
	set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃\n");
	set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫\n");
	set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃\n");
	set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫\n");
	set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃\n");
	set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫\n");
	set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃\n");
	set_font_color();printf("┗━┻━┻━┻━┛");set_background();printf("┗━┻━┻━┻━┛");set_font_color();printf("┗━┻━┻━┻━┛");set_background();printf("┗━┻━┻━┻━┛\n");
	set_background();printf("┏━┳━┳━┳━┓");set_font_color();printf("┏━┳━┳━┳━┓");set_background();printf("┏━┳━┳━┳━┓");set_font_color();set_font_color();printf("┏━┳━┳━┳━┓\n");
	set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();set_font_color();printf("┃　┃　┃　┃　┃\n");
	set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();set_font_color();printf("┣━╋━╋━╋━┫\n");
	set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();set_font_color();printf("┃　┃　┃　┃　┃\n");
	set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();set_font_color();printf("┣━╋━╋━╋━┫\n");
	set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();set_font_color();printf("┃　┃　┃　┃　┃\n");
	set_background();printf("┣━╋━╋━╋━┫");set_font_color();printf("┣━╋━╋━╋━┫");set_background();printf("┣━╋━╋━╋━┫");set_font_color();set_font_color();printf("┣━╋━╋━╋━┫\n");
	set_background();printf("┃　┃　┃　┃　┃");set_font_color();printf("┃　┃　┃　┃　┃");set_background();printf("┃　┃　┃　┃　┃");set_font_color();set_font_color();printf("┃　┃　┃　┃　┃\n");
	set_background();printf("┗━┻━┻━┻━┛");set_font_color();printf("┗━┻━┻━┻━┛");set_background();printf("┗━┻━┻━┻━┛");set_font_color();set_font_color();printf("┗━┻━┻━┻━┛\n");
}

//刷新16*16
int reflesh_num_4(void) {
	int i,j;
	setpos(0,0);
	for( i = 0; i < 16; i++ ) {
		for( j = 0; j < 16; j++ ) {
			printf("%3d",content_4[i][j]);
		}
		printf("\n");
	}
}

//刷新数独信息
int reflesh_num(void) {
	int i,j,_i,_j;
	
	for( i = 0,_i = 1; i < NUM*NUM; i++ ) {
		for( j = 0,_j = 2; j < NUM*NUM; j++ ) {
			setpos(_j,_i);
			set_font_color();//默认颜色
			if( state_3[i][j] == 1 ) 
				setcolor(10,BACKGROUND);
			if( content[i][j] != 0 )
				printf("%d",content[i][j]);
			else
				printf("  ");
			if( (j+1) % NUM == 0 )
				_j += 6;
			else 
				_j += 4;
		}
		if( (i+1) % NUM == 0 )
				_i += 3;
			else 
				_i += 2;
		
	}
	set_font_color();//默认颜色
}

//clear显示
int clear_num_test(void) {
		int i,j,_i,_j;
	
	for( i = 0,_i = 1; i < NUM*NUM; i++ ) {
		for( j = 0,_j = 2; j < NUM*NUM; j++ ) {
			setpos(_j,_i);
			printf("  ");
			if( (j+1) % NUM == 0 )
				_j += 6;
			else 
				_j += 4;
		}
		if( (i+1) % NUM == 0 )
				_i += 3;
			else 
				_i += 2;
		
	}
	set_font_color();//默认颜色
}

//测试显示
int reflesh_num_test(void) {
		int i,j,_i,_j;
	
	for( i = 0,_i = 1; i < NUM*NUM; i++ ) {
		for( j = 0,_j = 2; j < NUM*NUM; j++ ) {
			setpos(_j,_i);
			Sleep(15);
			set_font_color();//默认颜色
			if( state_3[i][j] == 1 ) 
				setcolor(10,BACKGROUND);
			if( content[i][j] != 0 )
				printf("%d",content[i][j]);
			else
				printf("  ");
			if( (j+1) % NUM == 0 )
				_j += 6;
			else 
				_j += 4;
		}
		if( (i+1) % NUM == 0 )
				_i += 3;
			else 
				_i += 2;
		
	}
	set_font_color();//默认颜色
}

//显示选项一级菜单
int show_choice_menu(int count) {
	setpos(60,1);
	if( count == 1 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("9X9数独　　　　　　");
	setpos(60,2);
	set_font_color();//默认颜色
	if( count == 2 )
		setcolor(BACKGROUND,MENUBAKC);
	//printf("4X4数独　　　　　　");
	printf("退出　　　　　　　 ");
	setpos(60,3);
	set_font_color();
	if( count == 3 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("　　　　　　　　　 ");
	set_font_color();//默认颜色
	setpos(60,4);
	set_font_color();
	printf("　　　　　　　　　 ");
	setpos(60,5);
	printf("　　　　　　　　　 ");
	setpos(60,6);
	printf("　　　　　　　　　 ");
	setpos(60,7);
	printf("　　　　　　　　　 ");
	setpos(60,8);
	printf("　　　　　　　　　 ");
	setpos(60,9);
	printf("　　　　　　　　　 ");
	setpos(60,10);
	printf("　　　　　　　　　 ");
	setpos(60,11);
	printf("　　　　　　　　　 ");
	setpos(60,12);
	printf("　　　　　　　　　 ");
	setpos(60,13);
	printf("　　　　　　　　　 ");
	setpos(60,14);
	printf("　　　　　　　　　 ");
}

//显示二级菜单
int show_2_menu(int count_2) {
	setpos(60,1);
	if( count_2 == 1 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("生成数独　　　　　 ");
	setpos(60,2);
	set_font_color();//默认颜色
	if( count_2 == 2 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("深度优先搜索求解   ");
	setpos(60,3);
	set_font_color();
	if( count_2 == 3 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("优化深度优先　　　 ");
	setpos(60,4);
	set_font_color();
	if( count_2 == 4 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("重填　　　　　　　 ");
	setpos(60,5);
	set_font_color();
	if( count_2 == 5 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("显示执行过程: ");setcolor(12,BACKGROUND);printf("%2s　 ",procedure==1?"是":"否");
	set_font_color();
	if( count_2 == 6 )
		setcolor(BACKGROUND,MENUBAKC);
	setpos(60,6);
	printf("返回　　　　　　　 ");
	set_font_color();
	setpos(60,7);
	printf("　　　　　　　　　 ");
	setpos(60,8);
	printf("　　　　　　　　　 ");
	setpos(60,9);
	printf("　　　　　　　　　 ");
	setpos(60,10);
	printf("　　　　　　　　　 ");
	setpos(60,11);
	printf("　　　　　　　　　 ");
	setpos(60,12);
	printf("　　　　　　　　　 ");
	setpos(60,13);
	printf("　　　　　　　　　 ");
	setpos(60,14);
	printf("　　　　　　　　　 ");
}

//显示主框架
int show_menu(void) {
	if( NUM == 3 ) { //9*9
		show_3_2();
		show_choice_menu(1);
	}else if( NUM == 4 ) { //4*4
		//show_4();
		show_choice_menu(1);
	}
	setpos(60,0);
	setcolor(12,14);
	printf("       菜单　　　　");
	set_font_color();
}

//显示生成数独三级菜单
int show_create_hole_menu(int count_3) {
	setpos(60,1);
	if( count_3 == 1 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("30个空　　　 　　　");
	setpos(60,2);
	set_font_color();//默认颜色
	if( count_3 == 2 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("40个空　　　 　　　");
	setpos(60,3);
	set_font_color();
	if( count_3 == 3 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("50个空　　　 　　　");
	setpos(60,4);
	set_font_color();
	if( count_3 == 4 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("60个空　　　 　　　");
	setpos(60,5);
	set_font_color();
	if( count_3 == 5 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("70个空　　　 　　　");
	setpos(60,6);
	set_font_color();
	if( count_3 == 6 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("难题1 　　　 　　　");
	setpos(60,7);
	set_font_color();
	if( count_3 == 7 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("难题2 　　　 　　　");
	setpos(60,8);
	set_font_color();
	if( count_3 == 8 )
	setcolor(BACKGROUND,MENUBAKC);
	printf("难题3 　　　 　　　");
	setpos(60,9);
	set_font_color();
	if( count_3 == 9 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("难题4 　　　 　　　");
	setpos(60,10);
	set_font_color();
	if( count_3 == 10 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("难题5 　　　 　　　");
	setpos(60,11);
	set_font_color();
	if( count_3 == 11 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("难题6 　　　 　　　");
	setpos(60,12);
	set_font_color();
	if( count_3 == 12 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("难题7 　　　 　　　");
	setpos(60,13);
	set_font_color();//默认颜色
	if( count_3 == 13 )
		setcolor(BACKGROUND,MENUBAKC);
	printf("难题8 　　　 　　　");
	set_font_color();//默认颜色
}