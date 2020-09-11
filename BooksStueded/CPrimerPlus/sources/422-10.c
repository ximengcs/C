#include <stdio.h>
void show_menu(void);
void show_menu1(void);
void show_menu2(void);
void show_menu3(void);
void show_menu4(void);
int main(void)
{
	int i;
	typedef void (*fp)(void);
	fp ch[5]={show_menu,show_menu1,show_menu2,show_menu3,show_menu4};
	scanf("%d",&i);getchar();
	ch[i]();
	return 0;
}
void show_menu(void)
{
	putchar('a');
}
void show_menu1(void)
{
	putchar('b');
}
void show_menu2(void)
{
	putchar('c');
}
void show_menu3(void)
{
	putchar('d');
}
void show_menu4(void)
{
	putchar('e');
}
	