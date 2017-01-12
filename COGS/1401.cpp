#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#define MAXN 101
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

double source[MAXN][MAXN],F[MAXN][MAXN];
int N,M;
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("ziyuan.in","r",stdin);
	freopen("ziyuan.out","w",stdout);
	#endif
	cin>>M>>N;
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)
			cin>>source[i][j];
}

void DP()
{
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)
			for(int k=0;k<=j;k++)
				F[i][j]=max(F[i][j],F[i-1][j-k]+source[i][k]);
}

void work()
{
	init();
	DP();
	cout<<fixed<<setprecision(2)<<F[M][N]<<endl;
}

int main()
{
	work();
	return 0;
}

