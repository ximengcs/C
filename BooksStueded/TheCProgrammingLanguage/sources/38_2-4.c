#include <stdio.h>
void squeeze(char s1[],char s2[])
{
	int i,j,k=0;
	int count = 0;
	while(s2[count] != '\0')
		count++;
	for( i = j = 0; s1[i] != '\0' ; i = i + k +1)
	{
		if( s1[i] != s2[0])
			s1[j++] = s1[i];
		else
		{
			for(k =0 ;k < count;)
			{
				if(s1[i+k+1] == s2[k+1])
					k++;
				else
					break;
			}
		}
		s1[j]= '\0';
	}
}
int main(void)
{
	char a[10],b[10];
	gets(a);
	gets(b);
	squeeze(a,b);
	int i;
	for(i = 0; a[i] != '\0' ; i++)
		putchar(a[i]);
	return 0;
}