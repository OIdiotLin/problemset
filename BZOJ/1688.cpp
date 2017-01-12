#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (1003)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

int N,D,K;
int v[MAXN];

void init(){
	int x,y;
	#ifdef Judge
	SpeedUp;
	freopen("1688.in","r",stdin);
	freopen("1688.out","w",stdout);
	#endif
	cin>>N>>D>>K;
	for(int i=1;i<=N;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y;
			v[i]|=(1<<(y-1));
		}
	}
}

void work(){
	int M=(1<<D),Ans=0;
	for(int i=0;i<M;i++){
		int a=i,b=0;
		while(a) {b+=(a&1); a>>=1;}
		if(b!=K) continue;
		b=0;
		for(int j=1;j<=N;j++)
			b+=((v[j]|i)==i);
		Ans=max(Ans,b);
	}
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

