#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define   LINE   101
#define   SIZE   5
#define   IN     1
#define   OUT    0

static char THE[SIZE] = "what";

int main( void )
{
	char a[LINE];
	int state;
	int the_i;
	int ch_i;
	int count;
	int ch;
	int i;
	
	i = 0;
	while( (ch = getchar()) != EOF ){
		if( ch == '\n' || i == 100 ){
			a[i] = '\0';
			i = 0;
		}
		else{
			a[i] = ch;
			i++;
			continue;
		}
		
		count = 0;
		state = OUT;
		the_i = 0;
		ch_i = 0;
		while( a[ ch_i ] != '\0' ){
			if( isblank( a[ch_i] ) ){
				ch_i++;
				continue;
			}
			if( a[ch_i] == THE[the_i] ){
				if( state == OUT ){
					state = IN;
					ch_i++;
					the_i++;
				}
				else if( state == IN ){
					ch_i++;
					the_i++;
					if( the_i == SIZE - 1 ){
						count++;
						the_i = 0;
						state = OUT;
					}
				}
			}
			else if( state == IN ){
				state = OUT;
				ch_i -= the_i-1;
				the_i = 0;
			}
			else
				ch_i++;
		}
		
		printf( "%s出现的次数: %d\n", THE, count );
	}
	
	return EXIT_SUCCESS;
}	