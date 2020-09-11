#include <stdio.h>
#include <string.h>
void input(int n,int m,char ar[n][m]);
int bill(int n,int m,char ar[n][m]);
void bill_1(int m,char ar[][m]);
void bill_2(int n,int m,char ar[n][m]);
void bill_3(int n,int m,char ar[n][m]);
void bill_4(int n,int m,char ar[n][m]);
void ceshi(int n,int m,char ar[n][m]);
void show(int n,int m,char ar[n][m]);
void ch_fan(char *ar);
int main(void)
{
	int w=1;
	int list=0;
	char ch[10][100]={'\0'};
	for(w=0;w<80;w++)
		printf("━");	
	printf("输入10个字符串：");
	input(10,100,ch);
	for(w=0;w<40;w++)
		printf("━");
	do
	{
		printf("\n┏");
		for(w=0;w<38;w++)
			printf("━");
		printf("┓");
		printf("\n┃                             [  菜单  ]                                     ┃\n");
		printf("┃  (1)输出初始字符串列表。        (2)按ASCII顺序输出字符串。                 ┃\n");
		printf("┃  (3)按长度递增顺序输出字符串。  (4)按字符串中第一个单词的长度输出字符串。  ┃\n");
		printf("┃  (5)退出!                                                                  ┃\n");
		printf("┗");
		for(w=0;w<38;w++)
			printf("━");
		printf("┛");
		list=bill(10,100,ch);
	}
	while(list!=0);
	return 0;
}
void bill_4(int n,int m,char ar[n][m])
{
	int j=0,i,s;
	printf("按第一个字符串长度显示所有字符串：\n");
	while(ar[0][j]!='\0')
		j++;
	for(i=0;i<n;i++)
	{
		printf("第%2d个字符串:[",i+1);
		for(s=0;s<j;s++)
			printf("%c",ar[i][s]);
		printf("]\n");
	}
}
void bill_3(int n,int m,char ar[n][m])
{
	int i=0,j=0;
	int num[n],js[10]={1,2,3,4,5,6,7,8,9,10};
	int xul=0,xu2=0;
	printf("按字符串长度顺序依次排序：\n");
	while(i<n)
	{
		while(ar[i][j]!='\0')
		{
			j++;
		}
		num[i]=j;
		i++;
		j=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(num[i]>num[j])
			{
				xul=num[j];
				num[j]=num[i];
				num[i]=xul;
				xu2=js[j];
				js[j]=js[i];
				js[i]=xu2;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("第%2d个字符串为第%2d个顺序：[",js[i],i+1);
		printf("%s",ar[js[i]-1]);
		printf("]\n");
	}
}
void bill_2(int n,int m,char ar[n][m])
{
	char *q;
	char a=0;
	int l,i,j=0,copy=0;
	char qr[10][100]={'\0'};
	while(copy<n)
	{
		strcpy(*(qr+copy),*(ar+copy));
		copy++;
	}
	for(l=0;l<10;l++)
	{
		for(i=0;i<100;i++)
		{
			if(qr[l][i+1]=='\0')
				break;
			for(j=i+1;j<100;j++)
			{
				if(qr[l][i]<qr[l][j])
				{
					a=qr[l][j];
					qr[l][j]=qr[l][i];
					qr[l][i]=a;
				}
			}
		}
		ch_fan(qr[l]);
	}
	show(n,m,qr);
}
void bill_1(int m,char ar[][m])
{
	int i;
	printf("初始字符串列表为:");
	for(i=0;i<m;i++)
	{
		printf("%c",ar[0][i]);
		if(ar[0][i]=='\0')
			break;
	}
}
int bill(int n,int m,char ar[n][m])
{
	int code,w;
	int list=0;
	for(w=0;w<40;w++)
		printf("━");
	printf("输入一个数字选择菜单:");
	scanf("%d",&code);
	for(w=0;w<40;w++)
		printf("━");
	switch(code)
	{
		case 1:bill_1(m,ar);break;
		case 2:bill_2(n,m,ar);break;
		case 3:bill_3(n,m,ar);break;
		case 4:bill_4(n,m,ar);break;
		case 5:printf("正在退出...............");return 0;;break;
		default:printf("输入无效!");
	}
}
void input(int n,int m,char ar[n][m])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(i==0)
			printf("第(%2d)个：",i+1);
		else
			printf("                第(%d)个：",i+1);
		for(j=0;j<m;j++)
		{
			ar[i][j]=getchar();
			if(ar[i][j]=='\n')
			{
				ar[i][j]='\0';
				break;
			}
		}
	}
}
void ceshi(int n,int m,char ar[n][m])
{
	int i,j,s=0;
	for(i=0;i<n;i++)
	{
		printf("[%2d]:",i+1);
		while(ar[i][s]!='\0')
			s++;
		for(j=0;j<(s+1);j++)
		{
			printf("(%2d):[%c] ",j+1,ar[i][j]);
			if(((j+1)%5)==0)
				if(ar[i][j]!='\0')
					printf("\n     ");
		}
		printf("\n");
		s=0;
	}
}
void show(int n,int m,char ar[n][m])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("第%2d个字符串按ASCII排序后顺序为：[",i+1);
		for(j=0;j<m;j++)
		{
			putchar(ar[i][j]);
			if(ar[i][j]=='\0')
				break;
		}
		printf("]\n");
	}
}
void ch_fan(char *ar)
{
	int i=0,j,m;
	char ch;
	while(ar[i])
		i++;
	j=i;
	if(i%2!=0)
		i=(i-1)/2;
	else
		i=i/2;
	for(m=0;m<i;m++)
	{
		ch=*(ar+m);
		*(ar+m)=*(ar+(j-(m+1)));
		*(ar+(j-(m+1)))=ch;
	}
}