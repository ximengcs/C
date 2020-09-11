#include <stdio.h>
int main(void)
{
	int f;
	printf("摄氏 华氏\n");
	for(f = 300;f >= 0; f -= 20)
		printf("%3d %6.1f\n", f, (5.0/9.0) * (f - 32));
	return 0;
}	