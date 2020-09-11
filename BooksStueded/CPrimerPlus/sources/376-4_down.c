#include <stdio.h>
#include <stdlib.h>
void read(char ar[],char br[],int i);
int main(int argc,char *argv[])
{
	char ar[argc-1][128];
	FILE *file;
	char ch[argc-1][10];
	int i,j,l;
	for(i=0;i<(argc-1);i++)
	{
		read(ar[i],argv[i+1],i);
		fprintf(stdout,"%s:\n",argv[i+1]);
		for(l=0;l<80;l++)
			putchar('-');
		for(j=0;j<128;j++)
			putc(ar[i][j],stdout);
		putchar('\n');
		for(l=0;l<80;l++)
			putchar('-');
	}
	exit(0);
}
void read(char ar[],char br[],int i)
{
	FILE *file;
	file=fopen(br,"r");
	//setvbuf(file,NULL,_IOFBF,1024);
	fread(ar,sizeof(char),128,file);
	fclose(file);
}
