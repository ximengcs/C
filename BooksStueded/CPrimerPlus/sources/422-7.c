#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(void)
{
	int option;
	struct book library[MAXBKS];
	char book_name[MAXTITL];
	int count=0,i,j,delete;
	int index,filecount;
	char eof=EOF;
	FILE *pbooks;
	int size=sizeof(struct book);
	if((pbooks=fopen("book","r+b"))==NULL)
	{
		fputs("Can't open book file\n",stderr);
		exit(1);
	}
	rewind(pbooks);
	while(count<MAXBKS&&fread(&library[count],size,1,pbooks)==1)
	{
		if(count==0)
			puts("Current contents of book:");
		printf("%s by %s:$%.2f\n",library[count].title,
			library[count].author,library[count].value);
		count++;
	}
	filecount=count;
	//printf("count=%d",count);
	printf("intput the option:");
	printf("\n(1):delete   (2):alter 输入q退出\n");
	while(scanf("%d",&option)==1)
	{
		getchar();
		switch(option)
		{
			case 1:if(count==0)
			{
				printf("文件中没有数据!");
				printf("\nintput the option:\n");
				break;
			}
					else
					{
						printf("输入要删除的书名:");
						delete=0;
						gets(book_name);
							for(i=0;i<count;i++)
							{
								if(strcmp(book_name,library[i].title)==0)
								{
									delete++;
									if(count==1)
									{
										rewind(pbooks);
										putc(EOF,pbooks);
										printf("已删除");
										break;
									}
									for(j=i+1;j<=count;j++)
									{
										strcpy(library[j-1].title,library[j].title);
										strcpy(library[j-1].author,library[j].author);
										library[j-1].value=library[j].value;
										
									
										break;
									}
									break;
								}
							}
						if(delete==0)
						{
							printf("没有找到%s",book_name);
							printf("\nintput the option:\n(1):delete   (2):alter 输入q退出\n");
							break;
						}
						else
						{
							fclose(pbooks);
							pbooks=fopen("book","wb+");
							rewind(pbooks);
							printf("count=%d,delete=%d",count,delete);
							fwrite(&library[0],size,count-delete,pbooks);
							printf("\n已删除%s\n",book_name);
						}
						count-=delete;
						printf("\nintput the option:\n(1):delete   (2):alter 输入q退出\n");
						break;
					}
			case 2:if(count==MAXBKS)
			{
				fputs("The book file if full.",stderr);
				exit(2);
			}
			puts("Add and new book titles.");
			while(count<MAXBKS&&gets(library[count].title)!=NULL&&library[count].title[0]!='\0')
			{
				puts("Now enter the author.");
				gets(library[count].author);
				puts("Now enter the value.");
				scanf("%f",&library[count++].value);
				getchar();
				if(count<MAXBKS)
					puts("Enter the next title.");
			}
			if(count>0)
			{
				puts("Here is the list of your books:");
				for(index=0;index<count;index++)
					printf("%s by %s:$%.2f\n",library[index].title,
						library[index].author,library[index].value);
				fwrite(&library[filecount],size,count-filecount,pbooks);
			}
			else
				puts("No books? Too bad.\n");
			while(getchar()!='\n')
				continue;
			break;
			case 3:exit(0);
		}
	}	
	printf("Bye.");
	fclose(pbooks);
	return 0;
}		