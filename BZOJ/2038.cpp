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

#define min(x,y) ((x)>(y)?(y):(x))

LL gcd(LL x,LL y){
	if(!x)	return y;
	if(!y)	return x;
	if(!(x&1)&&!(y&1))	return gcd(x>>1,y>>1)<<1;
	if(!(y&1))	return gcd(x,y>>1);
	if(!(x&1))	return gcd(x>>1,y);
	return gcd(abs(x-y),min(x,y));
}

struct Query_Seg{
	int l,r,pos,origin;
	LL Ans;
	Query_Seg(int _l=0,int _r=0,int _p=0,int _o=0):l(_l),r(_r),pos(_p),origin(_o){}
	bool operator < (const Query_Seg&t)const{
		return pos<t.pos || (pos==t.pos && r<t.r);
	}
	LL num(){
		return Ans-(r-l+1);
	}
	LL deno(){
		return (LL)(r-l+1)*(r-l);
	}
}Ask[MAXN];
inline bool init_pos(Query_Seg x,Query_Seg y){
	return x.origin<y.origin;
}

int N,M,blk_sz;
int C[MAXN],cnt[MAXN];

void init(){
	int l,r;
#ifdef Judge
	freopen("2038.in","r",stdin);
	freopen("2038.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	blk_sz=(int)sqrt(N+0.5);
	for(int i=1;i<=N;i++)
		read(C[i]);
	for(int i=1;i<=M;i++){
		read(l),read(r);
		Ask[i]=Query_Seg(l,r,i/blk_sz+1,i);
	}
	sort(Ask+1,Ask+M+1);
}

LL Ans=0;

inline void Modify(int val,int t){
	Ans+=(((cnt[val]=cnt[val]+t)<<1)-t)*t;
}

void work(){
	int l=1,r=0;
	for(int i=1;i<=M;i++){
		while(r<Ask[i].r)	Modify(C[++r],1);
		while(r>Ask[i].r)	Modify(C[r--],-1);
		while(l<Ask[i].l)	Modify(C[l++],-1);
		while(l>Ask[i].l)	Modify(C[--l],1);
		Ask[i].Ans=Ans;
	}
	sort(Ask+1,Ask+M+1,init_pos);
	for(int i=1;i<=M;i++){
		LL a=Ask[i].num(),b=Ask[i].deno();
		LL t=gcd(a,b);
		printf("%lld/%lld\n",a/t,b/t);
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