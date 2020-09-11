#include <stdio.h>
float num_grou(float ar[],int n);
int main(void)
{
	float br[5]={213.23,213.23,43.2364,436.523,65.2134};
	float s;
	s=num_grou(br,5);
	printf("%f",s);
	return 0;
}
float num_grou(float ar[],int n)
{
	float num_min,num_max,num_2,num_c;
	int j;
	if(*ar<*(ar+1))
	{
		num_min=*ar;
		num_max=*(ar+1);
	}
	for(j=2;j<n;j++)
	{
		num_2=*(ar+j);
		if(num_max<num_2)
			num_max=num_2;
		if(num_min>num_2)
			num_min=num_2;
	}
	num_c=num_max-num_min;
	return num_c;
}