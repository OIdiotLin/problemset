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
#define MAXM (525)
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

struct Edge{
	int v,next;
	Edge(int _v=0,int _n=0):
		v(_v),next(_n){}
}E[MAXN];

int depth[MAXN],G[MAXN];
int N,H,tot;

struct Matrix{
	int a[MAXN][MAXM];
	int card[MAXM];
}A;


inline void Ins(int u,int v){
	E[++tot]=Edge(v,G[u]);	G[u]=tot;
}

void init(){
#ifdef Judge
	freopen("3696.in","r",stdin);
	freopen("3696.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<N;i++)
		Ins(getint(),i+1);
}

void DFS(int x){
	A.a[x][0]=1;
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		DFS(v);
		for(int i=0;i<=depth[x];i++)
			for(int j=0;j<=depth[v];j++)
				A.card[i^(j+1)]+=A.a[x][i]*A.a[v][j];
		depth[x]=max(depth[x],depth[v]+1);
		for(int i=0;i<=depth[v];i++)
			A.a[x][i+1]+=A.a[v][i];
	}
}

void work(){
	DFS(1);
	int lim;
	for(lim=MAXM-1;A.card[lim]==0;lim--);
	for(int i=0;i<=lim;i++)
		print(A.card[i]);
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