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
#define MAXN (30005)
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

int N,M;

struct LinkCutTree{
	struct TagType{
		bool rev;
		int delta;
	};
	struct MsgType{
		int sum,size;
		MsgType(){}
		MsgType(const int &val){
			sum=val,size=1;
		}
		friend inline MsgType operator + (const MsgType &lc,const MsgType &rc){
			MsgType res;
			res.size=lc.size+rc.size;
			res.sum=lc.sum+rc.sum;
			return res;
		}
		inline void add(const int &val){
			sum+=size*val;
		}
	};
	struct Node{
		Node *fa,*lc,*rc;
		int val;
		MsgType msg;
		TagType tag;
		inline bool is_root(){
			return fa ? (fa->lc!=this && fa->rc!=this) : true;
		}
		inline void tag_rev(){
			tag.rev^=1;
		}
		inline void tag_add(const int &val){
			tag.delta+=val;
			msg.add(val);
		}
		inline void tag_down(){
			if(tag.rev){
				if(lc)	lc->tag_rev();
				if(rc)	rc->tag_rev();
				swap(lc,rc);
				tag.rev=false;
			}
			if(tag.delta){
				if(lc)	lc->tag_add(tag.delta);
				if(rc)	rc->tag_add(tag.delta);
				val+=tag.delta;
				tag.delta=0;
			}
		}
		inline void maintain(){
			msg=MsgType(val);
			if(lc)	msg=lc->msg+msg;
			if(rc)	msg=rc->msg+msg;
		}
	}node[MAXN+2];

	inline void rotate(Node *x){
		Node *y=x->fa,*z=y->fa,*b= y->lc==x ? x->rc : x->lc;
		x->fa=z,y->fa=x;
		if(b)	b->fa=y;
		if(z){
			if(z->lc==y)	z->lc=x;
			else if(z->rc==y)	z->rc=x;
		}
		if(y->lc==x)	x->rc=y,y->lc=b;
		else	x->rc=y,y->rc=b;
		y->maintain();
	}
	inline void splay(Node *x){
		static Node* anc[MAXN];
		int anc_cnt=0;
		anc[anc_cnt++]=x;
		for(Node *u=x;!u->is_root();u=u->fa)
			anc[anc_cnt++]=u->fa;
		for(int u=anc_cnt-1;~u;u--)
			anc[u]->tag_down();
		while(!x->is_root()){
			if(!x->fa->is_root())
				((x->fa->fa->lc==x->fa)^(x->fa->lc==x)) ? rotate(x) : rotate(x->fa);
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
	inline Node *find_root(Node *x){
		access(x);
		splay(x);
		x->tag_down();
		while(x->lc)
			x=x->lc,x->tag_down();
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
		if(find_root(x)==find_root(y)){
			puts("no");
			return;
		}
		puts("yes");
		make_root(x),make_root(y);
		x->fa=y;
	}
	inline void Cut(const int &u,const int &v){
		Node *x=&node[u],*y=&node[v];
		make_root(x);
		access(y),splay(y);
		if(x!=y->lc || x->lc || x->rc)	return;
		y->lc=NULL,y->rc=NULL;
		y->maintain();
	}
	inline void Modify(const int &u,const int &v){
		Node *x=&node[u];
		access(x);
		for(Node *p=x,*q=NULL;p;q=p,p=p->fa){
			splay(p);
			if(!p->fa){
				if(p->rc)	p->rc->tag_add(v-p->val);
				if(q)	q->tag_add(v-p->val);
				p->val=v;
			}
			p->rc=q,p->maintain();
			if(q)	q->fa=p;
		}
	}
	inline void Query(const int &u,const int &v){
		Node *x=&node[u],*y=&node[v];
		if(find_root(x)!=find_root(y)){
			puts("impossible");return;
		}
		access(x);
		for(Node *p=y,*q=NULL;p;q=p,p=p->fa){
			splay(p);
			if(!p->fa){
				MsgType res=p->val;
				if(p->rc){
					MsgType t=p->rc->msg;
					res = t+res;
				}
				if(q)	res=res+q->msg;
				print(res.sum);
			}
			p->rc=q,p->maintain();
			if(q)	q->fa=p;
		}
	}
}LCT;

void init(){
#ifdef Judge
	freopen("2843.in","r",stdin);
	freopen("2843.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++)
		read(LCT.node[i].val),LCT.node[i].maintain();
}

void work(){
	read(M);
	char CMD[10];
	int r1,r2;
	for(int i=1;i<=M;i++){
		scanf("%s",CMD);
		switch(CMD[0]){
			case 'b':	read(r1),read(r2);
						LCT.Link(r1,r2);
						break;
			case 'p':	read(r1),read(r2);
						LCT.Modify(r1,r2);
						break;
			case 'e':	read(r1),read(r2);
						LCT.Query(r1,r2);
						break;
		}
	}
}

int main(){
	init();
	work();
#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
