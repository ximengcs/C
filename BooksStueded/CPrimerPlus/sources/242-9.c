#include <stdio.h>
#define conversation "please choose one of the folloing:"
#define con2 "enter the number of your choice:"
#define listi "1)copy files     2)move files\n3)remove files   4)quit\n"
int shu(int x,int y);
void list(void);
void main()
{
	int sj,xj,q;
	printf("please input up world:");
	scanf("%d",&sj);
	printf("please input down world:");
	scanf("%d",&xj);
	q = shu(sj,xj);
	printf("return :%d",q);
}
int shu(int x,int y)
{
	int j;
	printf("please input a number:");
	scanf("%d",&j);
	while( j > x || j < y)
	{
		list();
		printf("please input a number:");
		scanf("%d",&j);
	}
	return j;
}
void list(void)
{
	printf("%s\n",conversation);
	printf("%s",listi);
	printf("%s\n",con2);
}