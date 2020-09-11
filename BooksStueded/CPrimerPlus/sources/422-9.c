#include <stdio.h>
#include <stdlib.h>
struct plane_modle{
	int seat_num;
	int whether;
	char ming[40];
	char xing[40];
};
void menu_show(char *);
void a(int,struct plane_modle []);
void c(int,struct plane_modle []);
void d(int,struct plane_modle [][12]);
void e(int,struct plane_modle []);
int change(int);
int main(void)
{
	struct plane_modle plane[4][12]={{{.seat_num=1,.whether=0},{.seat_num=2,.whether=0},{.seat_num=3,.whether=0},{.seat_num=4,.whether=0},
	{.seat_num=5,.whether=0},{.seat_num=6,.whether=0},{.seat_num=7,.whether=0},{.seat_num=8,.whether=0},
	{.seat_num=9,.whether=0},{.seat_num=10,.whether=0},{.seat_num=11,.whether=0},{.seat_num=12,.whether=0}},
	{{.seat_num=1,.whether=0},{.seat_num=2,.whether=0},{.seat_num=3,.whether=0},{.seat_num=4,.whether=0},
	{.seat_num=5,.whether=0},{.seat_num=6,.whether=0},{.seat_num=7,.whether=0},{.seat_num=8,.whether=0},
	{.seat_num=9,.whether=0},{.seat_num=10,.whether=0},{.seat_num=11,.whether=0},{.seat_num=12,.whether=0}},
	{{.seat_num=1,.whether=0},{.seat_num=2,.whether=0},{.seat_num=3,.whether=0},{.seat_num=4,.whether=0},
	{.seat_num=5,.whether=0},{.seat_num=6,.whether=0},{.seat_num=7,.whether=0},{.seat_num=8,.whether=0},
	{.seat_num=9,.whether=0},{.seat_num=10,.whether=0},{.seat_num=11,.whether=0},{.seat_num=12,.whether=0}},
	{{.seat_num=1,.whether=0},{.seat_num=2,.whether=0},{.seat_num=3,.whether=0},{.seat_num=4,.whether=0},
	{.seat_num=5,.whether=0},{.seat_num=6,.whether=0},{.seat_num=7,.whether=0},{.seat_num=8,.whether=0},
	{.seat_num=9,.whether=0},{.seat_num=10,.whether=0},{.seat_num=11,.whether=0},{.seat_num=12,.whether=0}}};
	struct plane_modle modle;
	int count=0,count_file=0,count1=0,count2=0,hangban;
	FILE *file;
	char code='g';
	int ar[12],ari=0;
	int size=sizeof(struct plane_modle);
	if((file=fopen("file_part","rb"))==NULL)
	{
		fprintf(stderr,"打开文件错误!");
		exit(1);
	}
	rewind(file);
	while(count1<4)
	{
		while(count2<12 && fread(&plane[count1][count2],size,1,file)==1)
		{
		if(plane[count1][count2].whether==1)
			count_file++;
		else{
			ar[ari]=plane[count1][count2].seat_num;
			ari++;
		}
		count2++;
		}
		count+=count2;
		count2=0;
		count1++;
	}
	count=count_file;
	if(fclose(file)!=0)
	{
		fprintf(stderr,"未知错误");
		exit(2);
	}
	printf("航班号：102\n        311\n        444\n        519\n请输入航班(输入888退出)：");
	
	while(scanf("%d",&hangban)!=1 || (hangban=change(hangban))==-1)
	{
		while(getchar()!='\n')
			continue;
		printf("请输入正确的航班号(输入888退出):");
	}
	while(1)
	{
		switch(hangban)
		{
			case 0:
			while(1)
			{
				printf("102航班\n");
					switch(code)
					{
						case 'a':a(count,plane[hangban]);menu_show(&code);continue;
						case 'b':a(count,plane[hangban]);menu_show(&code);continue;
						case 'c':c(count,plane[hangban]);menu_show(&code);continue;
						case 'd':d(0,plane),menu_show(&code);continue;
						case 'e':e(count,plane[hangban]),menu_show(&code);continue;
						case 'g':menu_show(&code);continue;
						case 'f':break;
					}
					break;
			}
			printf("航班号：102\n        311\n        444\n        519\n请输入航班(输入888退出)：");
	while(scanf("%d",&hangban)!=1 || (hangban=change(hangban))==-1)
	{
		getchar();
		printf("请输入正确的航班号(输入888退出):");
	}
			code='g';
			break;
			case 1:
			while(1)
			{
				printf("311航班\n");
					switch(code)
					{
						case 'a':a(count,plane[hangban]);menu_show(&code);continue;
						case 'b':a(count,plane[hangban]);menu_show(&code);continue;
						case 'c':c(count,plane[hangban]);menu_show(&code);continue;
						case 'd':d(1,plane),menu_show(&code);continue;
						case 'e':e(count,plane[hangban]),menu_show(&code);continue;
						case 'g':menu_show(&code);continue;
						case 'f':break;
					}
					break;
			}
			printf("航班号：102\n        311\n        444\n        519\n请输入航班(输入888退出)：");
	while(scanf("%d",&hangban)!=1 || (hangban=change(hangban))==-1)
	{
		printf("请输入正确的航班号(输入888退出):");
	}
			code='g';
			break;
			case 2:
			while(1)
			{
				printf("444航班\n");
					switch(code)
					{
						case 'a':a(count,plane[hangban]);menu_show(&code);continue;
						case 'b':a(count,plane[hangban]);menu_show(&code);continue;
						case 'c':c(count,plane[hangban]);menu_show(&code);continue;
						case 'd':d(2,plane),menu_show(&code);continue;
						case 'e':e(count,plane[hangban]),menu_show(&code);continue;
						case 'g':menu_show(&code);continue;
						case 'f':break;
					}
					break;
			}
			printf("航班号：102\n        311\n       444\n       519\n请输入航班(输入888退出)：");
	while(scanf("%d",&hangban)!=1 || (hangban=change(hangban))==-1)
	{
		while(getchar()!='\n')
			continue;
		printf("请输入正确的航班号(输入888退出):");
	}
			code='g';
			break;
			case 3:
			while(1)
			{
				printf("519航班\n");
					switch(code)
					{
						case 'a':a(count,plane[hangban]);menu_show(&code);continue;
						case 'b':a(count,plane[hangban]);menu_show(&code);continue;
						case 'c':c(count,plane[hangban]);menu_show(&code);continue;
						case 'd':d(3,plane),menu_show(&code);continue;
						case 'e':e(count,plane[hangban]),menu_show(&code);continue;
						case 'g':menu_show(&code);continue;
						case 'f':break;
					}
					break;
			}
			printf("航班号：102\n        311\n       444\n       519\n请输入航班(输入888退出)：");
	while(scanf("%d",&hangban)!=1 || (hangban=change(hangban))==-1)
	{
		while(getchar()!='\n')
			continue;
		printf("请输入正确的航班号(输入888退出):");
	}
			code='g';
			break;
			case 4:printf("Bye");exit(0);
		}		
	
	}
}
int change(int s)
{
	if(s==102)
		return 0;
	else if(s==311)
		return 1;
	else if(s==444)
		return 2;
	else if(s==519)
		return 3;
	else if(s==888)
		return 4;
	else return -1;
}
void e(int count,struct plane_modle plane[])
{
	FILE *file;
	int num,i=0;
	printf("输入要取消的座位编号:");
	while(scanf("%d",&num)!=1)
	{
		printf("请输入正确的编号:");
		while(getchar()!='\n')
			continue;
	}
	plane[num-1].whether=0;
	if((file=fopen("file_part","wb"))==NULL)
	{
		printf("删除出现未知错误!");
	}
	else
	{
		rewind(file);
		while(i<12 && fwrite(&plane[i],sizeof(struct plane_modle),1,file))
		{
			i++;
			continue;
		}
		printf("取消完成\n");
		while(getchar()!='\n')
			continue;
	}
}
void d(int count,struct plane_modle plane[][12])
{
	int num,i=0,j=0;
	char ming[40],xing[40];
	FILE *file;
	printf("请输入要预定的座位号:");
	while(scanf("%d",&num)!=1)
	{
		printf("请输入正确的座位号(1-12):");;
	}
	while(getchar()!='\n')
		continue;
	printf("请输入您的名:");
	gets(plane[count][num-1].ming);
	printf("请输入您的姓:");
	gets(plane[count][num-1].xing);
	plane[count][num-1].whether=1;
	if((file=fopen("file_part","wb"))==NULL)
	{
		fprintf(stderr,"写入错误!未保存");
	}
	else
	{
		j=0;
		rewind(file);
		fwrite(&plane[0][0],sizeof(struct plane_modle),12,file);
		fwrite(&plane[1][0],sizeof(struct plane_modle),12,file);
		fwrite(&plane[2][0],sizeof(struct plane_modle),12,file);
		fwrite(&plane[3][0],sizeof(struct plane_modle),12,file);
		fclose(file);
	}
}
void c(int count,struct plane_modle plane[])
{
	int num[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int ch;
	int i,j;
	for(i=0;i<12;i++)
	{
		for(j=i+1;j<12;j++)
		{
			if(plane[i].xing[0]<plane[j].xing[0])
			{
				ch=num[i];
				num[i]=num[j];
				num[j]=ch;
			}
		}
	}
	printf("编号 是否分配   名    姓\n");
	for(i=0;i<12;i++)
	{
		if(plane[num[i]-1].whether==1)
		{
			printf(" %02d      是     %-5s  %-5s \n",plane[num[i]-1].seat_num,
			plane[num[i]-1].ming,plane[num[i]-1].xing);
		}
	}
	putchar('\n');
}
void a(int count,struct plane_modle plane[])
{
	int i=0;
	printf("共有%d个空坐位，编号分别为:",12-count);
	while(i < 12)
	{
		if(plane[i].whether==0)
			printf(" %02d ",plane[i].seat_num);
		i++;
	}
	putchar('\n');
}
void menu_show(char *code)
{
	printf("输入一个选项，按回车键确认:\n");
	printf("a)显示空座位编号\n");
	printf("b)显示空座位名单\n");
	printf("c)按客户姓名首字母排序显示座位\n");
	printf("d)安排一个新座位\n");
	printf("e)取消一个座位\n");
	printf("f)退出\n");
	while(*code=getchar())
	{
		if(*code=='a')
			break;
		else if(*code=='b')
			break;
		else if(*code=='c')
			break;
		else if(*code=='d')
			break;
		else if(*code=='e')
			break;
		else if(*code=='f')
			break;
		else {
		printf("请正确输入选项:\n");
		}
	}
}