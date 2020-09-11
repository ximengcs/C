#include <stdio.h>
#include <time.h>
int main(void)
{
	int s[10]={0};
	int i,j;
	srand(time(0));
	for(i=0;i<1000;i++)
	{
		j=(rand()%10)+1;
		if(j==1)
			s[0]++;
		if(j==2)
			s[1]++;
		if(j==3)
			s[2]++;
		if(j==4)
			s[3]++;
		if(j==5)
			s[4]++;
		if(j==6)
			s[5]++;
		if(j==7)
			s[6]++;
		if(j==8)
			s[7]++;
		if(j==9)
			s[8]++;
		if(j==10)
			s[9]++;
	}
	for(i=0;i<10;i++)
	{
		printf(" %02d 出现的次数: %d \n",i+1,s[i]);
	}
	if(s[0]==100&&s[1]==100&&s[2]==100&&s[3]==100&&s[4]==100&&s[5]==100&&s[6]==100&&s[7]==100&&s[8]==100&&s[9]==10)
		printf("数字出现的次数相同!");
	return 0;
}
	
	