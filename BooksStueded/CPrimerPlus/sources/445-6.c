#include <stdio.h>
#define LEFT   1
#define CENTER 2
#define RIGHT  3
#define ON     1
#define OFF    0
#define ID 0X000000FF
#define SIZE 0X0000FF00
#define ALIGNMENT 0X03000000
#define BOLD 0X04000000
#define ITALIC 0X08000000
#define UNDERLINE 1000000000
struct box_a{
	unsigned long         id:8;
	unsigned long       size:8;
	unsigned long           :8;
	unsigned long  alignment:2;
	unsigned long       bold:1;
	unsigned long     italic:1;
	unsigned long  underline:1;
	unsigned long           :3;
};
union thing{
	struct box_a box_b;
	unsigned long num;
};
void show_jz(unsigned long);
void show(struct box_a *p);
void change_id(struct box_a *);
void change_size(struct box_a *);
void change_a(struct box_a *);
void change_b(struct box_a *);
void change_i(struct box_a *);
void change_u(struct box_a *);
int main(void)
{
	union thing box={1,12,1,0,0,0};
	show(&box.box_b);
	char code;
	printf("f)change font s)change size a)change alignment\nb)toggle bold i)toggle italic u)toggle underline q) quit\n");
	while(scanf("%c",&code)==1)
	{
		while(getchar()!='\n')
			continue;
		switch(code)
		{
			case 'f':change_id(&box.box_b);break;
			case 's':change_size(&box.box_b);break;
			case 'a':change_a(&box.box_b);break;
			case 'b':change_b(&box.box_b);break;
			case 'i':change_i(&box.box_b);break;
			case 'u':change_u(&box.box_b);break;
			default : printf("Bye");return 0;
		}
		show(&box.box_b);
		printf("f)change font s)change size a)change alignment\nb)toggle bold i)toggle italic u)toggle underline q) quit\n");
	}
	return 0;
}
void change_i(struct box_a *num)
{
	num->italic=num->italic ? 0 : 1;
}
void change_u(struct box_a *num)
{
	num->underline=num->underline ? 0 : 1;
}
void change_b(struct box_a *num)
{
	num->bold=num->bold ? 0 : 1;
}
void change_a(struct box_a *num)
{
	char ch;
	unsigned long a_a;
	printf("Select alignment\nl)left c)center r)right\n");
	scanf("%c",&ch);
	if(ch=='l')
		a_a=1;
	else if(ch=='c')
		a_a=2;
	else a_a=3;
	num->alignment=a_a;
	getchar();
}
void change_size(struct box_a *num)
{
	unsigned long size_a;
	printf("Enter font size(0-127):");
	scanf("%d",&size_a);
	num->size=size_a;
	getchar();
}
void change_id(struct box_a *num)
{
	unsigned long id_a;
	printf("Enter font ID(0-255):");
	scanf("%d",&id_a);
	num->id=id_a;
	getchar();
}
void show(struct box_a *p)
{
	printf("ID  SIZE  ALIGNMENT    B    I    U\n");
	printf("%02d   %d     ",p->id,p->size);
	if((p->alignment)==1)
		printf("left");
	else if((p->alignment)==2)
		printf("center");
	else printf("right");
	printf("     %s",p->bold?"ON":"OFF");
	printf("  %s",p->italic?"ON":"OFF");
	printf("  %s\n",p->underline?"ON":"OFF");
}
void show_jz(unsigned long a)
{
	int l=sizeof(unsigned long)*8+1;
	char ch[l];
	int i;
	for(i=l-2;i>=0;i--)
	{
		if(a!=0)
		{
			ch[i]=a%2+'0';
			a/=2;
		}
		else ch[i]='0';
	}
	ch[l-1]='\0';
	puts(ch);
}