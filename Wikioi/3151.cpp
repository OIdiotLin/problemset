#include <stdio.h>
int oneWay(int n)
{
	int sum=0; 
	for(int i=0;i<=n;i++)
		sum+=i;
	return sum;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",k*oneWay(n));
	return 0;
}
