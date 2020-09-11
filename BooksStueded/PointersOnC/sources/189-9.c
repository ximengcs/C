#include <stdio.h>
#include <stdlib.h>

int count_chars( char const *str, char const *chars );

int main( void )
{
	char a[100] = "iosgppppsgiosdpppgfgsdpppiosgdgsgsiosgd";
	char b[10] = "ppp";
	
	printf( "%d", count_chars( a, b ) );
	
	return EXIT_SUCCESS;
}

int count_chars( char const *str, char const *chars )
{
	int  count;
	int  i;
	
	count = 0;
	/*
	** 逐个字符匹配直到遇到文件结尾
	*/
	while( *str != '\0' ){
		/*
		** 如果字符全部匹配， 则str向后移动到匹配的字符串结束处
		** i为偏移量
		*/
		i = 0;
		/*
		** 如果第一个字符匹配
		*/
		if( *str == *chars ){
			/*
			** 则开始判断后面的字符是否相等
			*/
			while( *(str+i) == *(chars+i) ){
				/*
				** str偏移加1, 用于如果所有字符都匹配，则str向后偏移i
				*/
				i++;
				/*
				** 如果要匹配的字符下一个是文件结尾，
				** 则视为找到一个匹配结果，并把str
				** 定位到匹配的结束处,并退出循环
				*/
				if( *(chars+i) == '\0' ){
					str += i-1;
					count++;
					break;
				}
			}
		}
		/*
		** 查找下一个字符
		*/
		str++;
	}
	
	return count;
}
	