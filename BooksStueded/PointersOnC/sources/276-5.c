#include <stdlib.h>
#include <ctype.h>

char **do_args( int argc, char **argv,
	char *control, void (*do_arg)( int ch, char *value), void (*illegal_arg)( int ch ) );
	
int main( int argc, char *argv[] )
{
	
	
	return EXIT_SUCCESS;
}

char **do_args( int argc, char **argv, 
	char *control, void (*do_arg)( int ch, char *value), void (*illegal_arg)( int ch ) )
{
	int i, j, k;
	
	/*
	** 处理以 - 开头的命令符
	*/
	i = 1;  //跳过程序名
	while( *argv[i] == '-' ){
		/*
		** 处理 - 后的命令
		*/
		j = 1;
		if( islower( argv[i][j] ) ){
			/*
			** 判断该字符是否位于control字符串内
			*/
			k = 0;
			while( *(control+k) != '\0' ){
				if( argv[i][j] == *(control+k) )
					break;
				k++;
			}
			/*
			** 如果在control内或不在
			*/
			if( *(control+k) == '\0' ){
				illegal_arg( argv[i][j] );
			}
			else{
				/*
				** 如果control后有一个 +　
				*/
				if( *(control+k+1) != '+' ){
					do_arg( argv[i][j], NULL );
				}
				else if( *(control+k+1) == '+' ){
					if( islower( argv[i][j+1] ) ){
						do_arg( argv[i][j+1], &argv[i][j+1] );
					}
					else if( argv[i+1] == '\0' ){
						illegal_arg( argv[i][j] );
					}
					else{
						do_arg( argv[i+1], &argv[i+1] );
					}
				}
			}
		}
		i++;
	}
	
	if( *argv[i] == '\0' ){
		return &argv[i+1];
	}
	else{
		return &argv[i];
	}
	
}