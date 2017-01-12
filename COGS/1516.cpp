#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1100000
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

long long  N=0;
long long  f[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("rook.in","r",stdin);
	freopen("rook.out","w",stdout);
	#endif
	N++;
	memset(f,0,sizeof(f));
	f[0]=1;
}

long long Cal(int n)
{
	for(int i=1;i<=1<<n;i++)
	{
		for(int j=i;j>0;j=j-(j&-j))
		{
			f[i]+=f[i&~(j&-j)];
		}
	}
	return f[(1<<n)-1];
}

void work()
{
	init();
	cout<<Cal(N)<<",";
}

int main()
{
	for(int i=1;i<=20;i++)
	{
			work();
	}

	return 0;
}

