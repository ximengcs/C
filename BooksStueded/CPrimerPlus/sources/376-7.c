#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int eof_1=0,eof_2=0;
	FILE *file_1,*file_2;
	char ch;
	char name_1[10];
	char name_2[10];
	if(argc==3)
	{
		strcpy(name_1,argv[1]);
		strcpy(name_2,argv[2]);
	}
	else if(argc==1)
	{
		printf("Enter file's name1:");
		gets(name_1);
		printf("Enter file's name2:");
		gets(name_2);
	}
	else
	{
		printf("Error!");
		exit(1);
	}
	file_1=fopen(name_1,"r");
	//setvbuf(file_1,NULL,_IOFBF,1024);
	file_2=fopen(name_2,"r");
	//setvbuf(file_2,NULL,_IOFBF,1024);
	while(eof_1!=1||eof_2!=1)
	{
		while((ch=getc(file_1))!='\n'&&eof_1!=1)
		{
			if(ch==EOF)
				eof_1=1;
			putc(ch,stdout);
		}
		if(eof_1!=1)
			putc('\n',stdout);
		while((ch=getc(file_2))!='\n'&&eof_2!=1)
		{
			if(ch==EOF)
				eof_2=1;
			if(eof_2==1)
				putchar('\n');
			if(ch!=EOF)
				putc(ch,stdout);
		}
		if(eof_2!=1)
			putc('\n',stdout);
	}
	fclose(file_1);
	fclose(file_2);
	exit(0);
}
			
			
			
			