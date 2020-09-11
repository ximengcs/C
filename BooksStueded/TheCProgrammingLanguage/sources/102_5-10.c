#include <stdio.h>
#include <string.h>
static char sign[10] = {'\0'};
static sign_p = 0;
static int num[40] = {0};
static num_p = 0;
void in_num(int);
void in_char(char);
int out_num(void);
int atoi_(char);
void show(int *);
void show_(char *);
int main(int argc,char *argv[])
{
	int i, last = argc - 1;
	int spare;
	i = 0;
	if(argc < 3)
	{
		printf("error");
		return -1;
	}
	while(last != 0)
	{
		if(atoi_(argv[last][0]) >= 1 && atoi_(argv[last][0] <= 9))
			in_num(atoi_(argv[last][0]));
		else
			in_char(argv[last][0]);
		last--;
	}
	show_(sign);
	while(sign[i] != '\0')
	{
		if(sign[i] == '+')
			in_num(out_num() + out_num());
		else if(sign[i] == '-')
		{
			spare = out_num();
			in_num(spare - out_num());
		}
		else if(sign[i] == '*')
			in_num(out_num() * out_num());
		else if(sign[i] == '/')
		{
			spare = out_num();
			in_num(spare / out_num());
		}
		else
			return 1;
		i++;
	}
	printf("%d",out_num());
	return 0;
}
int atoi_(char c)
{
	return c - '0';
}
void show(int *ch)
{
	int i = 0;
	while( i < 4)
	{
		printf("%d",ch[i]);
		i++;
	}
	putchar('\n');
}
void show_(char *ch)
{
	char c;
	while((c = *(ch++)))
		putchar(c);
	putchar('\n');
}
int out_num(void)
{
	return num[num_p--];
}
void in_char(char ch)
{
	sign[sign_p++] = ch;
}
void in_num(int n)
{
	num[++num_p] = n;
}