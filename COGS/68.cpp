#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1010
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int f[MAXN];
int N,M;
int T,value;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("medic.in","r",stdin);
	freopen("medic.out","w",stdout);
	#endif
	cin>>N>>M;
}

void Dp()
{
	for(int i=1;i<=M;i++)
	{
		cin>>T>>value;
		for(int j=N;j>=T;j--)
			if(f[j]<value+f[j-T])
				f[j]=f[j-T]+value;
	}
}

void work()
{
	init();
	Dp();
	cout<<f[N]<<endl;
}

int main()
{
	work();
	return 0;
}

