#include <stdio.h>
#include <stdlib.h>
#define   SIZE   27
#define   TRUE    1
#define   FALSE   0

/*
** 用密匙对文件处理
*/
int prepare_key( char *key );
void show_key( void );

int main( void )
{
	char keys[SIZE];
	
	printf( "输入密匙: " );
	gets( keys );
	if( prepare_key( keys ) == TRUE )
		show_key();
	else
		printf( "加密失败" );
	
	return EXIT_SUCCESS;
}

static char up_line[SIZE] = { 
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0' 
};

static char down_line[SIZE];

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

void show_key( void )
{
	printf( "加密后的文件: %s", down_line );
}