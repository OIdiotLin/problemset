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
#define MAXN (103)
#define INF (1<<30)
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
	int u,v,w;
	Edge(int _u=0,int _v=0,int _w=0):
		u(_u),v(_v),w(_w){}
	bool operator < (const Edge& t)const{
		return w<t.w;
	}
}E[MAXN*MAXN];

int mark[MAXN],fa[MAXN],G[MAXN][MAXN];
int id[MAXN];
int N,K,tot;

inline void Ins(int u,int v,int w){
	E[++tot]=Edge(u,v,w);
}
inline int f(int x){
	return x==fa[x] ? x : fa[x]=f(fa[x]);
}

void init(){
	int cnt=1,x;
#ifdef Judge
	freopen("1982.in","r",stdin);
	freopen("1982.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(K);
	memset(G,127,sizeof(G));
	for(int i=1;i<=K;i++){
		read(x);
		id[x]=cnt;
	}
	for(int i=1;i<=N;i++){
		if(id[i]==1) continue;
		id[i]=++cnt;
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			read(x);
			G[id[i]][id[j]]=min(G[id[i]][id[j]],x);
		}
	for(int i=1;i<=N;i++)
		fa[i]=i;
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++)
			Ins(i,j,G[i][j]);
	sort(E+1,E+tot+1);
}

void work(){
	int Ans=0;
	for(int i=1;i<=tot;i++){
		int x=f(E[i].u),y=f(E[i].v);
		if(x!=y){
			fa[y]=x;
			Ans+=E[i].w;
		}
	}
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