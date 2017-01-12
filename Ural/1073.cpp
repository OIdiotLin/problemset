#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define MAXN (60010)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

int f[MAXN];
int N;

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		f[i]=INF;
	f[1]=1;
}

void dp(){
	for(int i=2;i<=N;i++){
		for(int j=0;j<=sqrt(i);j++)
			f[i]=min(f[i],f[i-j*j]+1);
	}
	cout<<f[N]<<endl;
}

int main(){
	init();
	dp();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

