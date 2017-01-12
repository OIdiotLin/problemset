/*
	Work on OIdiot's PC
	System: Ubuntu 14.04 Kylin
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (105)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

bool G[MAXN][MAXN];
int N,M,Ans;

void init(){
	int x,y;
	#ifdef Judge
	freopen("1612.in","r",stdin);
//	freopen("1612.out","w",stdout);
//	SpeedUp;
	#endif
	cin>>N>>M;
	for(int i=1;i<=M;i++){
		cin>>x>>y;
		G[x][y]=true;
	}
}

void Floyd(){
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(G[i][k] && G[k][j])
					G[i][j]=true;
}

void work(){
	for(int i=1;i<=N;i++){
		int cnt=0;
		for(int j=1;j<=N;j++)
			if(i!=j && (G[i][j]||G[j][i]))
				cnt++;
		if(cnt==N-1) Ans++;
	}
	cout<<Ans<<endl;
}

int main(){
	init();
	Floyd();
	work();
	#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
	#endif
	return 0;
}