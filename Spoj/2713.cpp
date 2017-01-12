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
#define INF (1<<30)
const double PI=acos(-1);
const int ZCY=1000000007;

inline LL getint(){
	LL x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct SegTree{
private:
	int size;
	struct SegNode{
		LL sum;
		SegNode(LL _s=0):
			sum(_s){}
	}node[MAXN<<2];
#define lc (id<<1)
#define rc (id<<1|1)
	void maintain(int id){
		node[id].sum=node[lc].sum+node[rc].sum;
	}

	void Build(int l,int r,int id){
		if(l==r){
			LL x;	read(x);
			node[id].sum=x;
			return;
		}
		int mid=(l+r)>>1;
		Build(l,mid,lc);
		Build(mid+1,r,rc);
		maintain(id);
	}

	void Modify(int s,int t,int l,int r,int id){
		/* All the elements in [l,r] is 1 */
		if(r-l+1==node[id].sum) return;
		if(l==r){
			node[id].sum=(LL)sqrt(node[id].sum);		//	Less than 8 times. 
			return;
		}
		int mid=(l+r)>>1;
		if(t<=mid)	Modify(s,t,l,mid,lc);
		else if(s>mid)	Modify(s,t,mid+1,r,rc);
		else{
			Modify(s,mid,l,mid,lc);
			Modify(mid+1,t,mid+1,r,rc);
		}
		maintain(id);
	}

	LL Query(int s,int t,int l,int r,int id){
		if(s==l && t==r)	return node[id].sum;
		int mid=(l+r)>>1;
		if(t<=mid)	return Query(s,t,l,mid,lc);
		if(s>mid)	return Query(s,t,mid+1,r,rc);
		return Query(s,mid,l,mid,lc)+Query(mid+1,t,mid+1,r,rc);
	}
public:
	SegTree(){size=0;}

	void Init(int n){
		size=n;
		Build(1,size,1);
	}

	void Sqrt(int l,int r){
		Modify(l,r,1,size,1);
	}

	LL Ask(int l,int r){
		return Query(l,r,1,size,1);
	}
}ST;

int cas,N;

void init(){
#ifdef Judge
	freopen("2713.in","r",stdin);
	freopen("2713.out","w",stdout);
//	SpeedUp;
#endif
	cas=0;
}

void work(int cas){
	int Q,CMD,l,r;
	ST.Init(N);
	read(Q);
	printf("Case #%d:\n",cas);
	while(Q--){
		read(CMD);
		switch(CMD){
			case 0:	read(l),read(r);
					if(l>r)	swap(l,r);
					ST.Sqrt(l,r);
					break;
			case 1:	read(l),read(r);
					if(l>r)	swap(l,r);
					print(ST.Ask(l,r));
					break;
			default:puts("Error !");
					return;
		}
	}
	puts("");
}

int main(){
	init();
	while(scanf("%d",&N)!=EOF)
		work(++cas);
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
