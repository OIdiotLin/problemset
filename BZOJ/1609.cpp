/*
	System: Windows7 32bit
	Machine: Class4_B2
	Comments: 枚举1和2的断点，每个枚举中用ST算法O(1)求最小值
				（即2和3的断点），O(nlogn)
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (30005)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

int N,Ans;
int d1[MAXN],d2[MAXN];
int f[MAXN][4];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen("1609.in","r",stdin);
	freopen("1609.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>d1[i];
		d2[i]=4-d1[i];
	}
}

int DP(int *d){
	for(int i=1;i<=N;i++)
		for(int j=1;j<4;j++){
			f[i][j]=INF;
			for(int k=1;k<=j;k++){
				f[i][j]=min(f[i][j],f[i-1][k]);
				f[i][j]+=(d[i]!=j);
			}
		}
	int ret=INF;
	ret=min(ret,min(f[N][1],min(f[N][2],f[N][3])));
	return ret;
}

void work(){
	Ans=INF;
	Ans=min(Ans,min(DP(d1),DP(d2)));
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

