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
#define MAXN (205)
#define MAXM (600005)
#define INF (1<<29)
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;
const int DirX[]={1,1,2,2};
const int DirY[]={2,-2,1,-1};

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

struct Edge{
	int v,next,flow;
	Edge(int v=0,int n=0,int f=0):
		v(v),next(n),flow(f){}
}E[MAXM];
int dist[MAXN*MAXN*2],G[MAXN*MAXN*2],cur[MAXN*MAXN*2];
int Map[MAXN][MAXN];
int N,Ans,K,S,T;

inline void Ins(int u,int v,int f){
	static int tot=1;
	E[++tot]=Edge(v,G[u],f);	G[u]=tot;
	E[++tot]=Edge(u,G[v],0);	G[v]=tot;
}
inline bool Exceed(int x,int y){
	return x<=0 || y<=0 || x>N || y>N;
}
#define id(x,y)	(((x)-1)*N+(y))
void init(){
#ifdef Judge
	freopen("3175.in","r",stdin);
	freopen("3175.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&N);
	S=0,T=N*N*2+1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%1d",&Map[i][j]);
			fprintf(stderr,"%d",Map[i][j]);
			if(Map[i][j]==0){
				K++;
				Ins(S,N*N+id(i,j),1);
				Ins(N*N+id(i,j),T,1);
			}
		}
		fprintf(stderr,"\n");
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(Map[i][j]==0)
				for(int k=0;k<4;k++){
					int nx=i+DirX[k],ny=j+DirY[k];
					if(Exceed(nx,ny) || Map[nx][ny])	continue;
					Ins(id(i,j),N*N+id(nx,ny),1);
					Ins(id(nx,ny),N*N+id(i,j),1);
				}
}

queue<int> Q;
bool BFS(){
	while(!Q.empty())	Q.pop();
	memset(dist,-1,sizeof(dist));
	Q.push(S);
	dist[S]=0;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
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
	if(x==T)	return f;
	int cnt=f;
	for(int u=cur[x];u;u=E[u].next){
		int v=E[u].v;
		if(E[u].flow && dist[v]==dist[x]+1){
			int w=DFS(v,min(E[u].flow,f));
			E[u].flow-=w;
			E[u^1].flow+=w;
			if(E[u].flow)	cur[x]=u;
			f-=w;
			if(f==0)	return cnt;
		}
	}
	if(f==cnt)	dist[x]=-1;
	return cnt-f;
}
int dinic(){
	int maxflow=0;
	while(BFS()){
		memcpy(cur,G,sizeof(cur));
		maxflow+=DFS(S,INF);
	}
	return maxflow;
}

void work(){
	printf("%d\n",K-dinic());
}

int main(){
	init();
	work();
// #ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(E)+3*sizeof(G)+sizeof(Map))/1048576<<" MB."<<endl;
// #endif
	return 0;
}