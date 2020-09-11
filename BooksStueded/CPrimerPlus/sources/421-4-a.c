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
		while(gets(message[i].allname.ming)==NULL)
			puts("please inout your name right");
		printf("input your id");
		scanf("%ld",&message[i].id);
		printf("%s,%s %c. %ld",message[i].allname.xing,message[i].allname.ming,message[i].allname.middle,message[i].id);
	}
	return 0;
}