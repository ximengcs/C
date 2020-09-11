#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main(void)
{
	FILE *in,*out;
	int ch;
	char name[LEN]={'\0'};
	char qr[LEN]={'\0'};
	int count=0;
	gets(qr);
	if(qr[0]=='\0')
	{
		fprintf(stderr,"Usage:a.exe filename\n");
		exit(1);
	}
	if((in=fopen(qr,"r"))==NULL)
	{
		fprintf(stderr,"I couldn't open the file\"%s\"\n",qr);
		exit(2);
	}
	strcpy(name,qr);
	strcat(name,".red");
	if((out=fopen(name,"w"))==NULL)
	{
		fprintf(stderr,"Can't create output file.\n");
		exit(3);
	}
	while((ch=getc(in))!=EOF)
		if(count++%3==0)
			putc(ch,out);
	if(fclose(in)!=0||fclose(out)!=0)
			fprintf(stderr,"Error in closing files\n");
	return 0;
}