#include<stdio.h>
int main()
{
	int s=0,n=0;
	while(n<=50)
	{
		s=s+n;
		n++;
	}
	printf("1+2+3+4+...+50=%d(while执行)\n",s);
	s=0;
	n=0;
	do     
	{                  //do while循环do中子句用大括号括起来
		s=s+n;
		n++;
	}
	while(n<=50);
	printf("1+2+3+4+...+50=%d(do while执行)\n",s);
	for(s=0,n=0;n<=50;n++)
		s=s+n;
	printf("1+2+3+4+...+50=%d(for执行)\n",s);
	return 0;
}