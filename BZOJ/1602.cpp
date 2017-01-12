#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
 
int way[1001],G[1001][1000],dis[1001][1000];
 
void bfs(int st,int en)
{
	int i,Q[1000]={0},len[1000]={0},tail=0,head=0;
	bool used[1001]={false};
	Q[0]=st;
	len[0]=0;
	used[st]=true;
	while (tail<=head)
	{
		for (i=0;i<way[Q[tail]];i++)
			if (!used[G[Q[tail]][i]])
			{
				head++;
				Q[head]=G[Q[tail]][i];
				len[head]=len[tail]+dis[Q[tail]][i];
				used[Q[head]]=true;
				if (Q[head]==en)
				{
					cout<<len[head]<<endl;
					return;
				}
			}
		tail++;
	}
}
 
int main()
{
	int i,N,M,r,r2,r3;
	cin>>N>>M;
	for (i=1;i<N;i++)
	{
		cin>>r>>r2>>r3;
		G[r][way[r]]=r2;
		G[r2][way[r2]]=r;
		dis[r][way[r]]=r3;
		dis[r2][way[r2]]=r3;
		way[r]++;
		way[r2]++;
	}
	for (i=1;i<=M;i++)
	{
		cin>>r>>r2;
		bfs(r,r2);
	}
	return(0);
}
