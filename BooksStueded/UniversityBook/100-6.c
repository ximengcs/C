#include<stdio.h>
int main()
{
	long int s=0,i=0;
	scanf("%d",&s);
	while(s!=0)
	{
		i=i+s%10;   //运算后没有赋值给本身s%10
		s=s/10;
	}
	printf("%d",i);
	return 0;
}