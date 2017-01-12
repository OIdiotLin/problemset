/*
	System: Windows7 32bit
	Machine: Class4_B2
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN ()
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

int N,M,cnt;
int t[30];
int Ans[1200][30];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen("dataa.in","r",stdin);
	freopen("dataa.out","w",stdout);
	#endif
	cin>>N>>M;
	cnt=0;
}

void dfs(int now,int dep,int s){
	if(dep>N) return;
	if(now==M && s<=(N-dep)){
		cnt++;
		for(int i=1;i<M;i++)
			Ans[cnt][i]=t[i];
		Ans[cnt][M]=N-dep;
		return;
	}
	for(int i=s;i<=N;i++){
		t[now]=i;
		dfs(now+1,dep+i,i);
	}
}

void work(){
	dfs(1,0,1);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=M;j++)
			cout<<Ans[i][j]<<" ";
		cout<<endl;
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

