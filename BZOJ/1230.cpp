/*
	System: Windows7 32bit
	Machine: Class4_B2
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (100005)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

struct SegTree{
	struct SegNode{
		int cover,sum;
	}s[MAXN<<2];
	inline void Up(int t){
		s[t].sum=s[t<<1].sum+s[t<<1|1].sum;
	}
	inline void Down(int t,int l,int r){
		if(s[t].cover==0) return;
		s[t<<1].cover^=1;
		s[t<<1|1].cover^=1;
		int mid=(l+r)>>1;
		s[t<<1].sum=mid+1-l-s[t<<1].sum;
		s[t<<1|1].sum=r-mid-s[t<<1|1].sum;
		s[t].cover=0;
	}
	inline void Update(int L,int R,int l,int r,int t){
		if(L<=l && R>=r){
			s[t].cover^=1;
			s[t].sum=r-l+1-s[t].sum;
			return;
		}
		Down(t,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,t<<1);
		if(R>mid) Update(L,R,mid+1,r,t<<1|1);
		Up(t);
	}
	inline int Query(int L,int R,int l,int r,int t){
		if(L<=l && R>=r) return s[t].sum;
		Down(t,l,r);
		int mid=(l+r)>>1,ret=0;
		if(L<=mid) ret+=Query(L,R,l,mid,t<<1);
		if(R>mid) ret+=Query(L,R,mid+1,r,t<<1|1);
		return ret;
	}
}ST;
int N,M;

void init(){
	#ifdef Judge
	SpeedUp;
	freopen("1230.in","r",stdin);
	freopen("1230.out","w",stdout);
	#endif
	cin>>N>>M;
}

void work(){
	int CMD,s,t;
	for(int i=1;i<=M;i++){
		cin>>CMD>>s>>t;
		switch(CMD){
			case 0 :ST.Update(s,t,1,N,1);
					break;
			case 1 :cout<<ST.Query(s,t,1,N,1)<<endl;
					break;
			default:cout<<"Error"<<endl;
		}
	}
}

int main(){
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

