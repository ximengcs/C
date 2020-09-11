#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int i;
	FILE *file1,*file2;
	char ar[10]={'\0'},br[10]={'\0'};
	char temp[1024];
	fprintf(stdout,"please input file's name1:");     //gets读取换行符前的字符（不包括换行符），并在末尾添加空字符 oh!shit!
	gets(ar);
	fprintf(stdout,"please input file's name2:");
	gets(br);
	if(ar[0]=='\0'||br[0]=='\0')
	{
		fprintf(stderr,"Error!");
		exit(1);
	}
	if(strcmp(ar,br)==0)
	{
		fprintf(stderr,"Error!!");
		exit(2);
	}
	if((file1=fopen(ar,"r"))==NULL)
	{
		fprintf(stderr,"Error!!!");
		exit(3);
	}
	if((file2=fopen(br,"w"))==NULL)
	{
		fprintf(stderr,"Error!!!!");
		exit(4);
	}
	fread(temp,sizeof(char),1024,file1);
	//setvbuf(file1,NULL,_IOFBF,2048);
	for(i=0;i<1024;i++)
		temp[i]=toupper(temp[i]);
	i=fwrite(temp,sizeof(char),1024,file2);
	//setvbuf(file2,NULL,_IOFBF,2048);
	fprintf(stdout,"it return %d numbers successful!",i);
	fclose(file1);
	fclose(file2);
	exit(0);
}