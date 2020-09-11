#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define   SIZE  50
#define   TRUE   1
#define   FALSE  0

int format( char *format_string, char const *digit_string );

int main( void )
{
	char format_[SIZE];
	char digit_[SIZE];
	
	printf( "输入格式符: " );
	gets( format_ );
	printf( "输入数字: " );
	gets( digit_ );
	
	if( format( format_, digit_ ) == TRUE )
		printf( "结果字符串:\"%s\"", format_ );
	else
		printf( "格式符错误或数字错误！" );
	
	return EXIT_SUCCESS;
}

int format( char *format_string, char const *digit_string )
{
	char *end_format;
	char const *end_digit;
	char *temp;
	int  check;  //检查错误时检查逗号
	
	end_format = format_string + strlen( format_string ) - 1;
	end_digit  =  digit_string + strlen(  digit_string ) - 1;
	
	/*
	** 检查格式符串最左边是否为#，如不是则返回false
	*/
	if( *format_string != '#' )
		return FALSE;
	/*
	** 检查数字字符串是否为空，如是则返回false
	*/
	if( *digit_string == '\0' )
		return FALSE;
	
	check = FALSE;
	temp = format_string;
	while( *temp != '\0' ){
		if( *temp == '.' || *temp == ',' ){
			/*
			** 检查格式符串中，或 .后是否有#，没有则返回false
			*/
			if( *(temp+1) != '#' )
				return FALSE;
			/*
			** 检查逗号与小数点位置是否错误
			*/
			if( *temp == ',' ){
				if( check == TRUE )
					return FALSE;
			}
			else if( *temp == '.' ){
				if( check == FALSE )
					check = TRUE;
				else
					return FALSE;
			}
		}
		/*
		** 如果格式符中出现其他字符，则返回false
		*/
		if( *temp == '#' || *temp == ',' || *temp == '.' )
			temp++;
		else
			return FALSE;
	}
	temp = NULL;
	
	while( end_format >= format_string ){
		if( *end_format == '#' ){
			if( end_digit != NULL )
				*end_format = *end_digit;
			else
				*end_format = ' ';
		}
		else if( *end_format == ',' ){
			if( end_digit == NULL )
				*end_format = ' ';
			else{
				end_format--;
				*end_format = *end_digit;
			}
		}
		else if( *end_format == '.' ){
			/*
			** 检查
			*/
			if( end_digit == NULL ){
				temp = end_format+1;
				end_format--;
				*end_format = '0';
				while( *temp == ' ' )
					*temp++ = '0';
			}
			else{
				end_format--;
				*end_format = *end_digit;
			}
		}
		/*
		** 处理end_format
		*/
		if( end_format == format_string )
			break;
		else
			end_format--;
		
		/*
		** 处理end_digit
		*/
		if( end_digit == digit_string )
			end_digit = NULL;
		else if( end_digit != NULL )
			end_digit--;
	}
	
	return TRUE;
}

	