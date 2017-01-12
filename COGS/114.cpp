#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 1005
#define MOD 12345
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int A[MAXN],W[MAXN];
int N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("puzhuan.in","r",stdin);
	freopen("puzhuan.out","w",stdout);
	#endif
	memset(A,0,sizeof(A));
	memset(W,0,sizeof(W));
	cin>>N;
}

void work(){
	for(int i=1;i<=N;i++){
		A[i]=(W[i-1]+2-(1&i))%MOD;
		W[i]=(W[i-1]+A[i])%MOD;
	}
	cout<<A[N]<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(A)+sizeof(W))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

