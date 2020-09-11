#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int i;
	double s=atof(argv[1]);
	for(i=1;i<atoi(argv[2]);i++)
		s=s*s;
	printf("%lf",s);
	return 0;
}
		