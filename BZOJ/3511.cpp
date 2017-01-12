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
#define MAXN (10005)
#define MAXM (2000005)
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
	int v,next,flow;
	Edge(int _v=0,int _next=0,int _flow=0):v(_v),next(_next),flow(_flow){}
}E[MAXM];
int G[MAXN<<3],dist[MAXN<<3],cur[MAXN<<3];
int A[MAXN],B[MAXN];
int N,M,tot,id,S,T;
LL Ans;

inline void Ins(int u,int v,int f){
	E[++tot]=Edge(v,G[u],f);	G[u]=tot;
	E[++tot]=Edge(u,G[v],0);	G[v]=tot;
}

void init(){
	int x,y,a,b,c;
#ifdef Judge
	freopen("3511.in","r",stdin);
	freopen("3511.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	S=1,T=N,tot=1;
	for(int i=S+1;i<T;i++) read(A[i]);
	for(int i=S+1;i<T;i++) read(B[i]);
	while(M--){
		read(x),read(y),read(a),read(b),read(c);
		if(x>y) swap(x,y);
		if(x==1 && y==N) Ans-=c;
		if(x==1 && y!=N) A[y]+=a,B[y]-=c;
		if(x!=1 && y==N) A[x]-=c,B[x]+=b;
		if(x!=1 && y!=N){
			Ans+=a+b;
			Ins(S,++id,a);	Ins(id,x,INF);	Ins(id,y,INF);
			Ins(++id,T,b);	Ins(x,id,INF);	Ins(y,id,INF);
			Ins(x,y,c);	Ins(y,x,c);
		}
	}
	for(int i=S+1;i<T;i++){
		if(A[i]>0)	Ans+=A[i],Ins(S,i,A[i]);
		else Ins(i,T,-A[i]);
		if(B[i]>0)	Ans+=B[i],Ins(i,T,B[i]);
		else Ins(S,i,-B[i]);
	}
}

queue<int> Q;
bool BFS(){
	while(!Q.empty()) Q.pop();
	memset(dist,-1,sizeof(dist));
	dist[S]=0;
	Q.push(S);
	while(!Q.empty()){
		int k=Q.front();
		cur[k]=G[k];
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
	if(x==T) return f;
	int cnt=f;
	for(int &u=cur[x];u;u=E[u].next){
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
