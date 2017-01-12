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
#define MAXN (100005)
#define INF (0x7fffffff)
const double PI=acos(-1);
const int ZCY=1000000007;

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
	if(x<0) {x=-x;putchar('-');}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct SplayTree{
	struct Node{
		Node *lc,*rc,*fa;
		int val,size,cnt;
		Node (int _v=0):val(_v){cnt=size=1,lc=rc=fa=NULL;}
	}*root;
	
	inline void maintain(Node *p){
		p->size=p->cnt;
		if(p->lc) p->size+=p->lc->size;
		if(p->rc) p->size+=p->rc->size;
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
		Node *q=p->lc,*t=q->rc,*f=p->fa;
		p->fa=q,q->rc=p,p->lc=t;
		if(t) t->fa=p;
		q->fa=f;
		if(f) f->lc==p ? f->lc=q : f->rc=q;
		maintain(p),maintain(q);
		if(f) maintain(f);
	}
	
	inline void splay(Node *p){
		while(p->fa)
			p->fa->lc==p ? zag(p->fa) : zig(p->fa);
		root=p;
	}
	
	inline bool find(int v){
		Node *p=root;
		while(p)
			if(v>p->val) p=p->rc;
			else if(v<p->val) p=p->lc;
			else break;
		if(p) splay(p);
		return p!=NULL;
	}
	
	inline void Ins(int v){
		Node *p=root,*q=new Node(v);
		if(!p){
			root=q;
			return;
		}
		while(true){
			p->size++;
			if(p->val==v){
				p->cnt++;q=p;
				break;
			}else if(v>p->val){
				if(!p->rc){
					p->rc=q,q->fa=p;
					break;
				}else p=p->rc;
			}else{
				if(!p->lc){
					p->lc=q,q->fa=p;
					break;
				}else p=p->lc;
			}
		}
		splay(q);
	}
	
	inline void Del(int v){
		find(v);
		--(root->size),--(root->cnt);
		if(root->cnt) return;
		Node *p=root->lc,*q=root->rc;
		if(!p && !q){
			delete(root);root=NULL;
			return;
		}else if(!p){
			delete(root);root=q;root->fa=NULL;
			return;
		}else if(!q){
			delete(root);root=p;root->fa=NULL;
			return;
		}
		delete(root);p->fa=NULL;
		while(p->rc){
			p->size+=q->size;
			p=p->rc;
		}
		p->size+=q->size;
		p->rc=q,q->fa=p;
		splay(q);
	}

	inline int Rnk(int v){
		int ret=0;
		Node *p=root;
		while(p){
			if(v==p->val){
				ret+=(p->lc?p->lc->size:0);
				ret++;
				break;
			}else if(v>p->val){
				ret+=(p->lc?p->lc->size:0);
				ret+=p->cnt;
				p=p->rc;
			}else if(v<p->val)
				p=p->lc;
		}
		return ret;
	}
	
	inline int Val(int ps){
		int ret=0,tmp;
		Node *p=root;
		while(p){
			tmp=ret+(p->lc ? p->lc->size : 0);
			if(ps<=tmp) p=p->lc;
			else if(ps>tmp+p->cnt) ret=tmp+p->cnt,p=p->rc;
			else return p->val;
		}
		return -1;
	}
	
	inline int Pre(int v){
		Ins(v);
		Node *p=root;
		p=p->lc;
		while(p->rc) p=p->rc;
		Del(v);
		return p->val;
	}
	
	inline int Nxt(int v){
		Ins(v);
		Node *p=root;
		p=p->rc;
		while(p->lc) p=p->lc;
		Del(v);
		return p->val;
	}
}T;
int N;

void init(){
#ifdef Judge
	freopen("3224.in","r",stdin);
	freopen("3224.out","w",stdout);
//	SpeedUp;
#endif
}

void work(){
	int CMD,x;
	cin>>N;
	while(N--){
		read(CMD),read(x);
		switch(CMD){
			case 1:	T.Ins(x); break;
			case 2: T.Del(x); break;
			case 3:	print(T.Rnk(x)); break;
			case 4:	print(T.Val(x)); break;
			case 5:	print(T.Pre(x)); break;
			case 6:	print(T.Nxt(x)); break;
			default:cout<<"Error"<<endl;
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