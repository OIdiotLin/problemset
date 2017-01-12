/*
	Name: Exponentiation
	Copyright: UVaOJ-748
	Author: LHD
	Date: 22/11/13 19:59
	Description: 高精度输出R^n。由于这里的R是个浮点数，所以要注意对小数点的处理:
				 先在输入时把小数点提取出来并记录位置，用普通乘法计算出结果后从后向前计算位置添加小数点。
				 循环变量有点伤，略多。 
*/
#include<stdio.h>
#include<string.h>
int part1[205],part2[205],temp[10];
int i,j,Index,a,b,c;
int bEqual;
char Base[10];
int main()
{
	while(scanf("%s%d",Base,&Index)!=EOF)
	{
		memset(part1,0,sizeof(part1));
		memset(part2,0,sizeof(part2));
		memset(temp,0,sizeof(temp));
		b=strlen(Base);
		for(a=b-1,i=0;a>=0;a--,i++)
		{
			if(Base[a]!='.')
			{
				temp[i]=Base[a]-'0';
				part1[i]=Base[a]-'0';
			}
			else
			{
				bEqual=i;
				i--;
			}
		}
		for(i=2;i<=Index;i++)
		{
			if(i%2==0)
			{
				for(a=0;a<=200;a++)
				{
					for(b=0;b<=8;b++)
					{
						part2[a+b]+=part1[a]*temp[b];
					}
				}
				for(a=0;a<=200;a++)
				{
					if(part2[a]>=10)
					{
						part2[a+1]+=part2[a]/10;
						part2[a]=part2[a]%10;
					}
				}
			}
			else
			{
				memset(part1,0,sizeof(part1));
				for(a=0;a<=200;a++)
				{
					for(b=0;b<=8;b++)
					{
						part1[a+b]+=part2[a]*temp[b];
					}
				}
				for(a=0;a<=200;a++)
				{
					if(part1[a]>=10)
					{
						part1[a+1]+=part1[a]/10;
						part1[a]=part1[a]%10;
					}
				}
			}
		}
		if(Index%2==0)
		{
			c=0;
			for(j=0;j<=bEqual*Index-1;j++)
			{
				if(part2[j]!=0)
				{
					break;
				}
			}  
			for(b=200;b>=j;b--)
			{
				if(part2[b]!=0)
					c=1;
				if(b==bEqual*Index-1)
					printf(".");
				if(c||b<=bEqual*Index-1)
					printf("%d",part2[b]);
			}
		}
		else 
		{
			c=0;
			for(j=0;j<=bEqual*Index-1;j++)
			{
				if(part1[j]!=0)
				{
					break;
				}
			} 
			for(b=200;b>=j;b--)
			{
				if(part1[b]!=0)
					c=1;
				if(b==bEqual*Index-1)
					printf(".");
				if(c||b<=bEqual*Index-1)
					printf("%d",part1[b]);
			}
		}
		if(c==0)
		printf(".");
		printf("\n");
	}
	return 0;
}
