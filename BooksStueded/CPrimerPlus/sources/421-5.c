#include <stdio.h>
#include <time.h>
#include <string.h>
#define CSIZE 4
struct name{
	char ming[10];
	char xing[20];
};
struct student{
	struct name mz;
	float grade[3];
	float avg_m;
};
void rand_ch(struct student ar[]);
void d(struct student ar[]);
void e(struct student ar[]);
void f(struct student ar[]);
int main(void)
{
	struct student line[CSIZE];
	int i,j;
	char k;
	rand_ch(line);
	/*for(i=0;i<CSIZE;i++)
		puts(line[i].mz.ming);*/
	while(scanf("%c",&k)==1)
	{
		while(getchar()!='\n')
			continue;
		fprintf(stdout,"(d)  (e)  (f)  (g)\n");
		switch(k)
		{
			case 'd':d(line);break;
			case 'e':e(line);break;
			case 'f':f(line);break;
			case 'g':break;
		}
		fscanf(stdin,"continue:\n");
	}
	return 0;
}
void f(struct student ar[])
{
	int i;
	for(i=0;i<CSIZE;i++)
	{
		fprintf(stdout,"[%d]:\n",i+1);
		fprintf(stdout,"studname:%s  stumark(1):%.2f  stumark(2):%.2f  stumark(3):%.2f",ar[i].mz.xing,ar[i].grade[0],ar[i].grade[1],ar[i].grade[2]);
		fprintf(stdout,"\n         avg:%f\n",ar[i].avg_m);
	}
}
void e(struct student ar[])
{
	int i;
	for(i=0;i<CSIZE;i++)
		ar[i].avg_m=(ar[i].grade[0]+ar[i].grade[1]+ar[i].grade[2])/3;
}
void d(struct student ar[])
{
	int i=0;
	fprintf(stdout,"Please input your name(x):\n");
	while(gets(ar[i].mz.xing)!=NULL&&ar[i].mz.xing[0]!='\0')
	{
		fprintf(stdout,"Please input your name(m):\n");
		gets(ar[i].mz.ming);
		fprintf(stdout,"Please input your mark:");
		scanf("%f %f %f",&ar[i].grade[0],&ar[i].grade[1],&ar[i].grade[2]);
		i++;
		while(getchar()!='\n')
			continue;
	}
}
void rand_ch(struct student ar[])
{
	int i,j,csize;
	char part[11]={'\0'};
	srand(time(0));
	for(i=0;i<CSIZE;i++)
	{
		part[0]=(int)((rand()%26+1)+64);
		csize=(int)(rand()%10+1);
		for(j=1;j<csize;j++)
			part[j]=(int)((rand()%26+1)+96);
		strcpy(ar[i].mz.ming,part);
	}
}