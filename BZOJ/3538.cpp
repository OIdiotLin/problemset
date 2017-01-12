#include <iostream>
#include <cstring>
#include <ctime>
#include <queue>
#include <algorithm>
#include <cstdio>
#define MAXN (10005)
#define MAXM (50005)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

struct Edge{
	int pre,next,w;
}E[MAXM];
int P[MAXM],Q[MAXM],A[MAXM],B[MAXM];
int N,M,tot;
bool vis[MAXN];
int dist[3][MAXN],G[MAXN];
inline void Ins(int x,int y){
	E[++tot]=(Edge){y,G[x],0};
	G[x]=tot;
}

void init(){
	#ifdef Judge
	SpeedUp;
	freopen("3538.in","r",stdin);
	freopen("3538.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=M;i++){
		cin>>A[i]>>B[i]>>P[i]>>Q[i];
		Ins(A[i],B[i]);
	}
}

queue<int> Qt;
void SPFA(int st,int *d){
	for(int i=1;i<=N;i++) d[i]=INF;
	Qt.push(st);
	d[st]=0;
	vis[st]=true;
	while(!Qt.empty()){
		int k=Qt.front();
		Qt.pop();
		vis[k]=false;
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].pre;
			if(d[v]>d[k]+E[u].w){
				d[v]=d[k]+E[u].w;
				if(!vis[v]){
					vis[v]=true;
					Qt.push(v);
				}
			}
		}
	}
}

void work(){
	for(int i=1;i<=tot;i++) E[i].w=P[i];
	SPFA(N,dist[0]);
	for(int i=1;i<=tot;i++) E[i].w=Q[i];
	SPFA(N,dist[1]);
	memset(G,0,sizeof(G)); tot=0;
	for(int i=1;i<=M;i++){
		int u=A[i],v=B[i];
		Ins(u,v);
		E[i].w=2;
		if(dist[0][v]+P[i]==dist[0][u]) E[i].w--;
		if(dist[1][v]+Q[i]==dist[1][u]) E[i].w--;
	}
	SPFA(1,dist[2]);
	cout<<(dist[2][N]==INF ? -1 : dist[2][N])<<endl;
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

