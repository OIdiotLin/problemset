/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (60002)
#define MAXM (300002)
#define INF (0x7fffffff)
const double PI=acos(-1);
const int ZCY=1000000007;
const int DirX[]={1,0,-1,0};
const int DirY[]={0,1,0,-1};

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
	int v,next,flow;
	Edge(int _v=0,int _n=-1,int _f=0):v(_v),next(_n),flow(_f){}
}E[MAXM];

int N,M,R,lim_D,tot,Ans,S,T;
int id[43][43][43];
int G[MAXN],dist[MAXN],cur[MAXN];

inline void Ins(int u,int v,int f){
	E[++tot]=Edge(v,G[u],f);	G[u]=tot;
	E[++tot]=Edge(u,G[v],0);	G[v]=tot;
}
#define Set(h,i,j) id[h][i][j]=++idx
#define InRange(x,y) (x&&x<=N&&y&&y<=M)
void init(){
	int idx=1,v;
	tot=-1;
#ifdef Judge
	freopen("3144.in","r",stdin);
	freopen("3144.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M),read(R),read(lim_D);
	memset(G,-1,sizeof(G));
	for(int h=1;h<=R+1;h++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				Set(h,i,j);
	S=1,T=id[R+1][N][M]+1;
	for(int h=1;h<=R;h++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++){
				read(v);
				Ins(id[h][i][j],id[h+1][i][j],v);
			}
	for(int h=lim_D+1;h<=R+1;h++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				for(int k=0;k<4;k++){
					int nx=i+DirX[k],ny=j+DirY[k];
					if(InRange(nx,ny))
						Ins(id[h][i][j],id[h-lim_D][nx][ny],INF);
				}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			Ins(S,id[1][i][j],INF);
			Ins(id[R+1][i][j],T,INF);
		}
}

queue<int> Q;
bool BFS(){
	while(!Q.empty()) Q.pop();
	memset(dist,-1,sizeof(dist));
	for(int i=S;i<=T;i++) cur[i]=G[i];
	dist[S]=0;
	Q.push(S);
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u!=-1;u=E[u].next){
			int v=E[u].v;
			if(E[u].flow && dist[v]==-1){
				dist[v]=dist[k]+1;
				Q.push(v);
			}
		}
	}
	return dist[T]!=-1;
}

int DFS(int x,int f){
	if(x==T) return f;
	int cnt=f;
	for(int &u=cur[x];u!=-1;u=E[u].next){
		int v=E[u].v;
		if(E[u].flow && dist[v]==dist[x]+1){
			int w=DFS(v,min(f,E[u].flow));
			E[u].flow-=w;
			E[u^1].flow+=w;
			f-=w;
			if(f==0) return cnt;
		}
	}
	return cnt-f;
}

void dinic(){
	while(BFS()) Ans+=DFS(S,INF);
}

void work(){
	dinic();
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
