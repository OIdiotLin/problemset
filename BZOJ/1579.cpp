/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
#define Debug
#define MAXN (110000)
#define MAXM (600000)
#define INF (1LL<<53)
const double PI=acos(-1);
const int ZCY=1000000007;
typedef pair<LL,int> Pair;
inline int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputLL(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0){putchar('-');x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputLL(x)
#define read(x) x=getint()

struct Edge{
	int v,next,w;
}E[MAXM];
int N,M,K,tot,S;
int G[MAXN];
LL dist[MAXN],Ans;
bool vis[MAXN];

inline void Ins(int x,int y,int w){
	E[tot]=(Edge){y,G[x],w};
	G[x]=tot++;
}

void init(){
	int x,y,w;
#ifdef Judge
	freopen("1579.in","r",stdin);
	freopen("1579.out","w",stdout);
	SpeedUp;
#endif
	memset(G,-1,sizeof(G));
	read(N),read(M),read(K);
	Ans=INF;
	S=N*(K+1);
	for(int i=1;i<=S;i++) dist[i]=INF;
	for(int i=1;i<=M;i++){
		read(x),read(y),read(w);
		Ins(x,y,w),Ins(y,x,w);
		for(int k=1;k<=K;k++){
			int p=k*N,q=(k-1)*N;
			Ins(x+p,y+p,w);
			Ins(y+p,x+p,w);
			Ins(x+q,y+p,0);
			Ins(y+q,x+p,0);
		}
	}
}
priority_queue<Pair,vector<Pair>,greater<Pair> > Q;
void Dijkstra(){

	Pair k(0,1);
	dist[1]=0;
	Q.push(k);
	while(!Q.empty()){
		int x=Q.top().second;
		Q.pop();
		if(!vis[x]){
			vis[x]=true;
			for(int u=G[x];~u;u=E[u].next){
				int v=E[u].v;
				if(dist[x]+E[u].w<dist[v]){
					dist[v]=dist[x]+E[u].w;
					k.first=dist[v];
					k.second=v;
					Q.push(k);
				}
			}
		}
	}
}
	
void work(){
	Dijkstra();
	for(int i=0;i<=K;i++)
		Ans=min(Ans,dist[N*(i+1)]);
	print(Ans);
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(G)+sizeof(dist)+sizeof(E)+sizeof(vis))/1048576<<" MB."<<endl;
#endif
	return 0;
}