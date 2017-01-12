#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 101000
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
struct Nose{
	int Weight,size;
};
inline int Max(int a,int b){return a>b?a:b;}
Nose a[MAXN];
int N,M;
int f[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("nose.in","r",stdin);
//	freopen("nose.out","w",stdout);
	#endif
	cin>>N>>M;
	memset(f,0,sizeof(f));
	for(int i=1;i<=N;i++)
	{
		cin>>a[i].Weight>>a[i].size;
		for(int j=M;j>=a[i].Weight;j--)
			f[j]=Max(f[j],f[j-a[i].Weight]+a[i].size);
	}
}

void DP()
{
	for(int i=1;i<=N;i++)
		for(int j=M;j>=a[i].Weight;j--)
			f[j]=Max(f[j],f[j-a[i].Weight]+a[i].size);
}

void work()
{
	init();
//	DP();
	cout<<f[M]<<endl;
}

int main()
{
	work();
	return 0;
}

