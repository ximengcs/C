#include <stdio.h>
void chline(char ch,int i,int j);
//test
int main (void)
{
	char ch;
	int i,j;
	printf("please input a word and two number:");
	scanf("%c%d%d",&ch,&i,&j);
	scanf("%*s");
	chline(ch,i,j);
	while(ch!='q')
	{
		scanf("%*s");
		printf("please input a word and two number:");
		scanf("%c%d%d",&ch,&i,&j);
		chline(ch,i,j);
	}
}
void chline(char ch,int i,int j)
{
	int h=1;
	
		while(h<i)
		{
			printf(" ");
			h++;
		}
		while(h>=i&&h<=j)
		{
			printf("%c",ch);
			h++;
		}
		printf("\n");
}