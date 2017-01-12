#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 1005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

inline int cmp(const int &a,const int &b)
{
	return (a>b)?1:0;
}

int N,P,K;
int G[MAXN][MAXN],f[MAXN][MAXN];
int dist[MAXN],A[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("phone.in","r",stdin);
//	freopen("phone.out","w",stdout);
	#endif
	cin>>N>>P>>K;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			f[i][j]=INF;
	for(int i=1;i<=P;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		G[x][y]=G[y][x]=w;
		f[x][y]=f[y][x]=1;
	}
}

void SPFA()
{
	bool vis[MAXN]={true};
	vis[1]=false;
	int Q[MAXN]={0};
	int head=0,tail=1,k;
	Q[1]=1;
	for(int i=2;i<=N;i++)
		dist[i]=INF;
	dist[1]=0;
	while(head!=tail)
	{
		k=Q[++head];
		vis[k]=true;;
		for(int i=1;i<=N;i++)
		{
			if(f[k][i]!=INF && dist[k]+f[k][i]<dist[i])
			{
				dist[i]=dist[k]+f[k][i];
				if(vis[i])
				{
					Q[++tail]=i;
					vis[i]=false;
				}
			}
		}
	}
}

void Out(int x,int y)
{
	if(x==y)
	{
		cout<<A[x]<<endl;
		return;
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(G[i][j]>A[(x+y)>>1])
				f[i][j]=1;
			else{
				if(G[i][j]==0)
					f[i][j]=INF;
				else
					f[i][j]=0;
			}
	SPFA();
	if(dist[N]>K)
		Out(((x+y)>>1)+1,y);
	else
		Out(x,(x+y)>>1);
}

void work()
{
	SPFA();
	if(dist[N]<=K)
	{
		cout<<0<<endl;
		return;
	}
	if(dist[N]==INF)
	{
		cout<<-1<<endl;
		return;
	}
	sort(A+1,A+P+1);
	Out(1,P);
}

int main()
{
	init();
	work();
	return 0;
}

