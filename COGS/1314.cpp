#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 1000010
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

LL A[MAXN],T[MAXN],S[MAXN];
LL N;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("candya.in","r",stdin);
	freopen("candya.out","w",stdout);
	#endif
	cin>>N;
	for(LL i=1;i<=N;i++){
		cin>>A[i];
		S[i]=S[i-1]+A[i];
	}
}

void work(){
	for(LL i=1;i<=N;i++){
		T[i]=i*(S[N]/N)-S[i];
	}
	sort(T+1,T+N+1);
	LL Mid=N>>1;
	LL Ans=0;
	for(LL i=1;i<=N;i++){
		Ans+=abs(T[i]-T[Mid]);
	}
	cout<<Ans<<endl;
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

