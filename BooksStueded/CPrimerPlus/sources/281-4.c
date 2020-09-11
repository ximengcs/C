#include <stdio.h>
float num_grou(float ar[],int n);
int main(void)
{
	float br[5]={1.2,2.3,3.4,4.5,5.6};
	float i;
	i=num_grou(br,5);
	printf("%f",i);
	return 0;
}
float num_grou(float ar[],int n)
{
	int s1;
	float s=(*ar);
		for(s1=1;s1<n;s1++)
			if(s<(*(ar+s1)))
				s=(*(ar+s1));
	return s;
}