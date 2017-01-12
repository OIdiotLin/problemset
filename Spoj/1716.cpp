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
#define MAXN (50005)
#define INF (1<<30)
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
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

inline int max(int a,int b,int c){return max(a,max(b,c));}

struct SegTree{
private:
	int size;
	struct SegNode{
		int val,pre,suf,sum;
		SegNode(int _v=-INF):
			val(_v),pre(_v),suf(_v){sum=0;}
	}node[MAXN<<2];
#define lc (id<<1)
#define rc (id<<1|1)
	void maintain(int id){
		node[id].pre=max(node[lc].pre,node[lc].sum+node[rc].pre);
		node[id].suf=max(node[rc].suf,node[rc].sum+node[lc].suf);
		node[id].val=max(node[lc].val,node[rc].val,node[lc].suf+node[rc].pre);
		node[id].sum=node[lc].sum+node[rc].sum;
	}
	
	void Build(int l,int r,int id){
		if(l==r){
			int x;	read(x);
			node[id]=SegNode(x);
			node[id].sum=x;
			return;
		}
		int mid=(l+r)>>1;
		Build(l,mid,lc);
		Build(mid+1,r,rc);
		maintain(id);
	}
	
	void Modify(int v,int p,int l,int r,int id){
		if(l==r){
			node[id]=SegNode(v);
			node[id].sum=v;
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid)	Modify(v,p,l,mid,lc);
		if(p>mid)	Modify(v,p,mid+1,r,rc);
		maintain(id);
	}
	
	SegNode Query(int s,int t,int l,int r,int id){
		if(s<=l && r<=t)	return node[id];
		SegNode LT,RT,AT;
		int mid=(l+r)>>1;
		if(s<=mid)	LT=Query(s,t,l,mid,lc);
		if(t>mid)	RT=Query(s,t,mid+1,r,rc);
		AT.pre=max(LT.pre,LT.sum+RT.pre);
		AT.suf=max(RT.suf,RT.sum+LT.suf);
		AT.val=max(LT.val,RT.val,LT.suf+RT.pre);
		AT.sum=LT.sum+RT.sum;
		return AT;
	}
public:
	SegTree(){size=0;}
	
	void Init(int n){
		size=n;
		Build(1,size,1);
	}
	
	void Change(int pos,int val){
		Modify(val,pos,1,size,1);
	}
	
	int Ask(int l,int r){
		return Query(l,r,1,size,1).val;
	}
}ST;

void init(){
	int N;
#ifdef Judge
	freopen("1716.in","r",stdin);
	freopen("1716.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	ST.Init(N);
}

void work(){
	int Q,CMD,r1,r2;
	read(Q);
	while(Q--){
		read(CMD);
		switch(CMD){
			case 0:	read(r1),read(r2);
					ST.Change(r1,r2);
					break;
			case 1:	read(r1),read(r2);
					print(ST.Ask(r1,r2));
					break;
			default:puts("Error !");
					return;
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