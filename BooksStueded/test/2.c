#include <stdio.h>
#include "hotel.h"
#define QUIT 5
#define HOTEL1 80.00
#define HOTEL2 125.00
#define HOTEL3 155.00
#define HOTEL4 200.00
#define DISCOUNT 0.95
#define STARS "******************"   //定义字符型常量一定加双引号
int menu (void);
int getnights(void);
void showprice(double,int);
int main (void)
{
	int nights;
	double hotel_rate;
	int code;
	
	while ((code=menu())!=QUIT)
	{
		switch (code)
		{
			case 1:hotel_rate = HOTEL1;
			break;
			case 2:hotel_rate = HOTEL2;
			break;
			case 3:hotel_rate = HOTEL3;
			break;
			case 4:hotel_rate = HOTEL4;
			break;
			default:hotel_rate = 0.0;
			printf("Oops!\n");
			break;
		}
		nights=getnights();
		showprice(hotel_rate,nights);
	}
	printf("Thank you and good bye.");
	return 0;
}
int menu (void)
{
	int code,status;
	
	printf("\n%s%s\n",STARS,STARS);
	printf("Enter the number of the hotel:\n");
	printf("(1)a_hotel    (2)b_hotel\n");
	printf("(3)c_hotel    (3)d_hotel\n");
	printf("(5)QUIT\n");
	printf("%s%s\n",STARS,STARS);
	while((status = scanf("%d",&code)) != 1 || (code < 1 || code > 5))
	{
		if (status != 1)
			scanf("%*s");
		printf("enter an integer from 1 to 5,please.\n");
	}
	return code;
}
int getnights (void)
{
	int nights;
	
	printf("how many nights are needed?");
	while (scanf("%d",&nights)!=1)
	{
		scanf("%*s");
		printf("please enter an integer,such as 2.\n");
	}
	return nights;
}
void showprice(double rate,int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;
	for (n = 1;n <= nights;n++,factor*=DISCOUNT)
		total += rate * factor;
	printf("The total cost will be $%0.2f.\n",total);
}