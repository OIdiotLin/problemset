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
	if(x<0){putchar('-'),x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

class Treap{
private:
	inline unsigned int Rand(){
		static unsigned int ran=791300089;
		ran+=(ran<<1)+19980716;
		return ran&INF;
	}
	
	struct Node{
		Node *lc,*rc;
		bool rev;
		int val,add,size,Max;
		Node(int _val=0):val(_val){add=0,size=1,Max=val,lc=rc=NULL,rev=false;}
	}*root;
	
	inline void maintain(Node *p){
		int t1=(p->rc ? p->rc->Max : -INF);
		int t2=(p->lc ? p->lc->Max : -INF);
		p->Max=max(max(t1,t2),p->val)+p->add;
		t1=(p->rc ? p->rc->size : 0);
		t2=(p->lc ? p->lc->size : 0);
		p->size=t1+t2+1;
	}
	
	/* Pushdown the tags: 1.add 2.rev */
	inline void Down(Node *p){
		if(p->add){
			p->val+=p->add;
			if(p->rc){
				p->rc->add+=p->add;
				p->rc->Max+=p->add;
			}
			if(p->lc){
				p->lc->add+=p->add;
				p->lc->Max+=p->add;
			}
			p->add=0;
		}
		if(p->rev){
			swap(p->lc,p->rc);
			if(p->lc) p->lc->rev^=1;
			if(p->rc) p->rc->rev^=1;
			p->rev=false;
		}
	}
	
	Node* Merge(Node *LT,Node *RT){
		if(!LT) return RT;
		if(!RT) return LT;
		Down(LT),Down(RT);
		if((int)Rand()%(LT->size+RT->size)<LT->size){
			LT->rc=Merge(LT->rc,RT);
			maintain(LT);
			return LT;
		}else{
			RT->lc=Merge(LT,RT->lc);
			maintain(RT);
			return RT;
		}
	}
	
	pair<Node*,Node*>split(Node *p,int id){
		if(!id || !p) return pair<Node*,Node*>(NULL,p);
		pair<Node*,Node*>res;
		Down(p);
		if(p->lc && p->lc->size>=id){
			res=split(p->lc,id);
			p->lc=res.second;
			res.second=p;
			maintain(p);
			return res;
		}else{
			int t1=(p->lc ? p->lc->size : 0);
			res=split(p->rc,id-t1-1);
			p->rc=res.first;
			res.first=p;
			maintain(p);
			return res;
		}
		return pair<Node*,Node*>(NULL,p);
	}
	
	inline void Build(Node *&p,int l,int r){
		if(l>r) return;
		p=new Node(0);
		Build(p->lc,l,((l+r)>>1)-1);
		Build(p->rc,((l+r)>>1)+1,r);
		maintain(p);
	}

public:
	pair<Node*,Node*>x,y;
	inline void Init(int sz){
		Build(root,1,sz);
	}
	
	inline void Add(int l,int r,int v){
		x=split(root,r);
		y=split(x.first,l-1);
		y.second->add+=v;
		y.second->Max+=v;
		root=Merge(Merge(y.first,y.second),x.second);
	}
	
	inline void Rev(int l,int r){
		x=split(root,r);
		y=split(x.first,l-1);
		y.second->rev^=1;
		root=Merge(Merge(y.first,y.second),x.second);
	}
	
	inline int Max(int l,int r){
		x=split(root,r);
		y=split(x.first,l-1);
		int ans=(y.second->Max);
		root=Merge(Merge(y.first,y.second),x.second);
		return ans;
	}
};

Treap Trp;
int N,M;

void init(){
#ifdef Judge
	freopen("1251.in","r",stdin);
	freopen("1251.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	Trp.Init(N);
}

void work(){
	int CMD,l,r,v;
	while(M--){
		read(CMD);
		switch(CMD){
			case 1:	read(l),read(r),read(v);
					Trp.Add(l,r,v);
					break;
			case 2:	read(l),read(r);
					Trp.Rev(l,r);
					break;
			case 3:	read(l),read(r);
					print(Trp.Max(l,r));
					break;
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
