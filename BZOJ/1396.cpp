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
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
#define Debug
#define MAXN (500000)
#define INF (0x7fffffff)
const double PI=acos(-1);
const int ZCY=1000000007;

inline int min(int a,int b){
	return a<b ? a : b;
}
inline int max(int a,int b){
	return a<b ? b : a;
}

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

char S[MAXN];
int C[MAXN];
int len;

struct SegTree{
private:
	struct Node{
		int val,tag;
		Node(){val=INF;tag=INF;}
	}node[MAXN*3];
	int sz;
#define lc id<<1
#define rc id<<1|1
	void maintain(int id){
		node[id].val=min(node[lc].val,node[rc].val);
	}
	void Build(int id,int l,int r){
		if(l==r) return;
		int mid=(l+r)>>1;
		Build(lc,l,mid);
		Build(rc,mid+1,r);
	}
	void down(int id){
		int tag=node[id].tag;
		if(tag!=INF){
			node[lc].val=min(node[lc].val,tag);
			node[lc].tag=min(node[lc].tag,tag);
			node[rc].tag=min(node[rc].tag,tag);
			node[rc].val=min(node[rc].val,tag);
		}
		node[id].tag=INF;
	}
	void Modify(int id,int l,int r,int s,int t,int x){
		down(id);		
		if(s<=l && r<=t){
			node[id].val=min(node[id].val,x);
			node[id].tag=min(node[id].tag,x);
			return;
		}
		int mid=(l+r)>>1;
		if(s<=mid)	Modify(lc,l,mid,s,t,x);
		if(t>mid)	Modify(rc,mid+1,r,s,t,x);
		maintain(id);
	}
	int Query(int id,int l,int r,int p){
#ifdef Debug
		printf("\tQuery(%d,%d,%d)\n",l,r,p);
#endif
		down(id);
		if(l==r)	return node[id].val;
		int mid=(l+r)>>1;
		return p<=mid ? Query(lc,l,mid,p) : Query(rc,mid+1,r,p);
	}
public:
	void Init(int n){
		sz=n;
//		Build(1,1,sz);
	}
	void Insert(int l,int r,int v){
		Modify(1,1,sz,l,r,v);
	}
	int Ask(int p){
		return Query(1,1,sz,p);
	}
}ST1,ST2;

struct Suffix_Automaton{
	struct Node{
		Node *fa,*son[26];
		int step;
		bool right;
		void Init(){
			memset(son,NULL,sizeof(son));
			fa=NULL,step=right=0;
		}
	}node[MAXN<<1],*fst,*fnl;
	int tot;
	
	void Init(){
		fst=fnl=&node[tot=1];
		fst->Init();
	}
	
	void Add(int x){
		Node *p=fnl,*np=&node[++tot];np->Init();
		np->step=p->step+1;
		np->right=1;
		while(p && !p->son[x]){
			p->son[x]=np;
			p=p->fa;
		}
		if(p==NULL){
			np->fa=fst;
		}else if(p->step+1==p->son[x]->step){
			np->fa=p->son[x];
		}else{
			Node *q=p->son[x],*nq=&node[++tot]; nq->Init();
			*nq=*q;
			nq->step=p->step+1;
			nq->right=0;
			np->fa=q->fa=nq;
			while(p && p->son[x]==q){
				p->son[x]=nq;
				p=p->fa;
			}
		}
		fnl=np;
	}
	
	void Calc_Info(){
		// for(int i=tot;i>1;i--){
			// Node *p=tmp[i];
			// if(p->fa)
				// p->fa->right+=p->right;
		// }
		for(int i=2;i<=tot;i++)
			node[i].fa->right=0;
		for(int i=2;i<=tot;i++){
			Node p=node[i];
			if(p.right==1){
				int l=p.step-p.fa->step,r=p.step;
				ST1.Insert(l,r,r-l+1);
				if(l>1)	ST2.Insert(1,l-1,r);
			}
		}
	}
}SAM;

void init(){
#ifdef Judge
	freopen("1396.in","r",stdin);
	freopen("1396.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%s",S);
	len=strlen(S);
	SAM.Init();
	for(int i=0;i<len;i++)
		SAM.Add(S[i]-'a');
	ST1.Init(len);
	ST2.Init(len);
}

void work(){
	SAM.Calc_Info();
	for(int i=1;i<=len;i++){
#ifdef Debug
		printf("\n\nWorking %d.\n",i);
#endif
		printf("%d\n",min(ST1.Ask(i),ST2.Ask(i)-i+1));
	}
}

int main(){
	init();
	work();
#ifdef Debug
	// cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	// cout<<"Memory Used : "<<(double)(sizeof(SAM)+sizeof(ST1)*2+sizeof(C))/1048576<<" MB."<<endl;
	printf("%lf\n",(double)(sizeof(SAM)+sizeof(ST1)*2+sizeof(C)+sizeof(S))/1048576);
#endif
	return 0;
}