#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int leap_year;
	int year;
	
	leap_year = 0;
	while( scanf( "%d", &year ) == 1 ){
		if( year % 4 == 0 ){
			if( year % 100 == 0 ){
				if( year % 400 == 0 )
					leap_year = 1;
				else leap_year = 0;
			}
			else leap_year = 1;
		}
		else leap_year = 0;
		if( leap_year == 1 )
			printf("闰年\n");
		else printf("不是闰年\n");
	}
	
	return EXIT_SUCCESS;
}