#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simon.h"
#define   SIZE      1000
#define   LANGUAGE  100
#define   NUM_SIZE  20
#define   HUNDRED   99

static void written_amount( unsigned int amount, char *buffer );

int main( void )
{
	unsigned int  num;
	char  buffer[SIZE];
	
	for( num = 1; num <= 100000 ; num++ ){
		written_amount( num, buffer );
		printf( "%-80s", buffer );
	}
	
	return EXIT_SUCCESS;
}

static void written_amount( unsigned int amount, char *buffer )
{
	char ZIKU[LANGUAGE][NUM_SIZE];
	char num[SIZE];
	unsigned int  num_long;
	unsigned int  temp;

	ziku( ZIKU );
	

	temp = amount;                   //数字反序保存在数组
	num_long  = 0;
	while( temp != 0 ){
		num[num_long] = temp % 10 + '0'; 
		temp /= 10;
		num_long++;
	}
	num[ num_long ] = '\0';
	temp = num_long;
	
	if( amount < 100 ){
		if( amount == 0 )
			strcpy( buffer, "ZERO" );
		else 
			strcpy( buffer, ZIKU[ amount-1 ] );
		return;
	}
	else if( num_long >= 3 ){
		if( num_long > 3 && num_long <= 6 ){
			if( num_long == 6 ){
				strcpy( buffer, ZIKU[ num[num_long-1] - '0' - 1 ] );
				strcat( buffer, " " );
				strcat( buffer, ZIKU[HUNDRED] );
				num_long -= 3;
			}

			if( temp > 3 ){
				if( temp > 3 && ( num[3] != '0' || num[4] != '0' ) ){
					if( temp == 6 )
						strcat( buffer, " AND " );
					else 
						strcpy( buffer, "" );
				}
				else if( num[3] != '0' || num[4] != '0' )
					strcpy( buffer, "" );   //为了添加空字符，否则出错
				strcat( buffer, ZIKU[ (amount/1000)%100 - 1 ] );
				
				if( num[3] != '0' || num[4] != '0' )
					strcat( buffer, " " ); //美化
				
				strcat( buffer, "THOUSAND " );
			}
			if( num_long == 5 )
				num_long -= 2;
			else if( num_long == 4 )
				num_long --;
		}

		if( num_long >= 3 ){
			if( num[num_long-1] != '0' ){
				if( temp > 3 )
					strcat( buffer, ZIKU[ num[num_long-1] - '0' - 1 ] );
				else
					strcpy( buffer, ZIKU[ num[num_long-1] - '0' - 1 ] );
				strcat( buffer, " " );
				strcat( buffer, ZIKU[ HUNDRED ] );
			}
			if( num[0] == '0' && num[1] == '0' )
				return;
			if( num[2] != '0' )
				strcat( buffer, " " );
			strcat( buffer, "AND " );
			strcat( buffer, ZIKU[ amount%100 - 1 ] );
		}
	}
}
				
				
				
				
				