#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int input(char a,char ar[]);
int main(int argc,char *argv[])
{
	int i,j,k=0;
	char ar[100];
	FILE *file;
	char ch;
	int count[100]={0};
	if(argc==1)
	{
		fprintf(stderr,"使用命令行参数!!!");
		exit(1);
	}
	else if(argc==2)
	{
		gets(ar);
		count[0]=input(argv[1][0],ar);
		fprintf(stdout,"\"%c\"在输入的字符串中出现的次数为：%d",argv[1][0],count[0]);
		exit(0);
	}
	for(i=2;i<argc;i++)
	{
		if((file=fopen(argv[i],"r"))==NULL)
		{
			fprintf(stderr,"\n无法打开%s文件!!!(文件不存在或其他错误)\n继续下一文件",argv[i]);
			k++;
			continue;
		}
		//setvbuf(file,NULL,_IOFBF,1024);
		fprintf(stdout,"\n打开%s文件：\n",argv[i]);
		for(j=0;j<80;j++)
			putchar('-');
		ch=getc(file);
		while(ch!=EOF)
		{
			if(ch==argv[1][0])
				count[i-2]++;
			putc(ch,stdout);
			ch=getc(file);
		}
		putchar('\n');
		for(j=0;j<80;j++)
			putchar('-');
		fclose(file);
	}
	fprintf(stdout,"\n已打开全部文件.");
	for(i=0;i<(argc-(k+2));i++)
		fprintf(stdout,"\n文件%s中%c出现的次数为：%d",argv[i+2],argv[1][0],count[i]);
	exit(0);
}
int input(char a,char ar[])
{
	int i,j=0;
	for(i=0;ar[i]!='\0';i++)
		if(a==ar[i])
			j++;
	return j;
}