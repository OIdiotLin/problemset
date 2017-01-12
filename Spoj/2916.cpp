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
#define maxN (10005)
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
		SegNode(int v=-INF):
			val(v),pre(v),suf(v){sum=0;}
	}node[maxN<<2];
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
	void Init(int n){
		size=n;
		Build(1,size,1);
	}
	
	int Ask(int l1,int r1,int l2,int r2){
		/*	|_______________|
								|_______________|	*/
		if(r1<l2)
			return Query(l1,r1-1,1,size,1).suf+Query(r1,l2-1,1,size,1).sum+Query(l2,r2,1,size,1).pre;
		
		/*	|_______________|	
							|_______________|		*/
		if(r1==l2){
			int Lsuf=Query(l1,r1-1,1,size,1).suf,Rpre=Query(l2,r2,1,size,1).pre;
			return max(Lsuf+Rpre,Query(l1,r1,1,size,1).suf,Rpre);
		}
		
		/*	|_______________|
							 |______________|		*/
		if(r1+1==l2)
			return Query(l1,r1,1,size,1).suf+Query(l2,r2,1,size,1).pre;
		
		/*	|_______________|
						|____________________|		*/
						
		/*	|____________________|
					|________|						*/
		int res=Query(l2,r1,1,size,1).val;
		res=max(res,Query(r1,r2,1,size,1).pre+Query(l1,l2,1,size,1).suf+Query(l2+1,r1-1,1,size,1).sum);
		int Lsuf=Query(l1,l2,1,size,1).suf;
		int Rpre=Query(r1,r2,1,size,1).pre;
		if(r1>=l2)
			res=max(res,Lsuf);
		res=max(res,Lsuf+Query(l2+1,r2,1,size,1).pre);
		if(l2<=r1)
			res=max(res,Rpre);
		res=max(res,Rpre+Query(l1,r1-1,1,size,1).suf);
		return res;
		
		// int ans,t1,t2;
		// if(r1<=l2){
			// ans=0;
			// t1=t2=-INF;
			// if(r1+1<=l2-1)	ans+=Query(r1+1,l2-1,1,size,1).sum;
			// if(r1==l2){
				// t1=Query(l2,r2,1,size,1).pre;
				// ans+=t1;
				// if(l1<=r1-1){
					// t2=Query(l1,r1-1,1,size,1).suf;
					// ans+=t2;
				// }
				// ans=max(ans,t1);
				// t2=Query(l1,r1,1,size,1).suf;
				// ans=max(ans,t2);
			// }else	ans+=Query(l2,r2,1,size,1).pre+Query(l1,r1,1,size,1).suf;
			// return ans;
		// }
		// ans=Query(l2,r1,1,size,1).val;
		// t1=Query(r1,r2,1,size,1).pre+Query(l1,l2,1,size,1).suf;
		// if(l2+1<=r1-1)	t1+=Query(l1+1,r1-1,1,size,1).sum;
		// ans=max(ans,t1);
		// t1=Query(l1,l2,1,size,1).suf;
		// if(r1>=l2)	ans=max(ans,t1);
		// if(l2<r2)	t1+=Query(l2+1,r2,1,size,1).pre;
		// ans=max(ans,t1);
		// t1=Query(r1,r2,1,size,1).pre;
		// if(l2<=r1)	ans=max(ans,t1);
		// if(l1<r1)	t1+=Query(l1,r1-1,1,size,1).suf;
		// ans=max(ans,t1);
		// return ans;
	}
}ST;

int T,N;

void init(){
#ifdef Judge
	freopen("2916.in","r",stdin);
	freopen("2916.out","w",stdout);
//	SpeedUp;
#endif
	read(T);
}

void work(){
	int Q,l1,l2,r1,r2;
	ST.Init(N);
	read(Q);
	while(Q--){
		read(l1),read(r1),read(l2),read(r2);
		print(ST.Ask(l1,r1,l2,r2));
	}
}

int main(){
	init();
	while(scanf("%d",&N)!=EOF)
		work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}