#include <stdio.h>
void num_grou(float (*ar)[4],float (*br)[4],int x,int y);
void show(float (*xx)[4],int x,int y);
int main(void)
{
	float xr[2][4]={{1,2,3,4},{5,6,7,8}};
	float yr[2][4];
	num_grou(xr,yr,2,4);
	show(xr,2,4);
	show(yr,2,4);
	return 0;
}
void num_grou(float (*ar)[4],float (*br)[4],int x,int y)
{
	int m,n;
	for(n=0;n<x;n++)
		for(m=0;m<y;m++)
			br[n][m]=ar[n][m];
}
void show(float (*xx)[4],int x,int y)
{
	int m,n;
	for(m=0;m<x;m++)
		for(n=0;n<y;n++)
			printf("%.2f ",*(*(xx+m)+n));
}