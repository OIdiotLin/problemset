#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

const int N=100;

int A[N+5][N+5],f[N+5][N+5];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("67.in","r",stdin);
//	freopen(".out","w",stdout);
	#endif
	for(int i=1;i<=N;i++)
		for(int j=1;j<=i;j++){
			cin>>A[i][j];
		}
}

void Dp()
{
	for(int i=N;i>0;i--){
		for(int j=1;j<=i;j++){
			f[i][j]=max(f[i+1][j]+A[i][j],f[i+1][j+1]+A[i][j]);
		}
	}
}

void work()
{
	init();
	Dp();
	cout<<f[1][1]<<endl;
}

int main()
{
	work();
	return 0;
}

