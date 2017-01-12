/*
	System: Windows7 32bit
	Machine: Class4_B2
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (50000)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

int fa[MAXN];
int N,M;
inline int f(int x){
	return fa[x]==x ? x : fa[x]=f(fa[x]);
}

void init(){
	int x,y;
	#ifdef Judge
	SpeedUp;
	freopen("relations.in","r",stdin);
	freopen("relations.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		fa[i]=i;
	for(int i=1;i<=M;i++){
		cin>>x>>y;
		int u=f(x),v=f(y);
		if(u!=v){
			if(x<y) fa[y]=x;
			else fa[x]=y;
		}
	}
}

void work(){
	int x,y;
	cin>>M;
	for(int i=1;i<=M;i++){
		cin>>x>>y;
		cout<<(f(x)==f(y) ? "Yes" : "No")<<endl;
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

