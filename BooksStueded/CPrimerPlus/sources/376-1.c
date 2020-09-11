#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int ch;
	FILE *fp;
	long count=0;
	char ar[10];
	gets(ar);
	if(ar[0]=='\n')
	{
		printf("Usage:1.exe filename\n");
		exit(1);
	}
	if((fp=fopen(ar,"r"))==NULL)
	{
		fprintf(stderr,"Can't open %s\n",ar);
		exit(2);
	}
	while((ch=getc(fp))!=EOF)
	{
		putc(ch,stdout);
		count++;
	}
	putchar('\n');
	fclose(fp);
	printf("File %s has %ld characters\n",ar,count);
	return 0;
}
	