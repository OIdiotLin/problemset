#include <iostream>
#include <cstring>
#define FILE
#define MAXN 1005

using namespace std;

bool vis[MAXN];
int Adj[MAXN][MAXN],d[MAXN][MAXN];
int N;

void init()
{
	#ifdef FILE
	freopen("DMZ-3.in","r",stdin);
	//freopen("DMZ-3.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>Adj[i][j];
}

void Floyd()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)
				if(d[i][j]+Adj[j][k]>d[i][k])
					d[i][k]=d[i][j]+Adj[j][k];
}

int main()
{
	init();
	Floyd();
	cout<<d[1][N]<<endl;
	return 0;
}
