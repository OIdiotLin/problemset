#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1010
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int G[MAXN][MAXN];
bool vis[MAXN];
int Ans;
int N,k;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("virus.in","r",stdin);
	freopen("virus.out","w",stdout);
	#endif
	memset(G,0,sizeof(G));
	memset(vis,false,sizeof(vis));
	Ans=0;
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>G[i][j];
}

void dfs(int x)
{
	vis[x]=true;
	for(int i=1;i<=N;i++)
		if(!vis[i] && G[x][i]==1)
			dfs(i);
}

void work()
{
	init();
	for(int i=1;i<=N;i++)
	{
		if(!vis[i])
		{
			dfs(i);
			Ans++;
		}
	}
	cout<<Ans<<endl;
}

int main()
{
	work();
	return 0;
}

