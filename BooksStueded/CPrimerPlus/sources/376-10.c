#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	FILE *file;
	long point;
	char name[40];
	char ch[40];
	gets(name);
	if((file=fopen(name,"r"))==NULL)
	{
		fprintf(stderr,"Error");
		exit(1);
	}
	while(scanf("%ld",&point)==1)
	{
		fseek(file,point,SEEK_SET);
		fgets(ch,40-1,file);
		fputs(ch,stdout);
	}
	fprintf(stdout,"Done!");
	exit(0);
}
		