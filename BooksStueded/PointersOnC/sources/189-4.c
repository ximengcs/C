#include <stdio.h>
#include <stdlib.h>

char *my_strcat( char *s1, const char *s2, int n );

int main( void )
{
	char a[10] = "sfdgfs";
	char b[10] = "DFSGFGDF";
	
	my_strcat( a, b, 10 );
	
	puts( a );
}

char *my_strcat( char *s1, const char *s2, int n )
{
	int i;
	
	i = 0;
	/*
	**查找s1字符串的结尾
	*/
	while( *(s1+i) != '\0' )
		i++;
	
	while( i < n-1 || *s2 == '\0' ){
		*(s1+i) = *s2++;
		i++;
	}
	*(s1+i) = '\0';
	
	return s1;
}