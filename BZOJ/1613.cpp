/*
	System: Windows7 32bit
	Machine: Class4_B2
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (10005)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

int N,M;
int D[MAXN],f[MAXN];
int S[MAXN];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>D[i];
		S[i]=S[i-1]+D[i];
	}
}

void work(){
	for(int i=1;i<=N;i++){
		f[i]=f[i-1];
		for(int j=1;j<=M&&(j<<1)<=i;j++)
			f[i]=max(f[i-(j<<1)]+S[i-j]-S[i-(j<<1)],f[i]);
	}
	cout<<f[N]<<endl;
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

