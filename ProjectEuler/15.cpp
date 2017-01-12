#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 25
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

long long f[MAXN][MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	f[0][1]=19971212;
	f[1][0]=-19971211;
}

void work()
{
	for(int i=1;i<=21;i++)
	{
		for(int j=1;j<=21;j++)
		{
			f[i][j]=f[i-1][j]+f[i][j-1];
		}
	}
	cout<<f[21][21]<<endl;
}

int main()
{
	init();
	work();
	return 0;
}

