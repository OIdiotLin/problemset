/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <queue>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (1005)
#define MAXM (100005)
#define INF (0x7fffffff)
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
	int u,v,next,flow,cost;
	Edge(int _u=0,int _v=0,int _n=0,int _f=0,int _c=0):
		u(_u),v(_v),next(_n),flow(_f),cost(_c){}
}E[MAXM];

int N,M,Ans,tot,S,T;
int Time[62][10];
int dist[MAXN],G[MAXN],pre[MAXN];
bool vis[MAXN];

inline void Ins(int u,int v,int f,int c){
	E[++tot]=Edge(u,v,G[u],f,c);	G[u]=tot;
	E[++tot]=Edge(v,u,G[v],0,-c);	G[v]=tot;
}

#define id(i,j) (((((i)-1))*M)+(j)))
void init(){
#ifdef Judge
	freopen("1070.in","r",stdin);
	freopen("1070.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	tot=1,S=0,T=N*M+M+2;
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)
			read(Time[i][j]);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			for(int k=1;k<=M;k++)
				Ins(M*i-M+j,N*M+k,1,Time[k][i]*j);
	for(int i=1;i<=M*N;i++)
		Ins(S,i,1,0);
	for(int i=N*M+1;i<=N*M+M;i++)
		Ins(i,T,1,0);
}

queue<int> Q;
bool SPFA(){
	while(!Q.empty()) Q.pop();
	for(int i=S;i<=T;i++) dist[i]=INF;
	vis[S]=true;
	dist[S]=0;
	Q.push(S);
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(E[u].flow && dist[v]>dist[k]+E[u].cost){
				dist[v]=dist[k]+E[u].cost;
				pre[v]=u;
				if(!vis[v]){
					vis[v]=true;
					Q.push(v);
				}
			}
		}
		vis[k]=false;
	}
	return dist[T]!=INF;
}

void mCF(){
	int w=INF;
	for(int u=pre[T];u;u=pre[E[u].u])
		w=min(w,E[u].flow);
	for(int u=pre[T];u;u=pre[E[u].u]){
		E[u].flow-=w;
		E[u^1].flow+=w;
		Ans+=E[u].cost*w;
	}
}

void minCmaxF(){
	while(SPFA()) mCF();
}

void work(){
	minCmaxF();
	cout<<fixed<<setprecision(2)<<(double)Ans/M<<endl;
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