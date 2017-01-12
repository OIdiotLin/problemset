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
#define MAXN (10005)
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

struct Edge{
	int v,next,w;
	Edge(){}
	Edge(int _v,int _n,int _w):
		v(_v),next(_n),w(_w){}
}E[MAXN<<1];

int N,TEST,Q;
int G[MAXN],tot;
inline void Ins(int u,int v,int w){
	E[++tot]=Edge(v,G[u],w);	G[u]=tot;
	E[++tot]=Edge(u,G[v],w);	G[v]=tot;
}

struct LCT{
	struct MsgType{
		int sum,size;
		MsgType(){}
		MsgType(const int &val){
			sum=val;
			size=1;
		}
		inline MsgType operator + (const MsgType &t) const{
			MsgType res;
			res.size=size+t.size;
			res.sum=sum+t.sum;
			return res;
		}
	};
	struct TagType{
		bool rev;
		TagType(){}
		TagType(const bool &v){
			rev=v;
		}
	};
	struct Node{
		Node *fa,*lc,*rc;
		int val;
		MsgType msg;
		TagType tag;
		Node(){}
		Node(int _v):
			val(_v){fa=lc=rc=NULL;tag.rev=false;}
		inline bool is_root(){
			if(fa==NULL)	return true;
			return fa->lc!=this && fa->rc!=this;
		}
		inline void tag_rev(){
			tag.rev^=1;
		}
		inline void pushdown(){
			if(tag.rev){
				if(lc)	lc->tag_rev();
				if(rc)	rc->tag_rev();
				swap(lc,rc);
				tag.rev=false;
			}
		}
		inline void maintain(){
			msg=val;
			if(lc)	msg=lc->msg+msg;
			if(rc)	msg=msg+rc->msg;
		}
	}node[MAXN<<1];

	void Init(){
		tot=0;
		memset(G,0,sizeof(G));
	}

	void dfs(int x,int fa){
		for(int u=G[x];u;u=E[u].next){
			int v=E[u].v;
			if(v==fa)	continue;
			node[v].fa=&node[x];
			node[v].val=E[u].w;
			dfs(v,x);
		}
	}

	inline void rotate(Node *x){
		Node *y=x->fa,*z=y->fa;
		Node *b=y->lc==x?x->rc:x->lc;
		x->fa=z,y->fa=x;
		if(b)	b->fa=y;
		if(z){
			if(z->lc==y)	z->lc=x;
			if(z->rc==y)	z->rc=x;
		}
		if(y->lc==x)
			x->lc=y,y->lc=b;
		else
			x->rc=y,y->rc=b;
		y->maintain();
	}
	
	inline void splay(Node *x){
		int anc_n=0;
		static Node* anc[MAXN];
		anc[anc_n++]=x;
		for(Node *p=x;!p->is_root();p=p->fa)
			anc[anc_n++]=p->fa;
		for(int i=anc_n-1;~i;i--)
			anc[i]->pushdown();
		while(!x->is_root()){
			if(!x->fa->is_root())
				rotate(((x->fa->fa->lc==x->fa)^(x->fa->lc==x)) ? x : x->fa);
			rotate(x);
		}
		x->maintain();
	}

	inline void access(Node *x){
		for(Node *p=x,*q=NULL;p;q=p,p=p->fa){
			splay(p);
			p->rc=q,p->maintain();
			if(q)	q->fa=p;
		}
	}

	inline Node* find_root(Node *x){
		access(x);
		splay(x);
		x->pushdown();
		while(x->lc)
			x=x->lc,x->pushdown();
		splay(x);
		return x;
	}

	inline void make_root(Node *x){
		access(x);
		splay(x);
		x->tag_rev();
	}

	inline void Link(const int &u,const int &v){
		Node *x=&node[u],*y=&node[v];
//		if(find_root(x)==find_root(y))	return;
		make_root(x),make_root(y);
		x->fa=y;
	}

	inline void Cut(const int &u,const int &v){
		Node *x=&node[u],*y=&node[v];
//		if(find_root(x)!=find_root(y))	return;
		make_root(x);
		access(y),splay(y);
		if(y->lc!=x || x->lc || x->rc)	return;
		y->lc=NULL,x->fa=NULL;
		y->maintain();
	}

	inline Node* get_k(Node *x,int k){
		Node *p=x;
		while((p->lc?p->lc->msg.size:0)+1!=k){
			int cur=p->lc?p->lc->msg.size:0+1;
			if(k<cur)
				p=p->lc;
			else
				k-=cur,p=p->rc;
		}
		return p;
	}

	inline int QueryD(int x,int y){
		Node *u=&node[x],*v=&node[y];
		int res=0;
		access(v),v=NULL;
		while(u){
			splay(u);
			if(!u->fa)
				return (u->lc?u->lc->msg.sum:0) + (v?v->msg.sum:0);
			u->lc=v;
			u->maintain();
			v=u;
			u=u->fa;
		}
		return -1;
	}

	inline int QueryK(int x,int y,int k){
		Node *u=&node[x],*v=&node[y];
		int res=0;
		access(u);
		for(Node *p=NULL,*q=v;q;q->rc=p){
			splay(q);
			int cur=q->rc?q->rc->msg.size+1:1;
			if(q->is_root()){
				if(cur==k)	return q-node;
				if(cur>k)	return get_k(q->rc,cur-k)-node;
				if(cur<k)	return get_k(p,k-cur)-node;
			}
			q->maintain();
			p=q;
		}
	}
}T;

void Init(){
#ifdef Judge
	freopen("QTREE2.in","r",stdin);
	freopen("QTREE2.out","w",stdout);
//	SpeedUp;
#endif
	read(TEST);
}

char CMD[10];
int u,v,c;
void init(){
	read(N);
	T.Init();
	for(int i=1;i<N;i++){
		read(u),read(v),read(c);
		Ins(u,v,c);
	}
	T.dfs(1,0);
}

void work(){
	while(true){
		scanf("%s",CMD);
		switch(CMD[1]){
			case 'O':	return;
			case 'T':	read(u),read(v),read(c);
						print(T.QueryK(u,v,c));
						break;
			case 'I':	read(u),read(v);
						print(T.QueryD(u,v));
						break;
		}
	}
}

int main(){
	Init();
	for(int i=1;i<=TEST;i++){
		init();
		work();
	}
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
