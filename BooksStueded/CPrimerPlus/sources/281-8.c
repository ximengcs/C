#include <stdio.h>
void vla(int n,int m,int ar[n][m],int br[n][m]);
void vla_show(int n,int m,int ar[n][m]);
int main(void)
{
	int x=2,y=5;
	int x1[][5]={{1,2,3,4,5},{6,7,8,9,100}};
	int x2[x][y];
	vla(x,y,x1,x2);
	vla_show(x,y,x1);
	printf("\n");
	vla_show(x,y,x2);
	return 0;
}
void vla(int n,int m,int ar[n][m],int br[n][m])
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			br[i][j]=ar[i][j];
}
void vla_show(int n,int m,int ar[n][m])
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			printf("%d ",ar[i][j]);
}