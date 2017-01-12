#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (200)
#define INF (1<<30)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

LL C[MAXN];
LL N;
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("1816.in","r",stdin);
	freopen("1816.out","w",stdout);
	#endif
	cin>>N>>C[0];
	for(int i=1;i<=N;i++)
		cin>>C[i];
	sort(C,C+N+1);
}

void BinSearch(LL L,LL R){
	if(L+1>=R){
		cout<<L<<endl;
		return;
	}
	LL mid=(L+R)>>1;
	LL t=0;
	for(LL i=0;i<=N;i++)
		if(C[i]<mid)
			t+=mid-C[i];
	if(t<=mid) BinSearch(mid,R);
	else BinSearch(L,mid);
}

int main()
{
	init();
	BinSearch(0,INF);
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

