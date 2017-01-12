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
#include <queue>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (1005)
#define MAXM (2000005)
#define INF (1LL<<51)
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputll(int x){
	char ch[18];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputll(x)
#define read(x) x=getint()

struct Edge{
	int v,next;
	LL flow;
	Edge(int _v=0,int _next=0,LL _flow=0):v(_v),next(_next),flow(_flow){}
}E[MAXM];

LL Pro[MAXN][MAXN],A[MAXN],s[MAXN];
LL Ans;
int N,tot,S,T;
int G[MAXN],dist[MAXN];

inline void Ins(int x,int y,LL f){
	++tot;
	E[tot<<1]=Edge(y,G[x],f);	G[x]=tot<<1;
	E[tot<<1^1]=Edge(x,G[y],0);	G[y]=tot<<1^1;
}

void init(){
#ifdef Judge
	freopen("2039.in","r",stdin);
	freopen("2039.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	S=0,T=N+1;
	for(int i=1;i<=N;i++){
		read(A[i]);
		Ins(i,T,A[i]);
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			read(Pro[i][j]);
			s[i]+=Pro[i][j];
			Ans+=Pro[i][j];
			if(Pro[i][j])
				Ins(i,j,Pro[i][j]<<1);
		}
	for(int i=1;i<=N;i++)
		Ins(S,i,s[i]);
}

queue<int> Q;
bool BFS(){
	while(!Q.empty()) Q.pop();
//	memset(dist,0x7fffffff,sizeof(dist));
	for(int i=0;i<=T;i++)
		dist[i]=0x7fffffff;
	dist[S]=0;
	Q.push(S);
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(E[u].flow && dist[v]>dist[k]+1){
				dist[v]=dist[k]+1;
				Q.push(v);
			}
		}
	}
	return dist[T]!=0x7fffffff;
}

LL DFS(int x,LL f){
	if(x==T) return f;
	LL cnt=f;
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(E[u].flow && dist[v]==dist[x]+1){
			LL w=DFS(v,min(cnt,E[u].flow));
			E[u].flow-=w;
			E[u^1].flow+=w;
			cnt-=w;
		}
	}
	return f-cnt;
}

void dinic(){
	while(BFS()) Ans-=DFS(S,INF);
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