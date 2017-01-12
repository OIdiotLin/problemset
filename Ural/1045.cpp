#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 1005
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

bool G[MAXN][MAXN];
bool f[MAXN],vis[MAXN];
int t[MAXN][MAXN];
int N,K;

void MakeTree(int v){
	vis[v]=true;
	for(int i=1;i<=N;i++){
		if(!vis[i] && G[v][i]){
			t[v][++t[v][0]]=i;
			MakeTree(i);
		}
	}
}

void init()
{
	int x,y;
	#ifdef FILE
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N>>K;
	for(int i=1;i<N;i++){
		cin>>x>>y;
		G[x][y]=G[y][x]=true;
	}
	MakeTree(K);
}

void dfs(int depth,int v){
	if(t[v][0]==0){
		f[v]=!(depth&1);
		return;
	}
	for(int i=1;i<=t[v][0];i++)
		dfs(depth+1,t[v][i]);
	if(depth&1){
		f[v]=false;
		for(int i=1;i<=t[v][0];i++)
			f[v]=(f[v]|f[t[v][i]]);
	}else{
		f[v]=true;
		for(int i=1;i<=t[v][0];i++)
			f[v]=(f[v]&f[t[v][i]]);
	}
}

void work(){
	dfs(1,K);
	if(f[K]==false)
		cout<<"First player loses"<<endl;
	else{
		for(int i=1;i<=t[K][0];i++)
			if(f[t[K][i]]){
				cout<<"First player wins flying to airport "<<t[K][i]<<endl;
				return;
			}
	}
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

