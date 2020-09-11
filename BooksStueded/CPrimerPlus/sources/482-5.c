#include <time.h>
#include <stdio.h>
#define SIZE 100
void show(int [],int,int);
int main(void)
{
	int ch[SIZE];
	int i,s=1;
	for(i=0;i<SIZE;i++,s++)
		ch[i]=s;
	printf("输入打印的次数:");
	scanf("%d",&i);
	show(ch,SIZE,i);
	return 0;
}
void show(int ch[],int size,int n)
{
	int i,s=0;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		s=rand()%SIZE;
		if(ch[s]==0)
		{
			i--;
			continue;
		}
		else 
		{
			printf(" %-4d ",ch[s]);
			ch[s]=0;
		}
		if((i+1)%10==0 && i!=0)
			putchar('\n');
	}
}