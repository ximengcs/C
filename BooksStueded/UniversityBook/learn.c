#include <stdio.h>
long fact(int n);
long rfact(int n);
int main (void)
{
	int num;
	while (scanf ("%d",&num)==1)
	{
		if (num<0)
			printf("no negative");
		else if(num>12)
			printf("keep input");
		else{
			printf("loop:%d fact=%ld\n",num,fact(num));
			printf("recursion:%d factorial=%ld\n",num,rfact(num));
		}
		printf("enter a in the 0-12\n");
	}
	printf("bye\n");
	return 0;
}
long fact (int n)
{
	long ans;
	for (ans = 1;n>1;n--)
		ans*=n;
	return ans;
}
long rfact (int n)
{
	long ans;
	if (n>0)
		ans=n*rfact(n-1);
	else
		ans=1;
	return ans;
}