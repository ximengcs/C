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
	unsigned int         id:8;
	unsigned int       size:8;
	unsigned int           :8;
	unsigned int  alignment:2;
	unsigned int       bold:1;
	unsigned int     italic:1;
	unsigned int  underline:1;
	unsigned int           :3;
};
union thing{
	struct box_a box_b;
	unsigned int num;
};
void show_jz(unsigned int);
void show(struct box_a *p);
void change_id(unsigned int *);
void change_size(unsigned int *);
void change_a(unsigned int *);
void change_b(unsigned int *);
void change_i(unsigned int *);
void change_u(unsigned int *);
int main(void)
{
	union thing box={1,12,1,0,0,0};
	show(&box.box_b);
	unsigned int id_a,size_a,al_a,bold_a,italic_a,underline_a;
	char code;
	printf("f)change font s)change size a)change alignment\nb)toggle bold i)toggle italic u)toggle underline q) quit\n");
	while(scanf("%c",&code)==1)
	{
		while(getchar()!='\n')
			continue;
		switch(code)
		{
			case 'f':change_id(&box.num);break;
			case 's':change_size(&box.num);break;
			case 'a':change_a(&box.num);break;
			case 'b':change_b(&box.num);break;
			case 'i':change_i(&box.num);break;
			case 'u':change_u(&box.num);break;
			default : printf("Bye");return 0;
		}
		show(&box.box_b);
		printf("f)change font s)change size a)change alignment\nb)toggle bold i)toggle italic u)toggle underline q) quit\n");
	}
	return 0;
}
void change_i(unsigned int *num)
{
	*num ^= ITALIC;
}
void change_u(unsigned int *num)
{
	*num ^= UNDERLINE;
}
void change_b(unsigned int *num)
{
	*num ^= BOLD;
}
void change_a(unsigned int *num)
{
	char ch;
	int a_a;
	printf("Select alignment\nl)left c)center r)right\n");
	scanf("%c",&ch);
	if(ch=='l')
		a_a=1;
	else if(ch=='c')
		a_a=2;
	else a_a=3;
	*num &= ~ALIGNMENT;
	*num |=(a_a<<24 & ALIGNMENT);
	getchar();
}
void change_size(unsigned int *num)
{
	unsigned int size_a;
	printf("Enter font size(0-127):");
	scanf("%d",&size_a);
	*num &=~SIZE;
	*num |=(size_a<<8 & SIZE);
	getchar();
}
void change_id(unsigned int *num)
{
	unsigned int id_a;
	printf("Enter font ID(0-255):");
	scanf("%d",&id_a);
	*num &= ~ID;
	*num |=id_a & ID;
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
void show_jz(unsigned int a)
{
	int l=sizeof(unsigned int)*8+1;
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