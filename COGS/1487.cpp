#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define MAXN 1010
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,M,K,T,T0;
double f[MAXN],P[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("tribbles.in","r",stdin);
	freopen("tribbles.out","w",stdout);
	#endif
	cin>>T;	
	T0=T;
}

void work()
{
	int N,K,M;
	cin>>N>>K>>M;
	for(int i=0;i<N;i++)
		cin>>P[i];
	f[0]=0;
	f[1]=P[0];
	for(int i=2;i<=M;i++)
	{
		f[i]=0;
		for(int j=0;j<N;j++)
			f[i]+=pow(f[i-1],j)*P[j];
	}
	cout<<"Case #"<<T0-T<<": "<<fixed<<setprecision(7)<<pow(f[M],K)<<endl;
}

int main()
{
	init();

	while(T--)
	{
		work();
	}
	return 0;
}

