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

struct LCTree{
	struct Node{
		Node *son[2],*fa;
		int sz;
		bool rev;
		Node(){
			son[0]=son[1]=fa=NULL;
			sz=1,rev=false;
		}		
		bool type_son(){
			return fa->son[0]!=this;		// lc:0, rc:1
		}
		bool is_root(){
			return (!fa || (fa->son[0]!=this && fa->son[1]!=this));
		}
		void maintain(){
			sz=(son[0]?son[0]->sz:0)+(son[1]?son[1]->sz:0)+1;
		}
		void pushdown(){
			if(!rev)	return;
			swap(son[1],son[0]);
			if(son[0])	son[0]->rev^=1;
			if(son[1])	son[1]->rev^=1;
			rev=false;
		}
		void set(Node *x,bool k){
			son[k]=x;
			if(x)	x->fa=this;
			maintain();
		}
	}node[MAXN];
	
	void rotate(Node *x){
		x->pushdown();
		int tp=x->type_son();
		Node *p=x->fa;
		if(p->is_root())	x->fa=p->fa;
		else p->fa->set(x,p->type_son());
		p->set(x->son[!tp],tp);
		x->set(p,!tp);
	}
	
	void splay(Node *x){
		while(!x->is_root()){
			x->fa->pushdown();
			if(x->fa->is_root())	rotate(x);
			else{
				x->fa->fa->pushdown();
				x->fa->pushdown();
				if(x->fa->type_son()==x->type_son())	rotate(x->fa),rotate(x);
				else rotate(x),rotate(x);
			}
		}
		x->pushdown();
	}
	
	void access(Node *x){
		for(Node *y=NULL;x;y=x,x=x->fa){
			splay(x);
			x->set(y,1);
		}
	}
	
	void makeroot(Node *x){
		access(x);
		splay(x);
		x->rev^=1;
	}
	
	bool Query(int u,int v){
		makeroot(&node[u]);
		access(&node[v]);
		splay(&node[v]);
		Node *t=&node[v];
		while(true){
			t->pushdown();
			if(!t->son[0])
				return t==&node[u];
			else t=t->son[0];
		}
	}
	
	void Link(int u,int v){
		makeroot(&node[u]);
		splay(&node[u]);
		node[u].fa=&node[v];
	}
	
	void Cut(int u,int v){
		makeroot(&node[u]);
		access(&node[v]);
		splay(&node[v]);
		node[v].son[0]->fa=node[v].fa;
		node[v].son[0]=NULL;
	}
}LCT;

int N,M;

void init(){
#ifdef Judge
	freopen("sdoi2008_cave.in","r",stdin);
	freopen("sdoi2008_cave.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d%d",&N,&M);
}

void work(){
	char cmd[10];
	int u,v;
	while(M--){
		scanf("%s%d%d",cmd,&u,&v);
//		read(u),read(v);
		switch(cmd[0]){
			case 'C':	LCT.Link(u,v);
						break;
			case 'D':	LCT.Cut(u,v);
						break;
			case 'Q':	puts(LCT.Query(u,v) ? "Yes" : "No");
						break;
			// default:	puts("Error!");
						// exit(0);
						// break;
		}
	}
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