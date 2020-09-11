#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int i,num_word=0,num_big=0,num_small=0,num_sign=0,num_num=0;
	char ch[100]={'\0'};
	printf("输入字符串:");
	gets(ch);
	for(i=0;i<100;i++)
	{
		if(isalpha(ch[i]))
			if(isalpha(ch[i+1])==0)
				num_word++;
		if(isupper(ch[i]))
			num_big++;
		if(islower(ch[i]))
			num_small++;
		if(ispunct(ch[i]))
			num_sign++;
		if(isdigit(ch[i]))
			num_num++;
	}
	printf("输入的字符串共有%2d个单词\n                %2d个大写字母\n",num_word,num_big);
	printf("                %2d个小写字母\n                %2d个标点符号\n                %2d个阿拉伯数字",num_small,num_sign,num_num);
	return 0;
}