#include <stdio.h>
int n,weight,sum=0;
int judge(int a)
{
	if(a>0&&a<=10) return 50;
	if(a>10&&a<=100) return 180;
	if(a>100&&a<=300) return 300;
	if(a>300&&a<=1000) return 1000;
	if(a>1000&&a<=3000) return 2000;
	if(a>3000) return -1;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&weight);
		if(judge(weight)<0)
			goto out;
		sum+=judge(weight);
	}
	printf("%d",sum);
	return 0;
	out:
	printf("Can¡¯t transport!");
	return 0;
}
