#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 55
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,M;
long long int F[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("nucle.in","r",stdin);
	freopen("nucle.out","w",stdout);
	#endif
	memset(F,0,sizeof(F));
	cin>>N>>M;
}

void Dp()
{
	F[0]=1;
	for(int i=1;i<=N;i++)
	{
		if(i==M)
			F[i]=2*F[i-1]-1;
		if(i<M)
			F[i]=2*F[i-1];
		if(i>M)
			F[i]=2*F[i-1]-F[i-M-1];
	}
}

void work()
{
	init();
	Dp();
	cout<<F[N]<<endl;
}

int main()
{
	work();
	return 0;
}

