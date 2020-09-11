#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define   YANS_  100
#define   LONG_  20
#define   KUAN_  20
#define   true   "[]"
#define   false  "  "
#define   YUSHU  50

static char *ch[LONG_][KUAN_];

int main( void )
{
	int j, k;
	int count;
	
	count = 0;
	srand( time( NULL ) );
	
	for( j = 0 ; j < LONG_; j++ )
			for( k = 0; k < KUAN_; k++ )
				ch[j][k] = true;
	
	while( count < LONG_*KUAN_ ){
		
		Sleep( YANS_ );
		system( "cls" );
		for( j = 0 ; j < LONG_; j++ ){
			for( k = 0; k < KUAN_; k++ )
				printf( "%s", ch[j][k] );
			putchar( '\n' );
		}
		
		for( j = 0 ; j < LONG_; j++ )
			for( k = 0; k < KUAN_; k++ )
				if( rand()%YUSHU == 0 && ch[j][k] == true ){
					ch[j][k] = false;
					count++;
				}
	}
	system( "cls" );  //清除最后一个色块
	
	return EXIT_SUCCESS;
}
		