/*
	Machine: Class4_B2
	System: Ubuntu_Kylin 14.10
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
#define MAXN (2005)
#define MAXM (5000002)
#define INF (~0u>>2)
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
	if(x==0) {putchar('0'); putchar(32);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(32);
}
#define print(x) outputint(x)
#define read(x) x=getint()
#define sqr(x)	((x)*(x))

inline int gcd(int x,int y){
	return y ? gcd(y,x%y) : x;
}

struct Edge{
	int u,v,next,flow,cost;
	Edge(){}
	Edge(int _u,int _v,int _n,int _f,int _c):
		u(_u),v(_v),next(_n),flow(_f),cost(_c){}
}E[MAXM];

int G[MAXN],dist[MAXN],pre[MAXN];
bool vis[MAXN];
int L,R,S,T,tot;
int maxflow,mincost;

inline void Ins(int u,int v,int f,int c){
	E[++tot]=Edge(u,v,G[u],f,c);	G[u]=tot;
	E[++tot]=Edge(v,u,G[v],0,-c);	G[v]=tot;
}

inline bool chk(int x,int y){
	if(gcd(x,y)!=1)	return false;
	int p=sqr(x)-sqr(y),q=sqrt(p);
	return sqr(q)==p;
}

void init(){
#ifdef Judge
	freopen("2661.in","r",stdin);
	freopen("2661.out","w",stdout);
//	SpeedUp;
#endif;
	scanf("%d%d",&L,&R);
	S=0,T=2001,tot=1;
	for(int i=L;i<=R;i++){
		Ins(S,i,1,0);
		Ins(i+R,T,1,0);
		for(int j=L;j<i;j++)
			if(chk(i,j))
				Ins(i,j+R,1,-(i+j));
	}
}

bool SPFA(){
	static queue<int> Q;
	for(int i=S;i<=T;i++)
		dist[i]=INF;
//	memset(dist,128,sizeof(dist));
	while(!Q.empty())	Q.pop();
	dist[S]=0;
	Q.push(S);
	vis[S]=true;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		vis[k]=false;
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(E[u].flow && dist[v]>dist[k]+E[u].cost){
				dist[v]=dist[k]+E[u].cost;
				pre[v]=u;
				if(!vis[v]){
					vis[v]=true;
					Q.push(v);
				}
			}
		}
//		vis[k]=false;
	}
	return dist[T]!=INF;
}

void MCF(){
	int f=INF;
	for(int u=pre[T];u;u=pre[E[u].u])
		f=min(f,E[u].flow);
	for(int u=pre[T];u;u=pre[E[u].u]){
		E[u].flow-=f;
		E[u^1].flow+=f;
	}
	maxflow+=f;
	mincost+=f*dist[T];
}

void work(){
	while(SPFA())	MCF();
	printf("%d %d",maxflow,-mincost);
}

int main(){
	init();
	work();
#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(E)+sizeof(G)*3)/1048576<<" MB."<<endl;
#endif
	return 0;
}
