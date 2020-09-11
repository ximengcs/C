#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort( void *head, int num, int each_long, int (*compare)( void *item_one, void *item_two ) );
int cmp_int( void *item_one, void *item_twe );
int cmp_float( void *item_one, void *item_two );
int cmp_char( void *item_one, void *item_two );
int cmp_double( void *item_one, void *item_two );

int main( void )
{
	int i, j;
	
	int ints[50];
	char chars[50];
	float floats[50];
	double doubles[50];
	
	srand(time(NULL));
	
	for( i = 0; i < 50; i++ ){
		ints[i] = rand()%19+1;
		chars[i] = rand()%25+1+65;
		floats[i] = (float)(rand()%100000+1)/12345.12345;
		doubles[i] = (double)(rand()%100000+1)/12345.12345;
	}
	
	for( i = 0; i < 50; i++ )
		printf( "%4.2f ", floats[i] );
	putchar( '\n' );
	putchar( '\n' );
	
	for( i = 0; i < 50; i++ )
		printf( "%4.2lf ", doubles[i] );
	putchar( '\n' );
	putchar( '\n' );
	
	for( i = 0; i < 50; i++ )
		printf( "%-4d", ints[i] );
	putchar( '\n' );
	putchar( '\n' );
	
	for( i = 0; i < 50; i++ )
		printf( "%2c", chars[i] );
	putchar( '\n' );
	putchar( '\n' );
	
	sort( ints, 50, 4, cmp_int );
	sort( chars, 50, 1, cmp_char );
	sort( floats, 50, 4, cmp_float );
	sort( doubles, 50, 8, cmp_double );
	
	for( i = 0; i < 50; i++ )
		printf( "%4.2f ", floats[i] );
	putchar( '\n' );
	putchar( '\n' );
	
	for( i = 0; i < 50; i++ )
		printf( "%-4d", ints[i] );
	putchar( '\n' );
	putchar( '\n' );
	
	for( i = 0; i < 50; i++ )
		printf( "%2c", chars[i] );
	putchar( '\n' );
	putchar( '\n' );
	
	for( i = 0; i < 50; i++ )
		printf( "%4.2lf ", doubles[i] );
	putchar( '\n' );
	putchar( '\n' );
	
	
	return EXIT_SUCCESS;
}

int cmp_char( void *a, void *b )
{
	return *(char *)a == *(char *)b ? 0 : *(char *)a - *(char *)b;
}

int cmp_int( void *a, void *b )
{
	return *(int *)a == *(int *)b ? 0 : *(int *)a - *(int *)b;
}

int cmp_float( void *a, void *b )
{
	return *(float *)a == *(float *)b ? 0 : *(float *)a > *(float *)b ? 1 : -1;
}

int cmp_double( void *a, void *b )
{
	return *(double *)a == *(double *)b ? 0 : *(double *)a > *(double *)b ? 1 : -1;
}

void sort( void *head, int num, int each_long, int (*compare)( void *item_one, void *item_two ) )
{
	register int i, j, k;
	char temp;
	
	head = (char *)head;
	for( i = 0; i < num-1; i++ ){
		for( j = i+1; j < num; j++ ){
			if( compare( head+i*each_long, head+j*each_long ) > 0 ){
				for( k = 0; k < each_long; k++ ){
					temp = *((char *)head+i*each_long+k);
					*((char *)head+i*each_long+k) = *((char *)head+j*each_long+k);
					*((char *)head+j*each_long+k) = temp;
				}
			}
		}
	}
}