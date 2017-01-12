/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <queue>
#include <stack>
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
#define MAXN (602)
#define MAXM (300002)
#define INF (0x7fffffff)
const double PI=acos(-1);
const int ZCY=1000000007;

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
}E[MAXM<<1];
int G[MAXN],cnt;

struct edge{
	int v,next;
	edge(int _v=0,int _n=0):
		v(_v),next(_n){}
}e[MAXM];
int g[MAXN];

int N,M,Ans,tot,S,T;
int in[MAXN],cur[MAXN],dist[MAXN];
bool ban[MAXN];
int score[MAXN];

inline void Ins(int u,int v){
	in[v]++;
	e[++tot]=edge(v,g[u]);		g[u]=tot;
}
inline void Ins(int u,int v,int f){
	E[++tot]=Edge(v,G[u],f);	G[u]=tot;
	E[++tot]=Edge(u,G[v],0);	G[v]=tot;
}

#define id(i,j) (((i)-1)*M+(j))
void init(){
	int w,r,c;
#ifdef Judge
	freopen("1565.in","r",stdin);
	freopen("1565.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			read(score[id(i,j)]);
			read(w);
			while(w--){
				read(r),read(c);
				Ins(id(i,j),id(r+1,c+1));
			}
		}
	for(int i=1;i<=N;i++)
		for(int j=M;j!=1;j--)
			Ins(id(i,j),id(i,j-1));
}

void dfs(int x){
	ban[x]=true;
	for(int u=g[x];u;u=e[u].next){
		int v=e[u].v;
		if(!ban[v])
			dfs(v);
	}
}

stack<int> Stk;
void Top_Sort(){
	while(!Stk.empty()) Stk.pop();
	for(int i=1;i<=N*M;i++)
		if(in[i]) 	ban[i]=true;
		else 		Stk.push(i);

	while(!Stk.empty()){
		int k=Stk.top();
		ban[k]=false;
		Stk.pop();
		for(int u=g[k];u;u=e[u].next){
			int v=e[u].v;
			if((--in[v])==0)
				Stk.push(v);
		}
	}
	for(int i=1;i<=N*M;i++)
		if(ban[i])
			dfs(i);
}

void Make_NewG(){
	tot=1,S=0,T=N*M+1;
	for(int i=1;i<=N*M;i++){
		if(ban[i]) continue;
		if(score[i]>0){
			Ans+=score[i];
			Ins(i,T,score[i]);
		}else Ins(S,i,-score[i]);
		for(int u=g[i];u;u=e[u].next){
			int v=e[u].v;
			if(!ban[v])
				Ins(i,v,INF);
		}
	}
}

queue<int> Q;
bool BFS(){
	while(!Q.empty()) Q.pop();
	memset(dist,-1,sizeof(dist));
	Q.push(S);
	dist[S]=0;
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
	if(x==T) return f;
	int cnt=f;
	for(int u=cur[x];u;u=E[u].next){
		int v=E[u].v;
		if(dist[v]==dist[x]+1){
			int w=DFS(v,min(E[u].flow,f));
			E[u].flow-=w;
			E[u^1].flow+=w;
			if(E[u].flow) cur[x]=u;
			f-=w;
			if(f==0)
				return cnt;
		}
	}
	if(cnt==f) dist[x]=-1;
	return cnt-f;
}

void dinic(){
	while(BFS()){
		for(int i=S;i<=T;i++) cur[i]=G[i];
		Ans-=DFS(S,INF);
	}
}

void work(){
	Top_Sort();
	Make_NewG();
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