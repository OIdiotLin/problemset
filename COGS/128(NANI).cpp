#include <cstdio>
using namespace std;
 
int x[1080],y[1080],r[1080],que[1080],way[1080]={0},map[1080][1079];
bool used[1080]={false};
 
int main(void)
{
	freopen("rollers.in","r",stdin);
//	freopen("rollers.out","w",stdout);
	int i,j,n,start,tail=0,head=0;
	scanf("%d\n",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d %d %d\n",&x[i],&y[i],&r[i]);
		if (x[i]==0&&y[i]==0)
		{
			start=i;
			break;
		}
		for (j=0;j<i;j++)
			if ((r[i]+r[j])*(r[i]+r[j])==(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
			{
				map[i][way[i]++]=j;
				map[j][way[j]++]=i;
			}
	}
	for (;;)
	{
		for (j=0;j<i;j++)
			if ((r[i]+r[j])*(r[i]+r[j])==(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
			{
				map[i][way[i]++]=j;
				map[j][way[j]++]=i;
			}
		i++;
		if (i>=n)
			break;
		scanf("%d %d %d\n",&x[i],&y[i],&r[i]);
	}
	if (!way[start])
	{
		printf("0 0\n");
		fclose(stdin);
		fclose(stdout);
		return(0);
	}
	for(int i=0;i<n;i++){
		printf("%d\n",way[i]);
	}
	printf("\n");
	que[0]=start;
	used[start]=true;
	while (tail<=head)
	{/*
		printf("tail=%d,head=%d\n",tail,head);
		for(i=tail;i<=head;i++)
		{
			printf("%d\t",que[i]);
		}
		printf("\n");*/
		for (i=0;i<way[que[tail]];i++)
			if (!used[map[que[tail]][i]])
			{
				head++;
				que[head]=map[que[tail]][i];	
			//	printf("%d\n",que[head]);
				used[que[head]]=true;
				if (way[que[head]]==1)
				{
					printf("%d %d\n",x[que[head]],y[que[head]]);
					fclose(stdin);
					fclose(stdout);
					return(0);
				}
			}
		tail++;
	
	}
	fclose(stdin);
	fclose(stdout);
	return(0);
}
