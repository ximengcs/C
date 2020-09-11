#include <stdio.h>
int num_grou(int ar[],int n);
int main(void)
{
	int a;
	int ar[5]={22,34,78,25,685};
	a=num_grou(ar,5);
	printf("%d",a);
}
int num_grou(int ar[],int n)
{
	int s1,s=0;
	for(s1=1,s=*ar;s1<n;s1++)
		if(s<(*(ar+s1)))
			s=*(ar+s1);
		return s;
}