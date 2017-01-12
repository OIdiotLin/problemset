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
/* /* //#define Debug */ */
#define MAXN (300001)
#define INF (1<<28)
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
		Node *son[2],*fa;
		int size,val,sum,lmx,rmx,ans;
		Node(){}
		int type(){
			return fa->son[1]==this;
		}
	}node[MAXN],*root,*nil;
	int tot;
	
	Node* NewNode(int val,Node *f){
		Node *np=node+(++tot);
		np->sum = np->lmx = np->rmx = np->val = np->ans = val;
		np->son[0] = np->son[1] = nil;
		np->size = 1;
		np->fa = f;
		return np;
	}
	
	inline void maintain(Node *p){
		if(p==nil)	return;
		p->size = p->son[0]->size + p->son[1]->size + 1;
		p->sum = p->son[0]->size + p->son[1]->size + p->val;
		p->lmx = max(p->son[0]->lmx , max(p->son[0]->sum + p->val , p->son[0]->sum + p->val + p->son[1]->lmx));
		p->rmx = max(p->son[1]->rmx , max(p->son[1]->sum + p->val , p->son[1]->sum + p->val + p->son[0]->rmx));
		p->ans = max(max(0,p->son[0]->rmx) + p->val + max(0,p->son[1]->lmx) , max(p->son[0]->ans , p->son[1]->ans));
	}
	
	inline void Init(){
		tot=-1;
		nil=0;	nil = NewNode(-INF,0);
		nil->sz = 0;
		root = NewNode(-INF,nil);
		root->son[1] = NewNode(-INF,root);
		nil->sum = root->sum = root->son[1]->sum = 0;
		maintain(root);
	}
	
	inline void rotate(Node *x,int k){
		Node *y = x->fa;
		y->son[k] = x->son[!k];
		y->son[k]->fa = y;
		x->fa = y->fa;
		y->fa->son[y->type()] = x;
		y->fa = x;
		x->son[!k] = y;
		maintain(y);
		maintain(x);
		if(y == root)	root = x;
	}
	
	inline void splay(Node *x,Node *y){
		while(x->fa != y){
			int tx = x->type(), tf = x->fa->type();
			if(x->fa->fa == y)
				rotate(x,tx);
			else if(tf == 0){
				if(tx == 0)	rotate(x->fa,0);
				else	rotate(x,1);
				rotate(x,0);
			}else{
				if(tf == 1)	rotate(x->fa,1);
				else 	rotate(x,0);
				rotate(x,1);
			}
		}
	}
	
	inline void choose(int k,)
void init(){ 
#ifdef Judge
	freopen("GSS6.in","r",stdin);
	freopen("GSS6.out","w",stdout);
//	SpeedUp;
#endif
	
}

void work(){
	
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