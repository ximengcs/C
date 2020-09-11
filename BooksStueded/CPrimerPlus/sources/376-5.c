#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int i;
	char ch[256];
	char ar;
	FILE *file;
	ar=argv[1][0];
	if(argc!=3)
	{
		fprintf(stderr,"Error!");
		exit(1);
	}
	file=fopen(argv[2],"r");
	while(fgets(ch,256,file)!=NULL)
	{
		for(i=0;i<256;i++)
		{
			if(ar==ch[i])
			{
				fprintf(stdout,"%s",ch);
				break;
			}
		}
	}
	exit(0);
	return 0;
}