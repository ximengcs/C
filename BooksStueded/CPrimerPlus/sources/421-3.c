#include <stdio.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(void)
{
	struct book library[MAXBKS];
	int librarys[MAXBKS];
	int ch;
	int count=0;
	int index,j;
	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while(count<MAXBKS&&gets(library[count].title)!=NULL&&library[count].title[0]!='\0')
	{
		printf("Now enter the author.\n");
		gets(library[count].author);
		printf("Now enter the value.\n");
		scanf("%f",&library[count++].value);
		while(getchar()!='\n')
			continue;
		if(count<MAXBKS)
			printf("Enter the next title.\n");
	}
	if(count>0)
	{
		printf("Here is the list of your books.\n");
		for(index=0;index<count;index++)
			printf("%s by %s:$%.2f\n",library[index].title,library[index].author,library[index].value);
	}
	else
		printf("No books?Too bad.\n");
	for(index=0;index<count;index++)
		librarys[index]=index;
	for(index=0;index<count;index++)
	{
		for(j=index+1;j<count;j++)
			if(library[index].title[0]>library[j].title[0])
			{
				ch=librarys[j];
				librarys[j]=librarys[index];
				librarys[index]=ch;
			}
	}
	if(count>0)
	{
		printf("Here is the list of your books(book's name).\n");
		for(index=0;index<count;index++)
			printf("%s by %s:$%.2f\n",library[librarys[index]].title,library[librarys[index]].author,library[librarys[index]].value);
	}
	else
		printf("No books?Too bad.\n");
	for(index=0;index<count;index++)
		librarys[index]=index;
	for(index=0;index<count;index++)
		for(j=index+1;j<count;j++)
		{
			if(library[index].value>library[j].value)
			{
				ch=librarys[j];
				librarys[j]=librarys[index];
				librarys[index]=ch;
			}
		}s
	if(count>0)
	{
		printf("Here is the list of your books(value).\n");
		for(index=0;index<count;index++)
			printf("%s by %s:$%.2f\n",library[librarys[index]].title,library[librarys[index]].author,library[librarys[index]].value);
	}
	else
		printf("No books?Too bad.\n");
	return 0;
}