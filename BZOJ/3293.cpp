/*
	System: Windows7 32bit
	Machine: Class4_B2
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (100005)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

int N;
int A[MAXN];
LL Sum,Ans;
LL f[MAXN];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		Sum+=A[i];
	}
	Sum/=N;
	for(int i=2;i<=N;i++)
		f[i]=f[i-1]+A[i-1]-Sum;
	sort(f+1,f+N+1);
}

void work(){
	int mid=f[(N+1)>>1];
	for(int i=1;i<=N;i++)
		Ans+=abs(mid-f[i]);
	cout<<Ans<<endl;
}

int main(){
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

