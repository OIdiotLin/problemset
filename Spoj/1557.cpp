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
#define MAXN (100003)
#define Zero (MAXN)
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
	if(x<0)	{putchar('-'); x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Interval{
	int l,r;
	int origin;
	Interval(int _l=0,int _r=0,int _o=0):
		l(_l),r(_r),origin(_o){}
	bool operator < (const Interval & t)const{
		return r<t.r;
	}
}Q[MAXN];

struct SegTree{
private:
	int size;
	struct SegNode{
		int hsty_add,hsty_max,cur_add,cur_max;		// add is a tag.
		SegNode(){hsty_add=hsty_max=cur_add=cur_max=0;}
	}node[MAXN<<2];
#define lc (id<<1)
#define rc (id<<1|1)
	void maintain(int id){
		node[id].hsty_max=max(node[lc].hsty_max,node[rc].hsty_max);
		node[id].cur_max=max(node[lc].cur_max,node[rc].cur_max);
	}

	void down(int id){
		node[lc].hsty_add=max(node[lc].hsty_add,node[lc].cur_add+node[id].hsty_add);
		node[rc].hsty_add=max(node[rc].hsty_add,node[rc].cur_add+node[id].hsty_add);
		node[lc].hsty_max=max(node[lc].hsty_max,node[id].hsty_add+node[lc].cur_max);
		node[rc].hsty_max=max(node[rc].hsty_max,node[id].hsty_add+node[rc].cur_max);
		node[lc].cur_add+=node[id].cur_add;
		node[rc].cur_add+=node[id].cur_add;
		node[lc].cur_max+=node[id].cur_add;
		node[rc].cur_max+=node[id].cur_add;
		node[id].hsty_add=node[id].cur_add=0;		// Clear tags.
	}

	void Modify(int v,int s,int t,int l,int r,int id){
		if(s==l && t==r){
			node[id].hsty_add=max(node[id].hsty_add,node[id].cur_add+=v);
			node[id].hsty_max=max(node[id].hsty_max,node[id].cur_max+=v);
			return;
		}
		down(id);
		int mid=(l+r)>>1;
		if(t<=mid)	Modify(v,s,t,l,mid,lc);
		else if(s>mid)	Modify(v,s,t,mid+1,r,rc);
		else{
			Modify(v,s,mid,l,mid,lc);
			Modify(v,mid+1,t,mid+1,r,rc);
		}
		maintain(id);
	}

	int Query(int s,int t,int l,int r,int id){
		if(l==s && r==t)	return node[id].hsty_max;
		down(id);
		int mid=(l+r)>>1;
		if(t<=mid)	return Query(s,t,l,mid,lc);
		if(s>mid)	return Query(s,t,mid+1,r,rc);
		return max(Query(s,mid,l,mid,lc),Query(mid+1,t,mid+1,r,rc));
	}
public:
	void Init(int n){
		size=n;
	}

	void Insert(int v,int l,int r){
		Modify(v,l,r,1,size,1);
	}

	int Ask(int l,int r){
		return Query(l,r,1,size,1);
	}
}ST;

int A[MAXN],Ans[MAXN],pos[(MAXN<<1)+10];
int N,M;

void init(){
	int l,r;
#ifdef Judge
	freopen("1557.in","r",stdin);
	freopen("1557.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	ST.Init(N);
	for(int i=1;i<=N;i++)
		read(A[i]);
	read(M);
	for(int i=1;i<=M;i++){
		read(l),read(r);
		Q[i]=Interval(l,r,i);
	}
	sort(Q+1,Q+M+1);
}

void work(){
	for(int i=1,j=1;i<=N&&j<=M;i++){
		ST.Insert(A[i],pos[A[i]+Zero]+1,i);
		pos[A[i]+Zero]=i;
		while(j<=M&&Q[j].r==i){
			Ans[Q[j].origin]=ST.Ask(Q[j].l,Q[j].r);
			++j;
		}
	}
	for(int i=1;i<=M;i++)
		print(Ans[i]);
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