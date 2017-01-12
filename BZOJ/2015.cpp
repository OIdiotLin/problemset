/*
	System: Windows7 32bit
	Machine: Class4_B2
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXN (50005)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

struct Edge{
	int pre,next,w;
}E[MAXN<<2];
queue<int> Q;
int G[MAXN],dist[MAXN];
bool vis[MAXN];
int N,M,B,tot;

inline void Ins(int x,int y,int w){
	E[++tot]=(Edge){y,G[x],w};
	G[x]=tot;
}

void init(){
	int x,y,w;
	#ifdef Judge
	SpeedUp;
	freopen("2015.in","r",stdin);
	freopen("2015.out","w",stdout);
	#endif
	cin>>N>>M>>B;
	for(int i=1;i<=M;i++){
		cin>>x>>y>>w;
		Ins(x,y,w);
		Ins(y,x,w);
	}
	memset(dist,127,sizeof(dist));
}

void SPFA(){
	dist[1]=0;
	Q.push(1);
	vis[1]=true;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].pre;
			if(dist[k]+E[u].w<dist[v]){
				dist[v]=dist[k]+E[u].w;
				if(!vis[v]){
					vis[v]=true;
					Q.push(v);
				}
			}
		}
		vis[k]=false;
	}
}

void work(){
	int x,y;
	SPFA();
	for(int i=1;i<=B;i++){
		cin>>x>>y;
		cout<<dist[x]+dist[y]<<endl;
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

