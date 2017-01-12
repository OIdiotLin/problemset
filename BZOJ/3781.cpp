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
inline void outputint(LL x){
	char ch[18];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Query_Seg{
	int l,r,pos,origin;
	Query_Seg(int _l=0,int _r=0,int _p=0,int _o=0):
		l(_l),r(_r),pos(_p),origin(_o){}
		
	bool operator < (const Query_Seg & t)const{
		return pos<t.pos || (pos==t.pos && r<t.r);
	}
}Ask[MAXN];

int N,M,K,blk_sz;
int A[MAXN];
LL C[MAXN],Ans[MAXN];
LL tAns;

void init(){
	int l,r;
#ifdef Judge
	freopen("3781.in","r",stdin);
	freopen("3781.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M),read(K);
	blk_sz=sqrt(N);
	for(int i=1;i<=N;i++)
		read(A[i]);
	for(int i=1;i<=M;i++){
		read(l),read(r);
		Ask[i]=Query_Seg(l,r,(l-1)/blk_sz+1,i);
	}
	sort(Ask+1,Ask+M+1);
}

inline void Modify(int val,int t){	
	tAns+=(((C[val]=C[val]+t)<<1)-t)*t;
}

void work(){
	int l=1,r=0;tAns=0;
	for(int i=1;i<=M;i++){
		while(r<Ask[i].r)	Modify(A[++r],1);
		while(r>Ask[i].r)	Modify(A[r--],-1);
		while(l<Ask[i].l)	Modify(A[l++],-1);
		while(l>Ask[i].l)	Modify(A[--l],1);
		Ans[Ask[i].origin]=tAns;
	}
	for(int i=1;i<=M;i++)
		print(Ans[i]);
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(Ask)+sizeof(Ans)+sizeof(C)+sizeof(A))/1048576<<" MB."<<endl;
#endif
	return 0;
}