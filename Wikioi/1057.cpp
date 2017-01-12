#include<stdio.h>
int main()
{
	int j,a;
	int n=0,s=0,m,i;
	bool flag=true;
	for(j=0;j<12;j++)
	{
		scanf("%d",&a);
		n+=300-a;
		if(n<0&&flag)
		{
			i=j+1;
			flag=false;
		}
		m=n/100;
		n-=m*100;
		s+=m*100;
	}
	if(flag)
		printf("%d\n",n+s*6/5);
	else
		printf("-%d\n",i);
	return 0;
} 
