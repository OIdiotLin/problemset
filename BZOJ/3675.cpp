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
inline void outputint(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()
#define sqr(x)	((x)*(x))
int N,M,k;
LL f[2][MAXN],g[2][MAXN],S[MAXN];

void init(){
	int x;
#ifdef Judge
	freopen("3675.in","r",stdin);
	freopen("3675.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	k=0;
	for(int i=1;i<=N;i++){
		read(x);
		S[i]=x+S[i-1];
	}
	for(int i=1;i<=N;i++)
		g[k][i]=sqr(S[i]);
}

void DP(){
	static int Q[MAXN];
	for(int j=1;j<=M;j++){
		k^=1;
		int head=0,tail=0;
		Q[head]=0;
		for(int i=1;i<=N;i++){
			while( head<tail && S[i]*(S[Q[head+1]]-S[Q[head]]) >= g[k^1][Q[head+1]]-g[k^1][Q[head]] )	head++;
			f[k][i]=f[k^1][Q[head]]+S[i]*S[Q[head]]-sqr(S[Q[head]]);
			g[k][i]=sqr(S[i])-f[k][i];
			while( head<tail && (g[k^1][Q[tail]]-g[k^1][Q[tail-1]]) * (S[i]-S[Q[tail]]) >= (g[k^1][i]-g[k^1][Q[tail]]) * (S[Q[tail]]-S[Q[tail-1]]) )	tail--;
			Q[++tail]=i;
		}
	}
}

void work(){
	DP();
	print(f[k][N]);
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