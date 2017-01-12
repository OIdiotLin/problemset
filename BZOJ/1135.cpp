#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define MAXN (200002)

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define read(x) x=getint()

struct SegTree{
	struct SegNode{
		LL Max,Sum,Maxl,Maxr;
	}s[MAXN<<2];
	
	inline void Update(int t,int l,int r,int x,int v){
		if(l==r){
			s[t].Max+=v;
			s[t].Sum+=v;
			s[t].Maxl+=v;
			s[t].Maxr+=v;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid) Update(t<<1,l,mid,x,v);
		if(x>mid) Update(t<<1|1,mid+1,r,x,v);
		s[t].Sum=s[t<<1].Sum+s[t<<1|1].Sum;
		s[t].Maxl=max(s[t<<1].Maxl,s[t<<1].Sum+s[t<<1|1].Maxl);
		s[t].Maxr=max(s[t<<1|1].Maxr,s[t<<1|1].Sum+s[t<<1].Maxr);
		s[t].Max=max(s[t<<1].Maxr+s[t<<1|1].Maxl,max(s[t<<1].Max,s[t<<1|1].Max));
	}
	
	inline int Ans(){
		return s[1].Max;
	}
}ST;
int N,M,D,K;

int main(){
	int r,x;
	read(N);
	read(M);
	read(K);
	read(D);
	for(int i=1;i<=N;i++) 
		ST.Update(1,1,N,i,-K);
	for(int i=1;i<=M;i++){
		read(r);
		read(x);
		ST.Update(1,1,N,r,x);
		cout<<(ST.Ans()<=(LL)D*K ? "TAK" : "NIE")<<endl;
	}
	return 0;
}
