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
#define MAXN (300001)
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

struct SplayTree{
	struct Node{
		Node *lc,*rc,*fa;
		bool rev,val;
		Node (int _v=0):val(_v){lc=rc=fa=NULL;}
	}*root;
	
	inline void maintain(Node *p){
		
	}
	
	inline void zig(Node *p){
		Node *q=p->rc,*t=q->lc,*f=p->fa;
		p->fa=q,q->lc=p,p->rc=t;
		if(t) t->fa=p;
		q->fa=f;
		if(f) f->lc==p ? f->lc=q : f->rc=q;
		maintain(p),maintain(q);
		if(f) maintain(f);
	}
	
	inline void zag(Node *p){
		Node *q=p->lc,*t=p->rc,*f=p->fa;
		p->fa=q,q->rc=p,p->lc=t;
		if(t) t->fa=p;
		q->fa=f;
		if(f) f->lc==p ? f->lc=p : f->rc=p;
		maintain(p),maintain(q);
		if(f) maintain(f);
	}
	
	inline void splay(Node *p){
		while(p->fa)
			p->fa->lc==p ? zag(p->fa) : zig(p->fa);
		root=p;
	}
	
	inline void find(int v)
void init(){
#ifdef Judge
	freopen("3223.in","r",stdin);
	freopen("3223.out","w",stdout);
	SpeedUp;
#endif

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