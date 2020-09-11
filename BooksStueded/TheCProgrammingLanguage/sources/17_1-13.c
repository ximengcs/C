#include <stdio.h>
#define OUT 0
#define IN 1
#define NUMBER 100  //最大列数
int countword(int []);
void show1(int [],int,int);
void show2(int [],int,int);
int cmp(int []);
int main(void)
{
	int num[NUMBER] = {0};
	int s;
	s = countword(num);
	printf("\n水平直方图\n");
	show1(num,s,cmp(num));
	printf("\n垂直直方图\n");
	show2(num,s,cmp(num));
	return 0;
}
void show2(int ch[],int n,int max)
{
	int i, j, q = max;
	putchar('\n');
	for(i = 0; i < max; i++)
	{
		if(q % 2 == 0)
		{
			printf("%2d",q);
			q--;
		}
		else
		{
			printf("  ");
			q--;
		}
		printf("┃");
		for(j = 0; j < n; j++)
		{
			if(ch[j] >= max+1 - i)
				printf("█  ");
			else if(ch[j]+1 == max+1 - i)
				printf("%2d  ",ch[j]);
			else
				printf("    ");
		}
		putchar('\n');
	}
	printf("  ┗");
	for(i = 0; i < n; i++)
		printf("━━");
	putchar('\n');
	putchar(' ');
	printf("0 ");
	for(i = 0; i < n; i++)
		printf("%2d  ",i+1);
	
}
int countword(int n[])
{
	int i, c, state;
	
	i = 0;
	state = OUT;
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n' || c == '\t')
		{
			if(state == IN)
			{
				i++;
				state = OUT;
			}
		}
		else if(state == OUT)
		{
			n[i] ++;
			state = IN;
		}
		else
			n[i] ++;
	}
	return i;
}
void show1(int n[],int s,int a)
{
	int i, j;
	printf(" 0  ");
	for(i = 0, j = 2; i < a/2; i++, j += 2)
		printf(" %d  ",j);
	putchar('\n');
	printf("  ┏");
	for(i = 0; i < a; i++)
		printf("━");
	putchar('\n');
	for(i = 0; i < s; i++)
	{
		printf("%2d┃",i+1);
		for(j = 0; j < n[i]; j++)
			printf("█");
		printf("%3d",n[i]);
		putchar('\n');
		printf("  ┃");
		putchar('\n');
	}
}
int cmp(int n[])
{
	int i = 0, s = n[0];
	for(i = 1; i < 10; i++)
		if(n[i] > s)
			s = n[i];
	return s;
}