#include "3.h"
#include <stdio.h>
static int set;
static double distance;
static double butter;
void set_mode(int a)
{
	extern int set;
	set=a;
}
void get_info(void)
{
	extern double distance;
	extern double butter;
	if(set==0)
	{
		printf("Enter distance traveled in kilometers:");
		scanf("%lf",&distance);
		printf("Enter fuel consumed in liters:");
		scanf("%lf",&butter);
	}
	else
	{
		printf("Enter distance traveled in miles:");
		scanf("%lf",&distance);
		printf("Enter fule consumed in gallons:");
		scanf("%lf",&butter);
	}
}
void show_info(void)
{
	extern double distance;
	extern double butter;
	if(set==0)
	{
		printf("Fuel consumption is %.2lf liters per 100km\n",distance/(butter*3.785));
	}
	else
	{
		printf("Fuel consumption is %.1lf miles per gallon\n",distance/butter);
	}
}
		
