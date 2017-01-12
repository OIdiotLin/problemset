/*
	Machine: OIdiot's Lenovo E440
	System: Windows10 64bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (100003)
#define MAXM (100003)
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
inline void outputint(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
}
#define print(x) outputint(x)
#define read(x) x=getint()

int N,M,K;
struct operation{
	int l,r;
	LL val;
	operation(int _l=0,int _r=0,LL _val=0):
		l(_l),r(_r),val(_val){}
	void Read(){
		read(l),read(r),read(val);
	}
}opArr[MAXM];
struct SegmentTree{
	struct Tnode{
		LL add,sum;
		Tnode(LL _add=0,LL _sum=0):
			add(_add),sum(_sum){}
		void clear(){
			add=0;
		}
	}node[MAXM<<2];
	void init(){
		memset(node,0,sizeof(node));
	}
	#define lc (id<<1)
	#define rc (id<<1|1)
	void pushDown(int len,int id){
		if(!node[id].add)	return;
		node[lc].add+=node[id].add;
		node[rc].add+=node[id].add;
		node[lc].sum+=node[id].add*(len-(len>>1));
		node[rc].sum+=node[id].add*(len>>1);
		node[id].clear();
	}
	void update(int s,int t,LL val,int l,int r,int id){
		if(s<=l && t>=r){
			node[id].add+=val;
			node[id].sum+=(t-s+1)*val;
			return;
		}
		int mid=((l+r)>>1);
		pushDown(t-s+1,id);
		if(s<=mid)	update(s,t,val,l,mid,lc);
		if(t>mid)	update(s,t,val,mid+1,r,rc);
		node[id].sum=node[lc].sum+node[rc].sum;
	}
	LL query(int s,int t,int l,int r,int id){
		LL ret=0;
		if(s<=l && t>=r)	return node[id].sum;
		int mid=((l+r)>>1);
		pushDown(t-s+1,id);
		if(s<=mid)	ret+=query(s,t,l,mid,lc);
		if(t>mid)	ret+=query(s,t,mid+1,r,rc);
		return ret;
	}
	void update(int s,int t,LL val){
		update(s,t,val,1,M,1);
	}
	void update(int pos,LL val){
		update(pos,pos,val,1,N,1);
	}
	LL query(int pos){
		return query(pos,pos,1,M,1);
	}
}T;
int arr[MAXN];

void init(){
#ifdef Judge
	freopen("295A.in","r",stdin);
	freopen("295A.out","w",stdout);
//	SpeedUp;
#endif
}

void work(){
	read(N),read(M),read(K);
	for(int i=1;i<=N;i++){
		read(arr[i]);
	}
	T.init();
	for(int i=1;i<=M;i++){
		opArr[i].Read();
	}
	for(int i=1;i<=K;i++){
		int l,r;
		read(l),read(r);
		T.update(l,r,1);
	}
	for(int i=1;i<=M;i++){
		opArr[i].val*=T.query(i);
		print(T.query(i));
	}
	T.init();
	for(int i=1;i<=N;i++)
		T.update(i,arr[i]);
	for(int i=1;i<=M;i++)
		T.update(opArr[i].l,opArr[i].r,opArr[i].val,1,N,1);
	for(int i=1;i<=N;i++)
		print(T.query(i,i,1,N,1)),putchar(' ');
	cout<<endl;
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