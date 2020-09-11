#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct modle{
	int id;
	char ming[10];
	char xing[10];
	int persent;
	int jiz;
	int zol;
	int rbi;
	float avg;
};
void show(struct modle [],int);
int make(struct modle []);
char * make_a(int,int);
void wfile(struct modle [],char *,int);
int main(void)
{
	FILE *file;
	int i,t,count,j,ar;
	struct modle person[30];
	struct modle two[30];
	int ch[30][5]={0};
	char file_name[10]={"Polo"};
	t=make(person);
	wfile(person,file_name,t);
	file=fopen(file_name,"rb");
	for(i=0;i<t;i++)
	{
		fread(&two[i],sizeof(struct modle),1,file);
		getc(file);
	}
	fclose(file);
	ch[0][0]=two[0].id;
	ch[0][1]=two[0].persent;
	ch[0][2]=two[0].jiz;
	ch[0][3]=two[0].zol;
	ch[0][4]=two[0].rbi;
	count=1;
	for(i=1;i<t;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(ch[j][0]==two[i].id)
			{
				ch[j][1]+=two[i].persent;
				ch[j][2]+=two[i].jiz;
				ch[j][3]+=two[i].zol;
				ch[j][4]+=two[i].rbi;
				break;
			}
			else if(j==i)
			{
				ch[count][0]=two[i].id;
				ch[count][1]+=two[i].persent;
				ch[count][2]+=two[i].jiz;
				ch[count][3]+=two[i].zol;
				ch[count][4]+=two[i].rbi;
				count++;
				break;
			}
		}
	}
	/*for(i=0;i<count;i++)
	{
		for(j=0;j<5;j++)
			printf(" %2d ",(int)ch[i][j]);
		putchar('\n');
	}	
	for(i=0;i<t;i++)
		show(two,i);*/
	printf("ID    名    姓     上场次数 击中数 走垒数 跑点数 击球平均率\n");
	for(i=0;i<60;i++)
		putchar('-');
	putchar('\n');
	for(i=0;i<count;i++)
	{
		for(j=0;j<t;j++)
		{
			if(ch[i][0]==two[j].id)
			{
				printf("%-2d  %s %s ",ch[i][0],two[j].ming,two[j].xing);
				printf("    %-2d      %-2d    %-2d    %-2d        %.0f%%\n",ch[i][1],ch[i][2],ch[i][3],ch[i][4],(float)ch[i][2]/ch[i][1]*100);
				break;
			}
		}
	}
	for(i=0;i<60;i++)
		putchar('-');
	putchar('\n');
	return 0;
}
void wfile(struct modle person[],char * name,int t)
{
	FILE *file;
	int i;
	char space='\n';
	if((file=fopen(name,"wb+"))==NULL)
	{
		fprintf(stderr,"打开文件出错!");
		exit(1);
	}
	rewind(file);
	for(i=0;i<t;i++)
	{
		fwrite(&person[i],sizeof(struct modle),1,file);
		fwrite(&space,sizeof(char),1,file);
	}
	fclose(file);
}
void show(struct modle person[],int i)
{
	printf("%-2d %s %s ",person[i].id,person[i].ming,person[i].xing);
	printf("%-2d %-2d %d %d %.0f%%\n",person[i].persent,person[i].jiz,person[i].zol,person[i].rbi,person[i].avg*100);
}
int make(struct modle person[])
{
	int i,t,l;
	srand(time(0));
	t=(int)(rand()%30+1);
	for(i=0;i<t;i++)
	{
		l=rand()%19;
		person[i].id=l;
		strcpy(person[i].ming,make_a(l,1));
		strcpy(person[i].xing,make_a(l,2));
		person[i].persent=(int)(rand()%10+1);
		person[i].jiz=(int)(rand()%person[i].persent+1);
		person[i].zol=(int)(rand()%2);
		person[i].rbi=(int)(rand()%2);
	}
	return t;
}
char *make_a(int i,int j)
{
	switch(i)
	{
		case 0:if(j==1) return "Aessie"; else return "Aoybat";
		case 1:if(j==1) return "Bessie"; else return "Boybat";
		case 2:if(j==1) return "Cessie"; else return "Coybat";
		case 3:if(j==1) return "Dessie"; else return "Doybat";
		case 4:if(j==1) return "Eessie"; else return "Eoybat";
		case 5:if(j==1) return "Fessie"; else return "Foybat";
		case 6:if(j==1) return "Gessie"; else return "Goybat";
		case 7:if(j==1) return "Hessie"; else return "Hoybat";
		case 8:if(j==1) return "Iessie"; else return "Ioybat";
		case 9:if(j==1) return "Jessie"; else return "Joybat";
		case 10:if(j==1) return "Kessie"; else return "Koybat";
		case 11:if(j==1) return "Kessie"; else return "Koybat";
		case 12:if(j==1) return "Lessie"; else return "Loybat";
		case 13:if(j==1) return "Messie"; else return "Moybat";
		case 14:if(j==1) return "Nessie"; else return "Noybat";
		case 15:if(j==1) return "Oessie"; else return "Ooybat";
		case 16:if(j==1) return "Pessie"; else return "Poybat";
		case 17:if(j==1) return "Qessie"; else return "Qoybat";
		case 18:if(j==1) return "Ressie"; else return "Roybat";
	}
}