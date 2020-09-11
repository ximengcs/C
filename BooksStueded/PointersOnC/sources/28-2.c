#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int  number_;
	int  c;
	
	number_ = 0;
	while( (c=getchar()) != EOF ){
		if( c == '{' )
			number_++;
		else if( c == '}' )
			if( number_ != 0 )
				number_--;
	}
	
	if( number_ == 0 )
		printf("花括号匹配");
	else
		printf("花括号不匹配");
	
	return EXIT_SUCCESS;
}