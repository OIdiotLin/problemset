#include <iostream>
#include <cmath>
#include <cstring>
#define INF 1<<30
#define MAXN 5010
#define MAXM 1010
#define SpeedUp ios::sync_with_stdio(false)
#define FILE

using namespace std;

inline int Min(int a,int b){return (a>b)?b:a;}
int height[MAXN],f[MAXN][MAXM];
int N,M;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("1061.in","r",stdin);
//	freopen("1061.out","w",stdout);
	#endif
	cin>>M>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			f[i][j]=INF;
	for(int i=N;i>=1;i--)
		cin>>height[i];
	
}

void Dp()
{
	for(int i=1;i<=M;i++)
		for(int j=i*3;j<=N;j++)
			f[j][i]=Min(f[j-1][i], f[j-2][i-1]+(height[j]-height[j-1])*(height[j]-height[j-1]) );
}

void work()
{
	init();
	Dp();
	cout<<f[N][M]<<endl;
}

int main()
{
	work();
	return 0;
}

