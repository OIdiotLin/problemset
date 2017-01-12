#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN (2510)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,f[MAXN],Cost[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("cowriver.in","r",stdin);
	freopen("cowriver.out","w",stdout);
	#endif
	cin>>N>>Cost[0];
	for(int i=1;i<=N;i++){
		cin>>Cost[i];
		Cost[i]+=Cost[i-1];
		f[i]=Cost[i];
	}
}

void Dp()
{
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i-j;j++)
			f[i]=min(f[i],f[j]+f[i-j]+Cost[0]);
	}
	cout<<f[N]<<endl;
}

int main()
{
	init();
	Dp();
	return 0;
}

