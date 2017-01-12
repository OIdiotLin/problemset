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
#define MAXN (40005)
#define MAXM (350005)
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
inline void outputLL(int x){
	char ch[18];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputLL(x)
#define read(x) x=getint()

int f(int);

struct SegTree{
	struct SegNode{
		int l,r;
		int v,Max;
		SegNode(int _l=0,int _r=0):
			l(_l),r(_r){v=Max=0;}
		bool leaf(){
			return l==r;
		}
	}s[MAXM];
#define lc (id<<1)
#define rc (id<<1|1)

	void Build(int id,int l,int r){
		s[id]=SegNode(l,r);
		if(l==r) return;
		int mid=(l+r)>>1;
		Build(lc,l,mid);
		Build(rc,mid+1,r);
	}
	
	void pushdown(int id){
		if(s[id].leaf()) return;
		if(s[id].v){
			s[lc].v=max(s[lc].v,s[id].v);
			s[lc].Max=max(s[lc].Max,s[id].Max);
			s[rc].v=max(s[rc].v,s[id].v);
			s[rc].Max=max(s[rc].Max,s[id].Max);
		}
		s[id].v=0;
	}
	
	void Modify(int id,int l,int r,int val){
		pushdown(id);
		if(s[id].l==l && s[id].r==r){
			s[id].v=val;
			s[id].Max=max(s[id].Max,val);
			return;
		}
		int mid=(s[id].l+s[id].r)>>1;
		if(r<=mid)	Modify(lc,l,r,val);
		else if(l>mid)	Modify(rc,l,r,val);
		else{
			Modify(lc,l,mid,val);
			Modify(rc,mid+1,r,val);
		}
	}
	
	int Query(int id,int p){
		pushdown(id);
		if(s[id].leaf()) return s[id].Max;
		int mid=(s[id].l+s[id].r)>>1;
		return (p<=mid ? Query(lc,p) : Query(rc,p));
	}
}ST;

struct Operation{
	int s,t,v;
	Operation(int _s=0,int _t=0,int _v=0):
		s(_s),t(_t),v(_v){}
	void ReNum(){
		s=f(s);
		t=f(t);
	}
}Q[MAXN];

int N;
int hash[MAXN<<1];

int f(int x){
	int l=1,r=N<<1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(hash[mid]<x) l=mid+1;
		else if(hash[mid]>x) r=mid-1;
		else return mid;
	}
	return -1;
}

void init(){
	int x,y,w;
#ifdef Judge
	freopen("1645.in","r",stdin);
	freopen("1645.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	ST.Build(1,1,N<<1);
	for(int i=1;i<=N;i++){
		read(x),read(y),read(w);
		Q[i]=Operation(x,y,w);
		hash[(i<<1)-1]=x,hash[i<<1]=y;
	}
	sort(hash+1,hash+(N<<1|1));
	for(int i=1;i<=N;i++)
		Q[i].ReNum();
	for(int i=1;i<=N;i++)
		ST.Modify(1,Q[i].s,Q[i].t-1,Q[i].v);
}

void work(){
	LL Ans=0;
	for(int i=1;i!=N<<1;i++)
		Ans+=(LL)ST.Query(1,i)*(hash[i+1]-hash[i]);
	print(Ans);
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