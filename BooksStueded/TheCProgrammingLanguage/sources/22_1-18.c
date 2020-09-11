#include <stdio.h>
#define MAXSIGN 1000
#define IN 1
#define OUT 0
int getline(char sign[],char sapce[],int max);
void strcat_(char s1[],const char s2[]);
//void show(const char s[]); //辅助显示
int main(void)
{
	char sign[MAXSIGN];  //符号数组
	char space[MAXSIGN]; //空格“缓存”
	int i, j;
	
	while((j = getline(sign,space,MAXSIGN)) != 0)
	{
		for(i = 0; i < j; i++)
			printf("[%c]",sign[i]);
		putchar('\n');
	}
	return 0;
}
int getline(char sign[],char space[],int max)
{
	int c, i, j, state;
	
	j = 0;
	state = OUT;   //设置在空格”外“（状态：外）
	for(i = 0; i < max-1 && (c=getchar()) != EOF && c !='\n';) //判断是否是结尾或换行，并保留 \n \0 位置
	{
		if((c == ' ' || c == '\t') && state == OUT)  //如果在空格外 且该字符是空格
		{                                            //
			sign[i] = '\0';							 //先将刚才输入的字符改为“串”，否则strcat会出错
			state = IN;							     //状态：在空格内
			space[j] = c;
			j++;
		}
		else if((c == ' ' || c == '\t') && state == IN)
		{
			space[j] = c;
			j++;
		}
		else
		{
			if(state == IN)
			{
				space[j] = '\0';                  //将空格缓存改为“串”
				strcat_(sign,space);
				i = i + j;
				j = 0;
			}
			sign[i] = c;
			state = OUT;
			i++;
		}
	}
	if(c == '\n' && i != 0)  //如果I为0，则为空行（只有一个回车符）或全为空格
	{
		sign[i] = c;
		i++;
	}
	if(c == '\n' && i == 0)  //
	{ 						 //
		sign[i] = '\0';      //防止输入空行时退出
		return -1;           //
	}
	sign[i] = '\0';
	return i;
}
void strcat_(char s1[],const char s2[])
{
	while(*s1 != '\0')
		s1++;
	for(; (*s1 = *s2) != '\0'; s1++, s2++)
		;
}
/*void show(const char s[])
{
	while( *s != '\0')
	{
		printf("(%c)",*s);
		s++;
	}
	putchar('\n');
}*/