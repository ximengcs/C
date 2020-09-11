#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	size_t code;
	FILE *file1;
	FILE *file2;
	char ar[2048];
	if(argc!=3)
	{
		fprintf(stderr,"Error!");
		exit(1);
	}
	if(strcmp(argv[1],argv[2])==0)
	{
		fprintf(stderr,"Error!!");
		exit(2);
	}
	if((file1=fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr,"Error!!!");
		exit(3);
	}
	//setvbuf(file1,NULL,_IOFBF,1024);
	if((file2=fopen(argv[2],"w"))==NULL)
	{
		fprintf(stderr,"Error!!!!");
		exit(4);
	}
	//setvbuf(file2,NULL,_IOFBF,1024);
	code=fread(ar,sizeof(char),2048,file1);
	fwrite(ar,sizeof(char),code,file2);
	fclose(file1);
	fclose(file2);
	return 0;
}
	