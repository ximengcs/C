#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   SIZE   50
#define   TRUE    1
#define   FALSE   0

char *edit( char *pattern, char const *digits );

int main( void )
{
	char pattern_[SIZE];
	char digits_[SIZE];
	
	printf( "输入格式图案: " );
	gets( pattern_ );
	printf( "输入数字: " );
	gets( digits_ );
	
	printf( "$%s\n", edit( pattern_, digits_ ) );
	printf( "结果字符串: %s\n", pattern_ );
	
	return EXIT_SUCCESS;
}

char *edit( char *pattern, char const *digits )
{
	char *tmp_pattern;
	char *state;
	
	state = NULL;
	tmp_pattern = pattern+1;
	
	while( *tmp_pattern != '\0' ){
		if( *tmp_pattern == '#' ){
			if( *digits == '\0' ){
				*tmp_pattern = '\0';
				return state;
			}
			if( state == NULL ){
				if( *digits == '0' || *digits == ' ' ){
					*tmp_pattern = *pattern;
					digits++;
				}
				else{
					*tmp_pattern = *digits++;
					state = tmp_pattern;
				}
			}
			else{
				if( *digits == ' ' ){
					*tmp_pattern = '0';
					digits++;
				}
				else
					*tmp_pattern = *digits++;
			}
		}
		else if( *tmp_pattern == '!' ){
			if( *digits == '\0' ){
				*tmp_pattern = '\0';
				return state;
			}
			if( state == NULL ){
				if( *digits == ' ' ){
					*tmp_pattern = '0';
					digits++;
				}
				else
					*tmp_pattern = *digits++;
				state = tmp_pattern;
			}
			else{
				*tmp_pattern = *digits++;
			}
		}
		else{
			if( state == NULL )
				*tmp_pattern = *pattern;
		}
		tmp_pattern++;
	}
}
	