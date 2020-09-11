#include<stdio.h>
int main()
{
	int s=0;
	while(s<=1500)
	{
		if(s%3==0)
			printf("%d ",s);
		s++;
	}
	return 0;
}