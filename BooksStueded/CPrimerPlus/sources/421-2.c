#include <stdio.h>
typedef struct{
	int month[12];
}year;
int main(void)
{
	year num={31,30,31,30,31,30,31,31,30,31,30,31};
	int y,m,d,s=0,i,j;
	scanf("%d %d %d",&y,&m,&d);
	if((y%4)==0)
	{
		num.month[1]=29;
	}
	for(i=m;i>=0;i--)
	{
		s+=num.month[i];
	}
	printf("%d",s);
	return 0;
}