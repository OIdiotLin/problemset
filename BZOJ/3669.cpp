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
#define MAXN ()
#define INF ()
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
#define sqr(x)	((x)*(x))

struct Edge{
	int u,v,a,b;
	Edge(){}
	Edge(int _u,int _v,int _a,int _b):
		u(_u),v(_v),a(_a),b(_b){}
	bool operator < (const Edge &t) const{
		return a==t.a ? b<t.b : a<t.a;
	}
}E[MAXM];

int N,M;
int fa[MAXN];
inline int f(int x){
	return fa[x]==x ? x : fa[x]=f(fa[x]);
}

struct LCT{
	struct Node{
		int fa,son[2];
		int size;
		bool rev;
		pair<int,int> msg;
	}node[MAXN];

	inline void maintain(int x){
		Node *p=&node[x],*lc=&node[p->son[0]],*rc=&node[p->son[1]];
		p->msg=P[x];
		if(p->son[0])	p->msg=max(p->msg,lc->msg);
		if(p->son[1])	p->msg=max(p->msg,rc->msg);
	}

	inline void pushdown(int x){
		Node *p=&node[x],*lc=&node[p->son[0]],*rc=&node[p->son[1]];
		if(p->rev){
			lc->rev^=1,rc->rev^=1;
			swap(lc,rc);
			p->rev=false;
		}
	}

	inline void rotate(int x,int k){
		pushdown(x),pushdown(node[x].son[k]);
		int y=node[x].son[k];
		node[x].son[k]=node[y].son[k^1];
		node[y].son[k^1]=x;
		if(node[x].fa!=-1)
			node[node[x].fa].son[node[node[x].fa].son[1]==x]=y;
		node[y].fa=node[x].fa;
		ndoe[x].fa=y;
		node[node[x].son[k]].fa=x;
		swap(fa[x],fa[y]);
		maintain(x),maintain(y);
	}

	inline void splay(int x,int tar=-1){
		while(node[x].fa!=s){
			if(node[node[x].fa].fa!=tar)
				rotate(node[node[x].fa].fa,(node[node[node[x].fa].fa].son[1]==node[x].fa)^(node[node[node[x].fa].fa].rev));
			rotate(node[x].fa,(node[node[x].fa].son[1]==x)^(node[node[x].fa].rev));
		}
	}

	inline void access(int x){
		int y=0;
		while(x!=-1){
			splay(x);
			pushdown(x);
			node[node[x].son[1]].fa=-1;
			fa[node[x].son[1]]=x;
			node[x].son[1]=y;
			node[y].fa=x;
			fa[y]=-1;
			maintain(x);
			x=fa[y=x];
		}
	}

	void find_root(int x){
		access(x),splay(x),pushdown(x);
		while(node[x].son[0])
			x=node[x].son[0],pushdown(x);
		return x;
	}
	inline void make_root(int x){
		access(x),splay(x);
		node[x].rev^=1;
	}
	inline void link(int x,int y){
		make_root(x),fa[x]=y;
	}
	inline void cut(int x,int y){
		access(x),splay(y);
		if(fa[y]==x)	fa[y]=-1;
		else	access(y),splay(x),fa[x]=-1;
	}

}

void init(){
#ifdef Judge
	freopen("3669.in","r",stdin);
	freopen("3669.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
}

void work(){
	;
}

int main(){
	init();
//#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
//#endif
	return 0;
}
