/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (250)
#define MAXM (20005)
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
	Edge(int _v=0,int _n=-1,int _f=0):v(_v),next(_n),flow(_f){}
}E[MAXM];

int G[MAXN],dist[MAXN];
int N,M,S,T,tot,Ans;
bool Map[MAXN][MAXN];

inline void Ins(int u,int v,int f){
	E[++tot]=Edge(v,G[u],f);	G[u]=tot;
	E[++tot]=Edge(u,G[v],0);	G[v]=tot;
}

void init(){
	int x,y;
	tot=-1;
#ifdef Judge
	freopen("1143.in","r",stdin);
	freopen("1143.out","w",stdout);
//	SpeedUp;
#endif
	memset(G,-1,sizeof(G));
	read(N),read(M);
	S=1,T=(N+1)<<1;
	Ans=N;
	for(int i=1;i<=M;i++){
		read(x),read(y);
		Map[x][y]=true;
	}
	for(int i=1;i<=N;i++){
		Map[i][i]=true;
		Ins(S,i<<1,1);
		Ins(i<<1|1,T,1);
	}
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				Map[i][j]|=Map[i][k]&Map[k][j];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(i!=j && Map[i][j])
				Ins(i<<1,j<<1|1,1);
}

queue<int> Q;
bool BFS(){
	while(!Q.empty()) Q.pop();
	memset(dist,-1,sizeof(dist));
	dist[S]=0;
	Q.push(S);
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
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

int DFS(int x,int f){
	if(x==T) return f;
	int cnt=f;
	for(int u=G[x];u!=-1;u=E[u].next){
		int v=E[u].v;
		if(E[u].flow && dist[v]==dist[x]+1){
			int w=DFS(v,min(f,E[u].flow));
			E[u].flow-=w;
			E[u^1].flow+=w;
			cnt-=w;
			if(cnt==0) return f;
		}
	}
	return f-cnt;
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
