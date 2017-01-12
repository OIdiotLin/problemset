#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define MOD 100003
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

LL N,M;

LL quick_pow(LL a,LL r)	//a^r
{
	LL Ans=1;
	LL t=a;
	while(r)
	{
		if(r&1==1)
			Ans=(Ans*t)%MOD;
		r>>=1;
		t=(t*t)%MOD;
	}
	return Ans;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("prisona.in","r",stdin);
	freopen("prisona.out","w",stdout);
	#endif
	cin>>M>>N;
}

void work()
{
	LL Ans=(quick_pow(M,N)-((M*quick_pow(M-1,N-1))%MOD))%MOD;
	if(Ans<0)
		Ans+=MOD;
	cout<<Ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}

