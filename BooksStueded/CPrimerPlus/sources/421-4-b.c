#include <string.h>
#include <stdio.h>
struct name{
	char xing[10];
	char middle;
	char ming[10];
};
struct messageq{
	long id;
	struct name allname;
};
void show(struct messageq *p);
int main(void)
{
	int i;
	struct messageq message[5];
	for(i=0;i<5;i++)
	{
		printf("input your name:");
		while(gets(message[i].allname.xing)==NULL)
			puts("please input you name right");
		printf("input your name again");
		message[i].allname.middle=getchar();
		printf("input your name again");
		while(getchar()!='\n')
			continue;
		gets(message[i].allname.ming);
		printf("input your id");
		scanf("%ld",&message[i].id);
		show(&message[i]);
	}
	return 0;
}
void show(struct messageq *p)
{
	printf("%s,%s %c. %ld",p->allname.xing,p->allname.ming,p->allname.middle,p->id);
}
