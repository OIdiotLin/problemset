#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 110
#define INF 1<<25
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,M;
int G[MAXN][MAXN];

void init()
{
	int s,t,w;
	SpeedUp;
	#ifdef FILE
	freopen("shorta.in","r",stdin);
	freopen("shorta.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			if(i==j)continue;
			G[i][j]=INF;
		}
	for(int i=1;i<=M;i++)
	{
		cin>>s>>t>>w;
		G[s][t]=G[t][s]=w;
	}
}

void floyd()
{
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(G[i][j]>G[i][k]+G[k][j])
					G[i][j]=G[i][k]+G[k][j];
}

void OutPut()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cout<<G[i][j]<<" ";
	cout<<endl;
}

int main()
{
	init();
	floyd();
	OutPut();
	return 0;
}

