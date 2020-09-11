#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	FILE *file;
	char ch[40];
	if(argc!=3)
	{
		fprintf(stderr,"Error!");
		exit(1);
	}
	if((file=fopen(argv[2],"r"))==NULL)
	{
		fprintf(stderr,"Error!!");
		exit(2);
	}
	while(fgets(ch,40-1,file)!=NULL)
	{
		fputs(strstr(ch,argv[1]),stdout);
	}
	fprintf(stdout,"Done.");
	fclose(file);
	exit(0);
}