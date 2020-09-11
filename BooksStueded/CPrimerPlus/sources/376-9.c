#include <stdio.h>
#include <stdlib.h>
#define MAX 40
int main(void)
{
	int count=0;
	FILE *fp;
	char words[MAX];
	if((fp=fopen("words.txt","a+"))==NULL)
	{
		fprintf(stderr,"Can't open \"words\" file.\n");
		exit(1);
	}
	rewind(fp);
	while((fgets(words,MAX-1,fp))!=NULL)
		count++;
	puts("Enter words to add to the files:press the Enter");
	puts("Key at the beginning of a line to terminate.");
	while(gets(words)!=NULL&&words[0]!='\0')
		fprintf(fp,"%d:%s\n",count++,words);
	puts("File contents:");
	rewind(fp);
	while(fscanf(fp,"%s",words)==1)
		puts(words);
	if(fclose(fp)!=0)
		fprintf(stderr,"error");
	return 0;
}