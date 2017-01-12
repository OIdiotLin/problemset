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
#define MAXN (10005)
#define INF ()
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

struct edge{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):
		u(u),v(v),w(w){}
}e[MAXN];

struct Edge{
	int v,next;
	Edge(int _v=0,int _n=0):
		v(_v),next(_n){}
}E[MAXN<<1];
int G[MAXN],W[MAXN],tot=0;

inline void Ins(int u,int v){
	E[++tot]=Edge(v,G[u]);	G[u]=tot;
	E[++tot]=Edge(u,G[v]);	G[v]=tot;
}

int pre[MAXN],dist[MAXN],heavy[MAXN],size[MAXN],top[MAXN],pos[MAXN],cnt;
void dfs(int x,int f){
	dist[x]=dist[f]+1;
	size[x]=1;
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(v==f)	continue;
		pre[v]=x;
		dfs(v,x);
		if(!heavy[x] || size[v]>size[heavy[x]])
			heavy[x]=v;
		size[x]+=size[v];
	}
}

void dfs2(int x,int f){
	pos[x]=++cnt;
	top[x]=f;
	if(heavy[x])
		dfs2(heavy[x],f);
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(v!=pre[x] && v!=heavy[x])
			dfs2(v,v);
	}
}

struct SegTree{
private:
	struct Node{
		int mx;
		Node(){
			mx=0;
		}
	}node[MAXN<<2];
	int sz;
#define lc id<<1
#define rc id<<1|1
	inline void maintain(int id){
		node[id].mx=max(node[lc].mx,node[rc].mx);
	}
	void Modify(int id,int l,int r,int p,int v){
		if(l==r){
			node[id].mx=v;
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid)	Modify(lc,l,mid,p,v);
		else Modify(rc,mid+1,r,p,v);
		maintain(id);
	}	
	int Query(int id,int l,int r,int s,int t){
		if(s<=l && r<=t)
			return node[id].mx;
		int mid=(l+r)>>1;
		if(t<=mid)	return Query(lc,l,mid,s,t);
		if(s>mid)	return Query(rc,mid+1,r,s,t);
		return max(Query(lc,l,mid,s,t),Query(rc,mid+1,r,s,t));
	}
public:
	inline void Init(int n){
		memset(node,0,sizeof(node));
		sz=n;
	}
	inline void Insert(int p,int x){
		Modify(1,1,sz,p,x);
	}
	inline int Ask(int l,int r){
		return Query(1,1,sz,l,r);
	}
}ST;

int T,N;
char cmd[8];

void init(){
#ifdef Judge
	freopen("QTREE.in","r",stdin);
	freopen("QTREE.out","w",stdout);
//	SpeedUp;
#endif
	read(T);
}

void work(){
	cnt=tot=0;
	memset(G,0,sizeof(G));
	memset(heavy,0,sizeof(heavy));
	int u,v,w,fu,fv,res;
	read(N);
	for(int i=1;i<N;i++){
		read(u),read(v),read(w);
		e[i]=edge(u,v,w);
		Ins(u,v);
	}
	dist[0]=0;
	dfs(1,0);
	dfs2(1,1);
	ST.Init(cnt);
	for(int i=1;i<N;i++){
		if(dist[e[i].u]>dist[e[i].v])
			swap(e[i].u,e[i].v);
		ST.Insert(pos[e[i].v],e[i].w);
	}
	while(scanf("%s",cmd)!=EOF)
		switch(cmd[0]){
			case 'Q':	read(u),read(v);
						fu=top[u],fv=top[v],res=0;
						while(fu!=fv){
							if(dist[fu]<dist[fv])
								swap(fu,fv),swap(u,v);
							res=max(res,ST.Ask(pos[fu],pos[u]));
							u=pre[fu];
							fu=top[u];
						}
						if(u==v){
							print(res);
							break;
						}
						if(dist[u]>dist[v])	swap(u,v);
						print(max(res,ST.Ask(pos[heavy[u]],pos[v])));
						break;
			case 'C':	read(u),read(v);
						ST.Insert(pos[e[u].v],v);
						break;
			case 'D':	return;
		}
}

int main(){
	init();
	while(T--){
		work();
		if(T)	puts("");
	}
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}