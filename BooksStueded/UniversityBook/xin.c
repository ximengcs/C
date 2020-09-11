#include<stdio.h>
int main()
{
	int l,h=1,l1=5,l2=5,l3=1,l4=5,l5=5,l6=3;
	while(h<5){
	for(l=1;l<5;l++)
	{
		if(l<l1)
			printf(" ");
		if(l>=l1) 
			printf("*");
	}
	l1--;
	for(l=1;l<5;l++)
	{
		if(l<l2)
			printf("*");
		if(l>=l2)
			printf(" ");
	}
	for(l=1;l<3;l++)
	{
		if(l<l3)
			printf("*");
		if(l>=l3)
			printf(" ");
	}
	l3++;
	for(l=1;l<3;l++)
	{
		if(l<l6)
			printf(" ");
		if(l>=l6)
			printf("*");
	}
	l6--;
	for(l=1;l<5;l++)
	{
		if(l<l4)
			printf("*");
		if(l>=l4) 
			printf(" ");
	}
	for(l=1;l<5;l++)
	{
		if(l<1)
			printf(" ");
		if(l>=l5) 
			printf("*");
	}
	l5--;
	h++;
	printf("\n");
	}
	return 0;
}