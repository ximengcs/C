#include <stdio.h>
int main(void)
{
	float h, s;
	int lower, upper, temp;
	lower = 0;
	upper = 300;
	temp = 20;
	s = lower;
	printf("摄氏 华氏\n");
	while(s <= upper)
	{
		h = 32 + s / (5.0/9);
		printf("%6.1f %3.0f\n",s ,h);
		s += temp;
	}
	return 0;
}