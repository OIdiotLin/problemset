#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 310
#define INF 0x3f
#define MAX 0x3f3f3f3f
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,M,T;
int G[MAXN][MAXN];

void init()
{
	int s,e,h;
	SpeedUp;
	#ifdef FILE
	freopen("hurdles.in","r",stdin);
//	freopen("hurdles.out","w",stdout);
	#endif
	cin>>N>>M>>T;
	memset(G,INF,sizeof(G));
	for(int i=1;i<=N;i++)
		G[i][i]=0;
	for(int i=1;i<=M;i++)
	{
		cin>>s>>e>>h;
		G[s][e]=h;
	}
}

void floyd()
{
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				G[i][j]=min(G[i][j],max(G[i][k],G[k][j]));
}

void work()
{
	int x,y;
	for(int i=1;i<=T;i++)
	{
		cin>>x>>y;
		if(G[x][y]==MAX)
			G[x][y]=-1;
		cout<<G[x][y]<<endl;
	}
}

int main()
{
	init();
	floyd();
	work();
	return 0;
}

