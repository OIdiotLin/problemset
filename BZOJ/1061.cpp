/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (1005)
#define MAXM (50005)
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
	int u,v,next,flow,cost;
	Edge(int _u=0,int _v=0,int _n=0,int _f=INF,int _c=0):
		u(_u),v(_v),next(_n),flow(_f),cost(_c){}
}E[MAXM];
int G[MAXN],dist[MAXN],pre[MAXN];
bool vis[MAXN];
int N,M,S,T,Ans,tot;

inline void Ins(int u,int v,int f,int c){
	E[++tot]=Edge(u,v,G[u],f,c);	G[u]=tot;
	E[++tot]=Edge(v,u,G[v],0,-c);	G[v]=tot;
}

void init(){
	int last=0,s,t,c;
#ifdef Judge
	freopen("1061.in","r",stdin);
	freopen("1061.out","w",stdout);
//	SpeedUp;
#endif
	tot=1;
	read(N),read(M);
	S=0,T=MAXN-1;
	for(int i=1;i<=N;i++){
		read(s);
		int delt=s-last;
		delt>0 ? Ins(S,i,delt,0) : Ins(i,T,-delt,0);
		Ins(i+1,i,INF,0);
		last=s;
	}
	Ins(N+1,T,last,0);
	for(int i=1;i<=M;i++){
		read(s),read(t),read(c);
		Ins(s,t+1,INF,c);
	}
}

queue<int> Q;
bool SPFA(){
	while(!Q.empty()) Q.pop();
	for(int i=S;i<=T;i++) dist[i]=INF;
	dist[S]=0;
	vis[S]=true;
	Q.push(S);
	
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(E[u].flow && dist[k]+E[u].cost<dist[v]){
				dist[v]=dist[k]+E[u].cost; 
				pre[v]=u;
				if(!vis[v]){
					vis[v]=true;
					Q.push(v);
				}
			}
		}
		vis[k]=false;
	}
	return dist[T]!=INF;
}

void mCF(){
	int w=INF;
	for(int u=pre[T];u;u=pre[E[u].u])
		w=min(w,E[u].flow);
	for(int u=pre[T];u;u=pre[E[u].u]){
		E[u].flow-=w;
		E[u^1].flow+=w;
		Ans+=E[u].cost*w;
	}
}

void minCmaxF(){
	while(SPFA()) mCF();
}

void work(){
	minCmaxF();
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
