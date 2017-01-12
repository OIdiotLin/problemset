#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

LL Pow(LL n,LL p,LL k){
	if(p==0) return 1;
	LL ret;
	if(p&1){
		ret=Pow(n,p>>1,k);
		ret=ret*ret*n%k;
		return ret;
	}
	ret=Pow(n,p>>1,k);
	ret=ret*ret%k;
	return ret;
}

LL N,P,K;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("dmod.in","r",stdin);
	freopen("dmod.out","w",stdout);
	#endif
	cin>>N>>P>>K;
}

void work(){
	N%=K;
	cout<<Pow(N,P,K)<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

