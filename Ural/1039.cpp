#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <vector>
#define MAXN (6001)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

int N,L,K;
int A[MAXN];
vector<int> son[MAXN];
int f[MAXN][2];
bool vis[MAXN],fa[MAXN];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen("1039.in","r",stdin);
//	freopen(".out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		f[i][1]=A[i];		//pick
	}
	while(true){
		cin>>L>>K;
		if(L==0 && K==0) break;
		son[K].push_back(L);
		fa[L]=true;
	}
}

void dfs(int T){
	if(son[T].empty()){
		vis[T]=true;
		return;
	}
	for(int i=0;i<son[T].size();i++){
		if(!vis[son[T][i]]) dfs(son[T][i]);
		f[T][0]=max(f[son[T][i]][0],f[son[T][i]][1])+f[T][0];
		f[T][1]=f[son[T][i]][0]+f[T][1];
	}
	vis[T]=true;
}

void work(){
	for(int i=1;i<=N;i++)
		if(fa[i]==false){			//Find the root.
			dfs(i);
			#ifdef Debug
			work2();
			#endif
			cout<<max(f[i][0],f[i][1])<<endl;
			return;
		}
}

int main(){
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(A)*2+sizeof(son)+sizeof(f)+sizeof(vis))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

