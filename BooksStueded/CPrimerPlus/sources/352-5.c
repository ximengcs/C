#include <stdio.h>
#include <time.h>
int main(void)
{
	int i,j,k=0;
	int s[100];
	srand(time(0));	
	for(i=0;i<100;i++)
	{
		s[i]=rand()%10+1;
	}
	for(i=0;i<100;i++)
		for(j=i+1;j<100;j++)
		{
			if(s[i]<s[j])
			{
				k=s[i];
				s[i]=s[j];
				s[j]=k;
			}
		}
	for(i=0;i<100;i++)
	{
		printf("%d ",s[i]);
	}
	return 0;
}	