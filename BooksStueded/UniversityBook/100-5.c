#include<stdio.h>
int main()
{
	int h,s;
	for(h=1;h<5;h++)
	{
		for(s=1;s<2*h;s++)
			printf("%5d",s);
		printf("\n");
		}
	return 0;
}