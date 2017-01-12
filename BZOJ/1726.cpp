/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (5005)
#define MAXM (200005)
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
	int u,v,next,w;
}E[MAXM];
int N,M,Ans,tot;
int G[MAXN],dist[MAXN][MAXN];
bool vis[MAXN];

inline void Ins(int x,int y,int w){
	E[++tot]=(Edge){x,y,G[x],w};
	G[x]=tot;
}

void init(){
	int x,y,z;
#ifdef Judge
	freopen("1726.in","r",stdin);
	freopen("1726.out","w",stdout);
	SpeedUp;
#endif
	read(N),read(M);
	for(int i=1;i<=M;i++){
		read(x),read(y),read(z);
		Ins(x,y,z);
		Ins(y,x,z);
	}
}

void SPFA(int T){
	queue<int> Q;
	memset(dist[T],127,sizeof(dist[T]));
	Ans=dist[T][1];
	memset(vis,false,sizeof(vis));
	int s=(T==0 ? 1 : N);
	Q.push(s);
	dist[T][s]=0;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		vis[k]=false;
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(dist[T][k]+E[u].w<dist[T][v]){
				dist[T][v]=dist[T][k]+E[u].w;
				if(!vis[v]){
					vis[v]=true;
					Q.push(v);
				}
			}
		}
	}
}

void work(){
	SPFA(0),SPFA(1);
	for(int u=1;u<=N;u++)
		for(int i=G[u];i;i=E[i].next){
			int t=dist[0][u]+dist[1][E[i].v]+E[i].w;
			if(t!=dist[0][N])
				Ans=min(Ans,t);
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