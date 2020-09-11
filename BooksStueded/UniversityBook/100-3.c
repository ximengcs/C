#include<stdio.h>
int main()
{
	int year=0;
	float s=200;
	while(s<=600)
	{
		s=s+200*0.045;
		year++;
	}
	printf("year=%d",year);
	return 0;
}