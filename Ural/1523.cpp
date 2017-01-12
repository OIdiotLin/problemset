/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <vector>
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
#define MAXN (300001)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000000;

inline int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputint(LL x){
	char ch[19];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

LL f[2][MAXN],g[2][MAXN],k;
int N,K,Ans;
LL A[MAXN];

inline int lowbit(int x){return x&(-x);}
inline void Change(int x,LL v){
	while(x){
		f[k][x]=(f[k][x]+v)%ZCY;
		x-=lowbit(x);
	}
}
inline LL Ask(int x){
	int ret=0;
	while(x<=N){
		ret=(f[k][x]+ret)%ZCY;
		x+=lowbit(x);
	}
	return ret;
}

void init(){
#ifdef Judge
	freopen("1523.in","r",stdin);
	freopen("1523.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(K);
	for(int i=1;i<=N;i++) cin>>A[i],g[1][i]=1;
}

void work(){
	for(int i=2;i<=K;i++){
		memset(f[k],0,sizeof(f[k]));
		for(int j=i-1;j<=N;j++){
			Change(A[j]-1,g[k^1][j]);
			g[k][j]=Ask(A[j]);
		}
		k^=1;
	}
	for(int i=K;i<=N;i++) 
		Ans=(Ans+g[k^1][i])%ZCY;
	print(Ans);
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
