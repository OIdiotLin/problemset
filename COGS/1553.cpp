#include <iostream>
#include <cstring>
#include <cstdio>
#define INF (1<<30)
#define MAXN 100010
#define eps 1000
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int Weight[MAXN],f[MAXN];
int N,K;
double Ans;

inline double MagicLin(int a,int b){
	return (double)(f[a]-f[b])/(double)(a-b);
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("helpz.in","r",stdin);
	freopen("helpz.out","w",stdout);
	#endif
	cin>>N>>K;
	for(int i=1;i<=N;i++)
	{
		cin>>Weight[i];
		f[i]=f[i-1]+Weight[i];
	}
	Ans=0;
}

void work()
{
	int Max=0;
	for(int i=0;i<=N-K;i++)
	{
		if(MagicLin(i+K,Max)<MagicLin(i+K,i))
			Max=i;
		if(MagicLin(i+K,Max)>Ans)
			Ans=MagicLin(i+K,Max);
	}
}

int main()
{
	init();
	work();
	cout<<(int)(Ans*eps)<<endl;
	return 0;
}

