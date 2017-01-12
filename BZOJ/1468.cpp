/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
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
#define MAXN (40005)
#define MAXM (500005)
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
	int v,next,w;
	Edge(int _v=0,int _n=0,int _w=0):
		v(_v),next(_n),w(_w){}
}E[MAXM];

int N,K,ROOT,Ans,Sum,tot;
int G[MAXN],f[MAXN],son[MAXN],depth[MAXN];
int dist[MAXN];
bool vis[MAXN];

inline void Ins(int u,int v,int w){
	E[++tot]=Edge(v,G[u],w);	G[u]=tot;
	E[++tot]=Edge(u,G[v],w);	G[v]=tot;
}

void init(){
	int u,v,w;
#ifdef Judge
	freopen("1468.in","r",stdin);
	freopen("1468.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<N;i++){
		read(u),read(v),read(w);
		Ins(u,v,w);
	}
	read(K);
	Sum=N,f[0]=INF;
}

/*	Maintain the tree structure.	*/
void Choose_Root(int x,int fa){
	son[x]=1,f[x]=0;
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(v==fa||vis[v]) continue;
		Choose_Root(v,x);
		son[x]+=son[v];	
		f[x]=max(f[x],son[v]);
	}
	f[x]=max(f[x],Sum-son[x]);
	if(f[x]<f[ROOT])
		ROOT=x;
}
void Get_Depth(int x,int fa){
	depth[++tot]=dist[x];
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(v==fa||vis[v]) continue;
		dist[v]=dist[x]+E[u].w;
		Get_Depth(v,x);
	}
}

/*	Get_Ans.	*/
int Calc(int x,int now){
	dist[x]=now;
	tot=0;
	Get_Depth(x,0);
	sort(depth+1,depth+tot+1);
	int res=0,l=1,r=tot;
	while(l<r)
		depth[l]+depth[r]<=K ? res+=r-(l++) : --r;
	return res;
}

void Divide_Conquer(int x){
	Ans+=Calc(x,0);
	vis[x]=true;
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(vis[v]) continue;
		Ans-=Calc(v,E[u].w);
		Sum=son[v];
		ROOT=0;
		Choose_Root(v,ROOT);
		Divide_Conquer(ROOT);
	}
}

void work(){
	Choose_Root(1,0);
	Divide_Conquer(ROOT);
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