#include <stdio.h>
#include <stdlib.h>

char *my_strcpy( char *s1, const char *s2, int n );

int main( void )
{
	char a[10] = "fdafds";
	char b[20] = "adsfsdffsdaasdf";
	
	my_strcpy( a, b, 10 );
	puts( a );
}

char *my_strcpy( char *s1, const char *s2, int n )
{
	register int i;
	
	i = 0;
	while( i < n-1 || *s2 == '\0' ){
		*(s1+i) = *s2++;
		i++;
	}
	*(s1+i) = '\0';
	
	return s1;
}