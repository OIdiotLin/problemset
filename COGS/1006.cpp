#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1010
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;

int New[MAXN][MAXN],Be[MAXN][MAXN],GN[MAXN][MAXN],GB[MAXN][MAXN];
int f[MAXN][MAXN][3];
int N,M,Ans;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("industry.in","r",stdin);
	freopen("industry.out","w",stdout);
	#endif
	memset(New,0,sizeof(New));
	memset(Be,0,sizeof(Be));
	memset(f,0,sizeof(f));
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin>>GB[i][j];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin>>GN[i][j];
	
}

void Dp()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			Be[i][j]=Be[i][j-1]+GB[i][j];
	for(int j=1;j<=M;j++)
		for(int i=1;i<=N;i++)
			New[i][j]=New[i-1][j]+GN[i][j];
			
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1])+Be[i][j];
			f[i][j][1]=max(f[i][j-1][0],f[i][j-1][1])+New[i][j];
		}
}

void work()
{
	init();
	Dp();
	Ans=max(f[N][M][0],f[N][M][1]);
	cout<<Ans<<endl;
}

int main()
{
	work();
	return 0;
}

