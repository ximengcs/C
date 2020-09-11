#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main( void )
{
	int ch;
	unsigned int iscntrl_;
	unsigned int isspace_;
	unsigned int isdigit_;
	unsigned int islower_;
	unsigned int isupper_;
	unsigned int ispunct_;
	unsigned int noprint_;
	
	iscntrl_ = 0;
	isspace_ = 0;
	isdigit_ = 0;
	islower_ = 0;
	isupper_ = 0;
	ispunct_ = 0;
	noprint_ = 0;
	while( (ch = getchar()) !=  EOF ){
		if( iscntrl( ch ) )
			iscntrl_++;
		if( isspace( ch ) )
			isspace_++;
		if( isdigit( ch ) )
			isdigit_++;
		if( islower( ch ) )
			islower_++;
		if( isupper( ch ) )
			isupper_++;
		if( ispunct( ch ) )
			ispunct_++;
		if( !isprint( ch ) )
			noprint_++;
	}
	
	printf( "\n控制字符: %d\n", iscntrl_ );
	printf( "空白字符: %d\n", isspace_ );
	printf( "数    字: %d\n", isdigit_ );
	printf( "小写字母: %d\n", islower_ );
	printf( "大写字母: %d\n", isupper_ );
	printf( "标点符号: %d\n", ispunct_ );
	printf( "不可打印: %d", noprint_ );
	
	return EXIT_SUCCESS;
}