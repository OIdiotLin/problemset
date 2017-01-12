/*
	Name: Linear Cellular Automata
	Copyright: UVaOJ-457
	Author: LHD
	Date: 20/11/13 17:52
	Description:生物学家对在一排并排着的培养皿中的细菌群体进行DNA序列修改来进行相关测试，通过改变DNA
				他可以让细菌对邻近培养皿里的种群浓密度产生反应，群体密度用4个状态标示（0~3）DNA的状态通过
				下标为0~9的数组描述，具体如下：
				对于每个给出的培养皿，让其与左邻右邻的培养皿密度和为K，第二天，培养皿就会形成一个
				对应数组序列DNA[K]的种群密度。
				最左边的培养皿可以认为其左边有个密度为0的培养皿，最右边的右边也有一个。
				现在我们清楚的知道一些DNA程式会导致所有的菌落死亡，(像[0,0,0,0,0,0,0,0,0,0])另外一些会令其
				快速生长([3,3,3,3,3,3,3,3,3,3])生物学家对这些更小的媒介DNA程式是如何运作的很感兴趣。
				写一个程序模仿40个并排着的细菌培养皿的生长状况，假设第20个起始密度为1，其他的为0.
				输入:
					先输入案例个数，然后输入密度变化规律
				输出: 
					密度为1输出' '，2输出'.'，3输出'x',4输出'W'。
				简单的水题，switch判断即可，只是需要注意每个案例之间的格式。
*/
#include <stdio.h>
#include <string.h>
int DNA[10],germ[50][45];
int main()
{
	freopen("457.in","r",stdin);
	//freopen("457.out","w",stdout);
	int n,i,j,temp;
	scanf("%d",&n);
	while(n--)
	{
		for(i=0; i<10; i++)
			scanf("%d",&DNA[i]);
		memset(germ,0,sizeof(germ));			//初始化为0 
		germ[0][20] = 1;
		for(i=1; i<50; i++)
		{
			for(j=1; j<41; j++)
			{
				temp = germ[i-1][j-1] + germ[i-1][j] + germ[i-1][j+1];
				germ[i][j] = DNA[temp];
			}
		}
		for(i=0; i<50; i++)						//列出50天的情况 
		{
			for(j=1; j<41; j++)					//列出40个培养皿的变化 
			{
				switch(germ[i][j])
				{
				case 0:
					putchar(' ');
					break;
				case 1:
					putchar('.');
					break;
				case 2:
					putchar('x');
					break;
				case 3:
					putchar('W');
					break;
				}
			}
			putchar('\n');
		}
		if(n>0)
			putchar('\n');
	}
	return 0;
}
