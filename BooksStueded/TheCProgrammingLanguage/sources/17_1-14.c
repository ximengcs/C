#include <stdio.h>
#define zhonglei 10
int countsign(int [],int *,int *);
void show(int [],int,int,int);
int main(void)
{
	int num[10] = {0};
	int white, other;
	int max;
	
	white = other = 0;
	max = countsign(num,&white,&other);
	show(num,white,other,max);
	return 0;
}
void show(int num[],int wh,int ot,int max)
{
	int i, j, s = 2;
	for(i = 0; i < zhonglei; i++)
	{
		printf("%4d┃",i);
		for(j = 0; j < max; j++)
		{
			if(j < num[i])
				printf("█");
			else if(j == num[i])
				printf("%2d",num[i]);
			else
				printf("  ");
		}
		putchar('\n');
		printf("    ┃");
		putchar('\n');
	}
	printf("空格┃");
	for(i = 0; i <= max ; i++)
	{
		if(i < wh)
			printf("█");
		else if(i == wh)
			printf("%3d",wh);
		else
			printf("  ");
	}
	putchar('\n');
	printf("    ┃");
	putchar('\n');
	printf("其它┃");
	for(i = 0; i <= max ; i++)
	{
		if(i < ot)
			printf("█");
		else if(i == ot)
			printf("%3d",ot);
		else
			printf("  ");
	}
	putchar('\n');
	printf("    ┗");
	for(i = 0; i <= max; i++)
		printf("━");
	printf("\n  0   ");
	for(i = 0; i <= max; i++)
		if(i % 2 == 0)
		{
			printf("  %2d",s);
			s += 2;
		}
}
int countsign(int num[],int *wh,int *ot)
{
	int c, max;
	while((c = getchar()) != EOF)
	{
		if(c == '\n' || c == ' ' || c == '\t')
			(*wh)++;
		else if(c >= '0' && c <= '9')
			num[c - '0']++;
		else
			(*ot)++;
	}
	max = num[0];
	for(c = 1; c < 10; c++)
		if(num[c] > max)
			max = num[c];
	if(*wh > max)
		max = *wh;
	if(*ot > max)
		max = *ot;
	return max;
}