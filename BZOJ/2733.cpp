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
#define MAXM (6000005)
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

int val[MAXN],id[MAXN],fa[MAXN];
int N,M,Q;
char cmd[3];

inline int f(int x){
	return x==fa[x] ? x : fa[x]=f(fa[x]);
}

struct SegTree{
	struct Node{
		Node *lc,*rc;
		int sum;
		void Init(){
			lc=rc=NULL;
			sum=0;
		}
	}node[MAXN],*root[MAXN];
	int tot;
	
	void Init(){
		tot=0;
	}
	
	void Ins(Node *p,int l,int r,int v){
		p=&node[++tot];
		p->sum=1;
		if(l==r)	return;
		int mid=(l+r)>>1;
		if(v<=mid)	Ins(p->lc,l,mid,v);
		else		Ins(p->rc,mid+1,r,v);
	}
	
	Node* Merge(Node *lt,Node *rt,int l,int r){
		if(!lt)	return rt;
		if(!rt)	return lt;
		Node *nt=&node[++tot];
		nt->sum=lt->sum+rt->sum;
		int mid=(l+r)>>1;
		nt->lc=Merge(lt->lc,rt->lc,l,mid);
		nt->rc=Merge(lt->rc,rt->rc,mid+1,r);
		return nt;
	}
	
	int Query(Node *p,int l,int r,int k){
		if(l==r)	return l;
		int mid=(l+r)>>1;
		if(k<=p->lc->sum)
			return Query(p->lc,l,mid,k);
		else return Query(p->rc,mid+1,r,k-(p->lc->sum));
	}
	
	void Link(int u,int v){
		root[f(v)]=Merge(root[f(v)],root[f(u)],1,N);
		fa[f(u)]=f(v);
	}
	
	void Ask(int u,int k){
		if(root[f(u)]->sum<k)	puts("-1");
		else	print(id[Query(root[f(u)],1,N,k)]);
	}
}T;

void init(){
#ifdef Judge
	freopen("2733.in","r",stdin);
	freopen("2733.out","w",stdout);
//	SpeedUp;
#endif
	T.Init();
	read(N),read(M);
	for(int i=1;i<=N;i++){
		read(val[i]);
		fa[i]=i;
	}
	for(int i=1;i<=N;i++)
		id[val[i]]=i;
	for(int i=1;i<=N;i++)
		T.Ins(T.root[i],1,N,val[i]);
}

void work(){
	int u,v;
	for(int i=1;i<=M;i++){
		read(u),read(v);
		int fu=f(u),fv=f(v);
		if(fu==fv)	continue;
		T.Link(u,v);
	}
	read(Q);
	while(Q--){
		scanf("%s%d%d",cmd,&u,&v);
		switch(cmd[0]){
			case 'B':	T.Link(u,v);
						break;
			case 'Q':	T.Ask(u,v);
						break;
			default:	puts("Error!");
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