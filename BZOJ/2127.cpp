/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (102)
#define MAXM (300005)
#define INF (1<<30)
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Edge{
	int v,next,flow;
	Edge(int _v=0,int _n=0,int _f=0):
		v(_v),next(_n),flow(_f){}
}E[MAXM];
int G[MAXN*MAXN],dist[MAXN*MAXN],cur[MAXN*MAXN];
int Arts[MAXN][MAXN],Science[MAXN][MAXN];
int S,T,N,M,tot,Ans;

inline void Ins1(int u,int v,int f){
	E[++tot]=Edge(v,G[u],f);	G[u]=tot;
	E[++tot]=Edge(u,G[v],0);	G[v]=tot;
}
inline void Ins2(int u,int v,int f){
	E[++tot]=Edge(v,G[u],f);	G[u]=tot;
	E[++tot]=Edge(u,G[v],f);	G[v]=tot;
}
#define id(i,j) (((i)-1)*M+(j))
void init(){
	int w;
#ifdef Judge
	freopen("2127.in","r",stdin);
	freopen("2127.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	S=0,T=N*M+2,tot=1;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			read(Arts[i][j]);
			Ans+=Arts[i][j];
			Arts[i][j]<<=1;
		}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			read(Science[i][j]);
			Ans+=Science[i][j];
			Science[i][j]<<=1;
		}
	for(int i=1;i<N;i++)
		for(int j=1;j<=M;j++){
			Ans+=read(w);
			Arts[i][j]+=w,Arts[i+1][j]+=w;
			Ins2(id(i,j),id(i+1,j),w);
		}
	for(int i=1;i<N;i++)
		for(int j=1;j<=M;j++){
			Ans+=read(w);
			Science[i][j]+=w,Science[i+1][j]+=w;
			Ins2(id(i,j),id(i+1,j),w);
		}
	for(int i=1;i<=N;i++)
		for(int j=1;j<M;j++){
			Ans+=read(w);
			Arts[i][j]+=w,Arts[i][j+1]+=w;
			Ins2(id(i,j),id(i,j+1),w);
		}
	for(int i=1;i<=N;i++)
		for(int j=1;j<M;j++){
			Ans+=read(w);
			Science[i][j]+=w,Science[i][j+1]+=w;
			Ins2(id(i,j),id(i,j+1),w);
		}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			Ins1(S,id(i,j),Arts[i][j]);
			Ins1(id(i,j),T,Science[i][j]);
		}
}

queue<int> Q;
bool BFS(){
	while(!Q.empty())	Q.pop();
	memset(dist,-1,sizeof(dist));
	dist[S]=0;
	Q.push(S);
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(E[u].flow && dist[v]==-1){
				dist[v]=dist[k]+1;
				Q.push(v);
			}
		}
	}
	return dist[T]!=-1;
}
int DFS(int x,int f){
	if(x==T)	return f;
	int cnt=f;
	for(int u=cur[x];u;u=E[u].next){
		int v=E[u].v;
		if(E[u].flow && dist[v]==dist[x]+1){
			int w=DFS(v,min(f,E[u].flow));
			E[u].flow-=w;
			E[u^1].flow+=w;
			if(E[u].flow)	cur[x]=u;
			f-=w;
			if(f==0)	return cnt;
		}
	}
	if(f==cnt)	dist[x]=-1;
	return cnt-f;
}
int dinic(){
	int maxflow=0;
	while(BFS()){
		memcpy(cur,G,sizeof(cur));
		maxflow+=DFS(S,INF);
	}
	return maxflow;
}

void work(){
	print(Ans-(dinic()>>1));
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