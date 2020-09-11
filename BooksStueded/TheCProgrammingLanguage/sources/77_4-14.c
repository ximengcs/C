#define swap(type,x,y) {type num;num=x;x=y;y=num;}
#include <stdio.h>
int main(void)
{
	int a, b;
	scanf("%d %d",&a, &b);
	swap(int,a,b);
	printf("%d %d",a,b);
	return 0;
}