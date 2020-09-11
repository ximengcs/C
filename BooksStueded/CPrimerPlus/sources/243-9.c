#include <stdio.h>
void shu(unsigned int x,unsigned int y,unsigned int j);
int main (void)
{
	unsigned int j = 0,x,y;
	while(1)
	{
		scanf("%ld%ld",&x,&y);
		shu(x,y,j);
		printf("\n");
	}

}
void shu(unsigned int x,unsigned int y,unsigned int j)
{
	while(x != 0)
	{
		j=x%y;
		x=x/y;
		shu(x,y,j);
		printf("%ld",j);
		break;
	}
}
