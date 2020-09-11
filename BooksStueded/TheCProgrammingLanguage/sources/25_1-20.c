#include <stdio.h>
#define TABLE 8
int main(void)
{
	int distance, temp;
	int c;
	
	distance = 1;
	temp = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\t')
		{
			temp = TABLE - (distance-1)%TABLE;
			while(temp > 0)
			{
				putchar(' ');
				temp --;
				distance ++;
			}
		}
		else if(c == '\n')
		{
			putchar(c);
			distance = 1;
		}
		else
		{
			putchar(c);
			distance++;
		}
	}
	return 0;
}