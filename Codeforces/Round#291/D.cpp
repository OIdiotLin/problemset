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
	if(x==0) {putchar('0'); putchar(32);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(32);
}
#define print(x) outputint(x)
#define read(x) x=getint()

int tmp[6],ans[6];
int N,M,K;

struct SegTree{
private:
	struct Node{
		int l,r;
		int mx[6];
		Node(int _l=0,int _r=0):
			l(_l),r(_r){memset(mx,128,sizeof(mx));}
	}node[MAXN<<2];
	int sz;
#define lc id<<1
#define rc id<<1|1
	void maintain(int id){
		for(int i=1;i<=M;i++)
			node[id].mx[i]=max(node[lc].mx[i],node[rc].mx[i]);
	}
	
	void Build(int id,int l,int r){
		node[id]=Node(l,r);
		if(l==r){
			for(int i=1;i<=M;i++)
				read(node[id].mx[i]);
			return;
		}
		int mid=(l+r)>>1;
		Build(lc,l,mid);
		Build(rc,mid+1,r);
		maintain(id);
	}
	
	void Query(int id,int s,int t){
#ifdef Debug
		printf("Query (%d, %d):\n",s,t);
#endif
		int l=node[id].l,r=node[id].r;
		if(s<=l && r<=t){
			for(int i=1;i<=M;i++)
				tmp[i]=max(tmp[i],node[id].mx[i]);
			return;
		}
		int mid=(l+r)>>1;
		if(t<=mid)	Query(lc,s,t);
		else if(s>mid)	Query(rc,s,t);
		else Query(lc,s,mid),Query(rc,mid+1,t);
	}
public:
	void Init(int n){
		sz=n;
		Build(1,1,sz);
	}
	
	void Ask(int l,int r){
		Query(1,l,r);
	}
}ST;

void init(){
#ifdef Judge
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M),read(K);
	ST.Init(N);
}

bool chk(int x){
	for(int i=1;i<=N-x+1;i++){
		int cnt=0;
		ST.Ask(i,i+x-1);
		for(int j=1;j<=M;j++)
			cnt+=tmp[j];
		if(cnt<=K)
			goto success;
		memset(tmp,0,sizeof(tmp));
	}
	return false;
	success:
	memcpy(ans,tmp,sizeof(ans));
	memset(tmp,0,sizeof(tmp));
	return true;
}

void work(){
	int l=1,r=N;
	while(l<=r){
		int mid=(l+r)>>1;
		chk(mid) ? l=mid+1 : r=mid-1;
	}
	for(int i=1;i<=M;i++)
		print(ans[i]);
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(ST)+sizeof(ans)*2)/1048576<<" MB."<<endl;
#endif
	return 0;
}