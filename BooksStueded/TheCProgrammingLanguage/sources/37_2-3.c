#include <stdio.h>
#define SIZE 40
int htoi(char *);
int main(void)
{
	char ch[SIZE];
	gets(ch);
	printf("%d",htoi(ch));
	return 0;
}
int htoi(char * p)
{
	int zhis=1;
	int count=0;
	int num=0;
	if(*p == '0' && ( *(p+1) == 'x' || *(p+1) == 'X'))
		p = p + 2;
	while( *(p+count) != '\0')
		count++;
	count--;
	while( count >=0 )
	{
		if( *(p+count) >= 65 && *(p+count)<=70)
			num += (*(p+count) - 55) * zhis;
		else if( *(p+count) >=97 && *(p+count)<=102)
			num += (*(p+count) - 87) * zhis;
		else
			num += (*(p+count) - 48) * zhis;
		zhis *= 16;
		count--;
	}
	return num;
}