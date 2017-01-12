#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (60)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

bool p;
int N,K;
int f[MAXN][2],Ans[MAXN];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N>>K;
	f[0][0]=1;
}

void dfs(int i,int s){
	if(i==0 || s==0)return;
	if(s>f[i][0]){
		Ans[i]=1;dfs(i-1,s-f[i][0]);
	}else dfs(i-1,s);
}

void work(){
	for(int i=1;i<=N;i++){
		f[i][0]=f[i-1][0]+f[i-1][1];		//N-1 0
		f[i][1]=f[i-1][0];					//N-2 10
		if(f[i][0]+f[i][1]>=K){
			p=true;
			dfs(i,K);
			break;
		}
	}
	if(p)for(int i=N;i;i--) cout<<Ans[i];
	else cout<<"-1";
	cout<<endl;
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

