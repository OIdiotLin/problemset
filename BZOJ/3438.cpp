/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (80005)
#define INF (0x7fffffff)
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Edge{
	int v,next,flow;
	Edge(int _v=0,int _next=0,int _flow=0):v(_v),next(_next),flow(_flow){};
}E[MAXN<<1];

int G[MAXN],dist[MAXN],cur[MAXN];
int tot,id,N,M,Ans;
int S,T;

int A[MAXN],B[MAXN];
int oA[MAXN],NodeA[MAXN],NodeB[MAXN];

inline void Ins(int u,int v,int w){
	E[++tot]=Edge(v,G[u],w),G[u]=tot;
	E[++tot]=Edge(u,G[v],0),G[v]=tot;
}

void init(){
	int k,c1,c2,x;
#ifdef Judge
	freopen("3438.in","r",stdin);
	freopen("3438.out","w",stdout);
//	SpeedUp;
#endif
	tot=-1;
	memset(G,-1,sizeof(G));
	read(N);
	for(int i=1;i<=N;i++){
		read(A[i]);
		Ans+=A[i];
	}
	for(int i=1;i<=N;i++){
		read(B[i]);
		Ans+=B[i];
	}
	read(M);
	S=++id,T=++id;
	for(int i=1;i<=N;i++)
		oA[i]=++id;
	for(int i=1;i<=M;i++)
		NodeA[i]=++id,NodeB[i]=++id;
	for(int i=1;i<=N;i++){
		Ins(S,oA[i],A[i]);
		Ins(oA[i],T,B[i]);
	}
	for(int i=1;i<=M;i++){
		read(k),read(c1),read(c2);
		Ins(S,NodeA[i],c1);
		Ins(NodeB[i],T,c2);
		Ans+=c1+c2;
		for(int j=1;j<=k;j++){
			read(x);
			Ins(NodeA[i],oA[x],INF);
			Ins(oA[x],NodeB[i],INF);
		}
	}
}

queue<int> Q;
bool BFS(){
	while(!Q.empty()) Q.pop();
	Q.push(S);
	memset(dist,-1,sizeof(dist));
	dist[S]=0;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		cur[k]=G[k];
		for(int u=G[k];u!=-1;u=E[u].next){
			int v=E[u].v;
			if(E[u].flow && dist[v]==-1){
				dist[v]=dist[k]+1;
				Q.push(v);
			}
		}
	}
	return dist[T]!=-1;
}

inline int DFS(int x,int f){
	if(x==T) return f;
	int cnt=f;
	while(f && cur[x]!=-1){
		int k=cur[x];
		int v=E[k].v;
		if(E[k].flow && dist[v]==dist[x]+1){
			int w=DFS(v,min(f,E[k].flow));
			E[k].flow-=w;
			E[k^1].flow+=w;
			f-=w;
		}
		cur[x]=E[cur[x]].next;
	}
	if(cnt-f==0) dist[x]=-1;
	return cnt-f;
}

void dinic(){
	while(BFS()) Ans-=DFS(S,INF);
}

void work(){
	dinic();
	print(Ans);
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;

}