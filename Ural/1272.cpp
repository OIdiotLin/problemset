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
#define MAXN (300001)
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

int N,K,M;
int fa[MAXN];

inline int f(int x){
	return fa[x]==x ? x : fa[x]=f(fa[x]);
}

void init(){
	int u,v;
#ifdef Judge
	freopen("1272.in","r",stdin);
	freopen("1272.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(K),read(M);
	for(int i=1;i<=N;i++)
		fa[i]=i;
	for(int i=1;i<=K;i++){
		read(u),read(v);
		int x=f(u),y=f(v);
		fa[y]=x;
	}
}

void work(){
	int ans=0,u,v;
	for(int i=1;i<=M;i++){
		read(u),read(v);
		int x=f(u),y=f(v);
		if(x!=y)
			fa[y]=x,ans++;
	}
	print(ans);
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