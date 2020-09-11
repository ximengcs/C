#include <stdio.h>
void get_info(int,double *,double *);
void show_info(int,double *,double *);
int main(void)
{
	int mode;
	double distance,butter;
	printf("Enter 0 for metric mode,1 for US mode:");
	scanf("%d",&mode);
	while(mode>=0)
	{
		get_info(mode,&distance,&butter);
		show_info(mode,&distance,&butter);
		printf("Enter 0 for metric mode,1 for US mode:");
		printf("(-1 to quit):");
		scanf("%d",&mode);
	}
	printf("Done.");
	return 0;
}
void get_info(int set,double *distance,double *butter)
{
	if(set==0)
	{
		printf("Enter distance traveled in kilometers:");
		scanf("%lf",distance);
		printf("Enter fuel consumed in liters:");
		scanf("%lf",butter);
	}
	else
	{
		printf("Enter distance traveled in miles:");
		scanf("%lf",distance);
		printf("Enter fule consumed in gallons:");
		scanf("%lf",butter);
	}
}
void show_info(int set,double *distance,double *butter)
{
	if(set==0)
	{
		printf("Fuel consumption is %.2lf liters per 100km\n",(*distance)/((*butter)*3.785));
	}
	else
	{
		printf("Fuel consumption is %.1lf miles per gallon\n",(*distance)/(*butter));
	}
}