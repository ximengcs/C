#include "simon.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int display(void);
int change(int key);

int number = 49;

int main(void) {//①②③④⑤⑥⑦⑧⑨⑩
	system("cls");
	set_console_size(25,10);
	hide_console();
	display();
	int key = 0;
	while(1) {
		key = getch();
		if(key=='q')
			break;
		else
			change(key);
	}
	show_console();
	set_console_size(100,25);
}

int change(int key) {
	if(key=='w' && number!=58)
		number++;
	else if(key=='s' && number!=49)
		number--;
	display();
}

int display(void) {
	setpos(0,0);
	printf("　▲　\n");
	printf("　");
	switch(number) {
		case 49: printf("①");break;
		case 50: printf("②");break;
		case 51: printf("③");break;
		case 52: printf("④");break;
		case 53: printf("⑤");break;
		case 54: printf("⑥");break;
		case 55: printf("⑦");break;
		case 56: printf("⑧");break;
		case 57: printf("⑨");break;
		case 58: printf("⑩");break;
	}
	printf("　\n");
	printf("　▼　\n");
}