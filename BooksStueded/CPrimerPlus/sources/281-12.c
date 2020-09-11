#include <stdio.h>
void num_into(int n,int m,double ar[n][m]);
double num_avg(int m,double ar[]);
double avg_all(int n,int m,double ar[n][m]);
double num_max(int n,int m,double ar[n][m]);
int main(void)
{
	double num_grou[3][5],a1,a2,s;
	int n,m;
	printf("please input 15 numbers:");
	num_into(3,5,num_grou);
	for(n=0;n<3;n++)
		printf("第%d个数集平均值为:%.2lf：\n\n",n+1,num_avg(5,*(num_grou+n)));
	printf("总平均值为：%.2lf\n",avg_all(3,5,num_grou));
	printf("\n最大值为：%.2lf\n\n!!!!!!!!!!!!!!!\n!!!!Perfect!!!!\n!!!!!!!!!!!!!!!",num_max(3,5,num_grou));
	return 0;
}
void num_into(int n,int m,double ar[n][m])
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%lf",*(ar+i)+j);
}
double num_avg(int m,double ar[])
{
	double s;
	int j;
	for(s=0,j=0;j<m;j++)
		s+=*(ar+j);
	s=s/m;
	return s;
}
double avg_all(int n,int m,double ar[n][m])
{
	int i,j;
	double s=0,z=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			s+=*(*(ar+i)+j);
	}
	s=s/(n*m);
	return s;
}
double num_max(int n,int m,double ar[n][m])
{
	int i,j;
	double s=**ar;
	for(i=0;i<n;i++)
		for(j=1;j<m;j++)
			if( (*(*(ar+i)+j)) > s )
				s=*(*(ar+i)+j);
	return s;
}