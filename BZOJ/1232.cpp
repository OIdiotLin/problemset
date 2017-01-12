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
#define INF (1<<28)
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
	bool operator < (const Edge &b) const{
		return w<b.w;
	}
}E[MAXN];
int fa[MAXN],C[MAXN];
int N,M,Sum,Min;

inline int f(int x){
	return fa[x]==x ? x : fa[x]=f(fa[x]);
}

void init(){
	int x,y,w;
#ifdef Judge
	freopen("1232.in","r",stdin);
	freopen("1232.out","w",stdout);
	SpeedUp;
#endif
	Min=INF,Sum=0;
	read(N),read(M);
	for(int i=1;i<=N;i++){
		read(C[i]);
		Min=min(Min,C[i]);
		fa[i]=i;
	}
	for(int i=1;i<=M;i++){
		read(x),read(y),read(w);
		E[i]=(Edge){x,y,(w<<1)+C[x]+C[y]};
	}
}

void Kruskal(){
	sort(E+1,E+M+1);
	for(int i=1;i<=M;i++){
		int fx=f(E[i].u),fy=f(E[i].v);
		if(fx!=fy){
			Sum+=E[i].w;
			fa[fx]=fy;
		}
	}
}

void work(){
	Kruskal();
	print(Min+Sum);
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