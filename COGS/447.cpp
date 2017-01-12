#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 205
#define MOD 9901
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

int N,K;
int f[MAXN][MAXN];

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	#endif
	cin>>N>>K;
	for(int i=1;i<=K;i++){
		f[1][i]=1;
	}
}

void work(){
	for(int i=3;i<=N;i++){
		if(i&1){
			for(int j=1;j<=K;j++)
				for(int k=1;k<i-1;k++){
					if(k&1)
						f[i][j]=(f[i][j]+f[i-1-k][j-1]*f[k][j-1])%MOD;
				}
		}
	}
	cout<<(f[N][K]-f[N][K-1]+MOD)%MOD<<endl;
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

