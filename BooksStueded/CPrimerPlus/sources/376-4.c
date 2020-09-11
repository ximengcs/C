#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int i=0,k=0;
	double s[100]={'\0'};
	double j=0;
	FILE *file;
	if(argc==1)
		file=stdin;
	else if(argc==2)
	{
		file=fopen(argv[1],"r");
	}
	else if(argc>2)
	{
		fprintf(stderr,"error!");
		exit(1);
	}
	fprintf(stdout,"输入数字，按非数字键结束输入:");
	while(fscanf(file,"%lf",&s[i])==1)
	{
		i++;
		k++;
	}
	for(i=0;i<k;i++)
		j=j+s[i];
	j=j/k;
	fprintf(stdout,"这%d个数的算数平均数为:%.2lf",k,j);
	if(argc==2)
		fclose(file);
	exit(0);
}