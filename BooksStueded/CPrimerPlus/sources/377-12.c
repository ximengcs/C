#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char qr(int n);
int main(void)
{
	FILE *file;
	int ar[20][31]={'\0'};
	int i,j,k;
	char ch=' ';
	if((file=fopen("math","wb+"))==NULL)
	{
		fprintf(stderr,"Error!");
		exit(1);
	}
	srand(time(0));
	for(i=0;i<20;i++)
		for(j=0;j<30;j++)
		{
			k=(int)(rand()%10);
			fwrite(&k,sizeof(int),1,file);
			fwrite(&ch,sizeof(char),1,file);
		}
	/*for(i=0;i<20;i++)
		for(j=0;j<30;j++)
		{
			scanf("%d",&k);
			fwrite(&k,sizeof(int),1,file);
			fwrite(&ch,sizeof(char),1,file);
		}*/
	rewind(file);
	for(i=0;i<20;i++)
	{
		for(j=0;j<30;j++)
		{
			fread(&ar[i][j],sizeof(int),1,file);
			fseek(file,1L,SEEK_CUR);
		}
		ar[i][j]='\0';
	}
	/*for(i=0;i<20;i++)
	{
		for(j=0;j<30;j++)
			printf("%d",ar[i][j]);
		putchar('\n');
	}*/
	for(i=0;i<20;i++)
	{
		for(j=0;j<30;j++)
			putchar(qr(ar[i][j]));
		putchar('\n');
	}
	exit(0);
}
char qr(int n)
{
	char ch[10]={' ','.','\'',':','~','*','$','=','%','#'};
	return ch[n];
}


