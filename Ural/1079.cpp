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

LL a[MAXN],f[MAXN];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	a[0]=0,a[1]=1;
	f[0]=0,f[1]=1;
	for(int i=2;i<=99999;i++){
		a[i]=(i&1 ? a[i/2]+a[i/2+1] : a[i>>1]);
		f[i]=max(f[i-1],a[i]);
	}
}

void work(){
	while(1){
		int N;
		cin>>N;
		if(N==0) return;
		cout<<f[N]<<endl;
	}
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

