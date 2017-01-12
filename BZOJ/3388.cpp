/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
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
#define MAXN (505)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

const int DirX[]={0,1,0,-1};
const int DirY[]={1,0,-1,0};

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

// struct Edge{
	// int v,next;
	// Edge(int _v=0,int _next=0):
		// v(_v),next(_next){}
// }E[MAXN*MAXN<<2];

int N,M;
int h[MAXN][MAXN];
int /*G[MAXN*MAXN],*/in[MAXN*MAXN],out[MAXN*MAXN];
int scc[MAXN][MAXN],scctot;

// inline void Ins(int u,int v){
	// static int tot=0;
	// E[++tot]=Edge(v,G[u]);	G[u]=tot;
// }

inline bool Exceed(int x,int y){
	return x<1 || y<1 || x>N || y>M;
}

void DFS(int x,int y){
	if(scc[x][y])	return;
	scc[x][y]=scctot;
	for(int k=0;k<4;k++){
		int nx=x+DirX[k],ny=y+DirY[k];
		if(!Exceed(nx,ny) && h[x][y]==h[nx][ny])
			DFS(nx,ny);
	}
}

void init(){
#ifdef Judge
	freopen("3388.in","r",stdin);
	freopen("3388.out","w",stdout);
//	SpeedUp;
#endif
	read(M),read(N);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			read(h[i][j]);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			if(!scc[i][j])
				scctot++,DFS(i,j);
}

void work(){
	int ans1=0,ans2=0;
	if(scctot==1){
		puts("0");
		return;
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			for(int k=0;k<2;k++){
				int nx=i+DirX[k],ny=j+DirY[k];
				if(!Exceed(nx,ny) && h[i][j]!=h[nx][ny]){
					if(h[i][j]>h[nx][ny]){
						in[scc[nx][ny]]=out[scc[i][j]]=1;
					}else{
						in[scc[i][j]]=out[scc[nx][ny]]=1;
					}
				}
			}
	for(int i=1;i<=scctot;i++){
		if(in[i]==0)	ans1++;
		if(out[i]==0)	ans2++;
	}
	print(max(ans1,ans2));
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