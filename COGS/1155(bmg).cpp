#include <stdio.h>
#define N 100
int main()
{
	int n,flag;
	int a[142];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==3)
			printf("1 2/n2/n");
		else if(n==4)
			printf("1 3/n3/n");
		else
		{
			
			int i=2,num=0,j;
			long result[N]={1};
			while (1)   //存放分解后的数
			{
				a[num]=i;
				n-=i;
				i++;
				num++;
				if(n<=i-1)
					break;
			}
			if(n==a[num-1])   //和前一个数相等的时候，会多出一位，所以倒数第二总的加2
			{
				for(i=0;i<num;i++)
					a[i]++;
				a[num-1]++;
			}
			else
			{
				for(i=num-1,j=0;j<n;j++,i--)
					a[i]++;
			}
			for(i=0;i<num;i++)
			{
				printf("%d",a[i]);
				if(i!=num-1)
					printf(" ");
			}
			printf("\n");
			for(i=0;i<=num-1;i++)
			{
				for(j=0;j<N;j++)
				{
					if(result[j]!=0)
						result[j]=result[j]*a[i];
				}
				for(j=0;j<N;j++)
				{
					if(result[j]!=0)
						while(result[j]>=10000)
						{
							long x=result[j]/10000;
							result[j+1]+=x;
							result[j]%=10000;
						}
				}
			}
			for(i=N-1;i>=0;i--)
			{
				if(result[i]!=0)
				{
					flag=i;    //首位不为0后的全部个数
					break;
				} 
			}
			printf("%ld",result[flag]);   //首位的0不记，先输出
			for(i=flag-1;i>=0;i--)      //接下来的要判断是否缺少0了，缺了就补上
			{
				printf("%4.4ld",result[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
