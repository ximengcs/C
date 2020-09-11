#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define   SIZE      100
#define   FLOATSIZE 18

int print( char *string, ... );

int main( void )
{
	int i = 0;
	  //测试
	print( "ABCD\n%d %d\n%s\n%c\n%f\nDCBA", 1+1, 2*2, "I LOVE YOU", 'XM', 1.234 );
	
	return EXIT_SUCCESS;
}

int print( char *string, ... )
{
	int  i = 0;           
	int  count = 0;          //统计%s(格式化符号)数目
	int  sign[SIZE] = {0};   //将格式化符号(%s等)在字符串string中的偏移数（下标）
	int  sign_count = 0;     
	int  code;               //匹配%后的字母编号
	int  p;
	va_list var_arg;         //可变参数列表
	
	while( *(string + i) != '\0' ){         //i是print第一个参数(字符串)的下标
		if( *(string + i) == '%' && ( *(string + i + 1) == 'd' ||
			*(string + i + 1) == 'f' || *(string + i + 1) == 's' ||
			*(string + i + 1) == 'c') ){
				
		//如果找到格式化符号（%d等），则将格式化符号在string的偏移数保存在sign中
				sign[sign_count++] = i;        //%的偏移量
				sign[sign_count++] = i+1;      //%后的字母的偏移量
				count++;                       //如果找到格式化符号，count+1
				i += 2;                        //因为格式化符号占两个字节
			}
		else
			//下一个字符
			i++;
	}
	
	//将最后一个格式化符号偏移量和文件结尾保存在sign的最后
	sign[sign_count] = sign[sign_count-1];  
	sign[++sign_count] = i+1;
	
	va_start( var_arg, count );
	
	i = 0;
	sign_count = 1;
	while( i < count ){
		
		//输出第一个格式化符号前面的字符
		if( i == 0 && sign[sign_count] != 1 ){
			p = 0;
			while( p <= sign[sign_count - 1] - 1 ){
				putchar( *(string + p) );
				p++;
			}
		}
		
		//匹配格式化符号
		code = *(string + sign[sign_count]);
		switch( code ){
			case 'd': {
				int number = va_arg( var_arg, int );
				char num[SIZE] = {'\0'};
				int i = 0;
				
				//将数字转化为字符；
				while( number != 0 ){
					num[i++] = number%10 + '0';
					number /= 10;
				}
				num[i] = '\0';
				
				//从字符数组末尾输出（因为转化的数字是倒序的）
				i--;
				while( i >= 0 )
					putchar( num[i--] );
				break;
			}
			case 'f': {
				char point[FLOATSIZE];
				char num[6];
				int  i = 0;
				int  j = 0;
				long number;
				
				//将浮点型数字后面的小数点乘掉并转化为long
				number = (long)(va_arg( var_arg, double ) * 1000000);
				
				//将数字后6位（小数位）转化为字符
				while( i < 6 ){
					point[i] = number%10 + '0';
					number /= 10;
					i++;
				}
				
				//将其余数字转化为字符
				while( number != 0 ){
					num[j] = number%10 + '0';
					number /= 10;
					j++;
				}
				
				//输出整数部分
				j--;
				while( j >= 0 ){
					putchar( num[j] );
					j--;
				}
				//输出小数点
				putchar( '.' );
				
				//输出小数位
				i--;
				while( i >= 0 ){
					putchar( point[i] );
					i--;
				}
				break;
			}
			case 's': {
				char *chars;
				
				//将字符串参数保存在指针中
				chars = va_arg( var_arg, char * );
				
				//输出字符串
				while( *chars != '\0' )
					putchar( *chars++ );
				break;
			}
			case 'c': {
				int  c;
				c = va_arg( var_arg, int );
				//输出字符
				putchar( c );
				break;
			}
			default : {
				return -1; //检测错误！
			}
		}
		
		//输出当前格式符到下一个格式符间的字符
		p = sign[sign_count] + 1;  
		while( p <= ((sign[sign_count+1])-1) ){
				putchar( *(string+p) );
				p++;
			}
		
		i++; //下一个格式符
		sign_count += 2; //下一个格式符在string中的偏移量(%s)占2位所以+2
	}
	
	//输入最后一个格式符到文件结尾间的字符
	p = sign[--sign_count] + 1;
		while( p <= ((sign[sign_count+1])-1) ){
				putchar( *(string+p) );
				p++;
			}
	
	va_end( var_arg );
	
	return count;
}