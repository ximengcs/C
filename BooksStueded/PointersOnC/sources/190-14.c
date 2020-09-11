#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   SIZE   27
#define   TRUE    1
#define   FALSE   0

static char up_line[SIZE] = { 
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0' 
};

static char down_line[SIZE];

/*
** 用密匙对文件处理
*/
int prepare_key( char *key );
/*
** 加密
*/
void encrypt( char *words, const char *key );
/*
** 解密
*/
void decrypt( char *words, const char *key );

int main( void )
{
	char keys[SIZE];
	char words[SIZE];
	
	printf( "输入密匙: " );
	while( gets( keys ) != NULL ){
		if( prepare_key( keys ) == FALSE ){
			printf( "密匙错误！请重新输入: " );
			continue;
		}
		printf( "输入需要加密的文件: " );
		gets( words );
		encrypt( words, down_line );
		printf( "加密后的文件为: %s\n", words );
		printf( "开始解密...\n" );
		decrypt( words, down_line );
		printf( "解密后的文件为: %s\n", words );
		printf( ".......\n" );
		printf( "输入密匙: " );
	}
	
	return EXIT_SUCCESS;
}

int prepare_key( char *key )
{
	int down_i;
	int j;
	int i;
	int key_nul;
	
	/*
	** 将密匙中的非重复字符保存
	*/
	down_i = 0;
	i = 0;
	while( *(key+i) != '\0' ){
		/*
		** 如果密匙不是字母，则处理失败
		*/
		if( !isalpha( *(key+i) ) )
			return FALSE;
		
		key_nul = i;
		for( j = 0; j < key_nul; j++ )
			if( *(key+i) == *(key+j) )
				break;
		if( j == key_nul )
			down_line[down_i++] = toupper( *(key+i) ); //转换为大写字母
		i++;
	}
	down_line[down_i] = '\0';
	
	key_nul = down_i;  //密匙空字符位置  
	while( key_nul < SIZE-1 ){
		for( i = 0; i < SIZE-1; i++ ){
			for( j = 0; j < key_nul; j++ ){
				/*
				** 如果找到相等的字母则退出继续测试下一个字母
				*/
				if( up_line[i] == down_line[j] )
					break;
			}
			if ( j == key_nul ){
				down_line[key_nul] = up_line[i];
				break;
			}
		}
		key_nul++;
	}
	down_line[key_nul] = '\0';
	
	return TRUE;
}

void encrypt( char *words, const char *down_key )
{
	int i;
	
	/*
	** 对文件加密
	*/
	while( *words != '\0' ){
		for( i = 0; i < SIZE-1; i++ )
			if( (char)toupper( *words ) == up_line[i] ){
				if( islower( *words ) )
					*words = (char)tolower(down_key[i]);
				else
					*words = down_key[i];
				break;
			}
		words++;
	}
}

void decrypt( char *words, char const *down_key )
{
	int i;
	
	/*
	** 对文件解密
	*/
	while( *words != '\0' ){
		for( i = 0; i < SIZE -1; i++ ){
			if( (char)toupper(*words) == down_key[i] ){
				if( islower( *words ) )
					*words = (char)tolower( up_line[i] );
				else
					*words = up_line[i];
				break;
			}
		}
		words++;
	}
}