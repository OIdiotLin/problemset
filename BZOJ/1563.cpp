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
typedef long double LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (100005)
#define INF (1000000000000000000LL)
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

struct Node{
	int l,r;
	int x;
	Node(int _l=0,int _r=0,int _x=0):
		l(_l),r(_r),x(_x){}
};

int T,N,L,P;
char st[MAXN][40];
LL S[MAXN],f[MAXN];

void init(){
#ifdef Judge
	freopen("1563.in","r",stdin);
	freopen("1563.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&T);
}

inline LL qPow(LL x,int k){
	x=(x<0) ? -x : x;
	LL res = 1;
	while (k) {
		if (k&1)	res = res * x;
		k >>= 1;
		x = x * x;
	}
	return res;
}

inline LL Calc(int j,int i){
	return f[j] + qPow(S[i] - S[j]+ (i - j - 1) - L, P) ;
}

inline int find(Node p,int x){
	int l = p.l, r = p.r;
	while(l <= r) {
		int mid = (l+r)>>1;
		(Calc(p.x, mid) < Calc(x, mid)) ? l = mid+1 : r = mid-1;
	}
	return l;
}

void DP(){
	static Node Q[MAXN+5];
	int head=1,tail=0;
	Q[++tail]=Node(0,N,0);
	for(int i=1;i<=N;i++){
		if(head<=tail && Q[head].r<i)	head++;
		f[i]=Calc(Q[head].x,i);
		if(head>tail || Calc(i,N)<=Calc(Q[tail].x,N)){
			while(head<=tail && Calc(i,Q[tail].l)<=Calc(Q[head].x,Q[tail].l))	tail--;
			if(head>tail)	Q[++tail]=Node(i,N,i);
			else{
				int p=find(Q[tail],i);
				Q[tail].r=p-1;
				Q[++tail]=Node(p,N,i);
			}
		}
	}
}

void work(){
	scanf("%d%d%d",&N,&L,&P);
	for (int i = 1; i <= N; i++) {
		scanf("%s", st[i]);
		S[i] = S[i-1] + strlen(st[i]);
	}
	DP();
	if (f[N] > INF)	puts("Too hard to arrange");
	else printf("%lld\n", (long long)f[N]);
	puts("--------------------");
}

int main(){
	init();
	while(T--)
		work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}