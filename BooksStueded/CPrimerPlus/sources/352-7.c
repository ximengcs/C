#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void form(int n,int i,int j,int ch[n]);
int complete(int n,int m);
int main(void)
{
	int i,j,p,a;
	printf("Enter the number of sets:enter q to stop.\n");
	while(scanf("%d",&a)==1)
	{
		int ch[a];
		printf("How many sides and how many dice\n");
		scanf("%d %d",&i,&j);
		form(a,i,j,ch);
		putchar('\n');
		printf("Enter the number of sets:enter q to stop.\n");
	}
	return 0;
}
void form(int n,int i,int j,int ch[n])
{
	int l,p;
	srand(time(0));
	for(l=0;l<n;l++)
		ch[l]=complete(i,j);
	printf("Here are %d sets of %d %d-sided throws\n",n,j,i);
	for(p=0;p<n;p++)
		printf("%5d",ch[p]);
}
int complete(int n,int m)
{
	int i,j=0;
	for(i=0;i<m;i++)
		j=j+(rand()%n)+1;
	return j;
}
	