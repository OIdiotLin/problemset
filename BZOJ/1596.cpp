/*
	Machine: Class4_B2
	System: Ubuntu_Kylin 14.10
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (10005)
#define INF (1<<28)
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;
inline int min(int x,int y,int z){
	return min(x,min(y,z));
}
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
#define sqr(x)	((x)*(x))

struct Edge{
	int v,next;
	Edge(){}
	Edge(int _v,int _n):
		v(_v),next(_n){}
}E[MAXN<<1];

int f[3][MAXN],G[MAXN];
int N;

inline void Ins(int u,int v){
	static int tot=0;
	E[++tot]=Edge(v,G[u]);	G[u]=tot;
	E[++tot]=Edge(u,G[v]);	G[v]=tot;
}

void init(){
#ifdef Judge
	freopen("1596.in","r",stdin);
	freopen("1596.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<N;i++)
		Ins(getint(),getint());
}

void dp(int x,int fa){
	int res=0;
	f[1][x]=1,f[0][x]=INF;
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(fa==v)	continue;
		dp(v,x);
		f[1][x]+=min(f[0][v],f[1][v],f[2][v]);
		f[2][x]+=f[0][v];
		res+=min(f[0][v],f[1][v]);
	}
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(fa==v)	continue;
		f[0][x]=min(f[0][x],f[1][v]-min(f[0][v],f[1][v])+res);
	}
}

void work(){
	dp(1,0);
	print(min(f[1][1],f[0][1]));
}

int main(){
	init();
	work();
#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
