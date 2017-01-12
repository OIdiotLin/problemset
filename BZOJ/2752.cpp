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
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct SegTree{
private:
	/* s1: 费用和 s2: （下标*费用）的和 s3: (下标^2*费用)的和 */
	struct SegNode{
		int l,r;
		LL s1,s2,s3;
		LL add;
		SegNode(){l=r=-1,s1=s2=s3=add=0;}
	}s[MAXN<<2];
	
#define lc(id) s[id<<1]
#define rc(id) s[id<<1|1]

	inline void Down(int id,int l,int r){
		if(s[id].add){
			LL t=s[id].add;
			s[id].add=0;
			s[id].s1+=(r-l+1)*t;
			s[id].s2+=(So[r-l+1])*t;
			s[id].s3+=(Sp[r-l+1])*t;
			if(l==r) return;
			lc(id).add+=t;
			rc(id).add+=t;
		}
	}
	inline void maintain(int L,int R,int l,int r,int id,LL v){
		Down(id,L,R);
		if(L>=l && R<=r){
			s[id].add+=v;
			return;
		}
		int mid=(L+R)>>1;
		if(l<=mid) maintain(L,mid,l,r,id<<1,v);
		if(r>=mid) maintain(mid+1,R,l,r,id<<1|1,v);
		Down(id<<1,L,mid);
		Down(id<<1|1,mid+1,R);
		s[id].s1=lc(id).s1+rc(id).s1;
		s[id].s2=lc(id).s2+rc(id).s2;
		s[id].s3=lc(id).s3+rc(id).s3;
	}
	inline LL query(int L,int R,int l,int r,int id){
		Down(id,L,R);
		if(L>=l && R<=r){
			print
void init(){
#ifdef Judge
	freopen("2752.in","r",stdin);
	freopen("2752.out","w",stdout);
//	SpeedUp;
#endif
	
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