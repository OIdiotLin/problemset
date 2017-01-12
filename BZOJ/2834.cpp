/*
	Machine: Class4_B2
	System: Ubuntu_Kylin 14.10
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
#define MAXN (2000005)
#define MAXM (6000005)
#define INF (2139062143)
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

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
#define sqr(x)	((x)*(x))

struct Data{
	int x,y,id;
	Data(){}
	Data(int _x,int _y,int _d):
		x(_x),y(_y),id(_d){}
}A[MAXN];
inline bool cmpxy(const Data &u,const Data &v){
	return u.x==v.x ? u.y<v.y : u.x<v.x;
}
inline bool cmpyx(const Data &u,const Data &v){
	return u.y==v.y ? u.x<v.x : u.y<v.y;
}

struct Edge{
	int v,next,w;
	Edge(){}
	Edge(int _v,int _n,int _w):
		v(_v),next(_n),w(_w){}
}E[MAXM];

int G[MAXN],dist[MAXN];
bool vis[MAXN];
int N,M,S,T;

inline void Ins(int u,int v,int w){
	static int tot=0;
	E[++tot]=Edge(v,G[u],w);	G[u]=tot;
	E[++tot]=Edge(u,G[v],w);	G[v]=tot;
}

void init(){
#ifdef Judge
	freopen("2834.in","r",stdin);
	freopen("2834.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	S=M+1,T=M+2;
	for(int i=1;i<=M+2;i++)
		read(A[i].x),read(A[i].y),A[i].id=i;
	sort(A+1,A+M+3,cmpxy);
	for(int i=1;i<=M+1;i++)
		if(A[i].x==A[i+1].x)
			Ins(A[i].id,A[i+1].id,(A[i+1].y-A[i].y)<<1);
	sort(A+1,A+M+3,cmpyx);
	for(int i=1;i<M+2;i++)
		if(A[i].y==A[i+1].y)
			Ins(A[i].id+T,A[i+1].id+T,(A[i+1].x-A[i].x)<<1);
	for(int i=1;i<=M;i++)
		Ins(i,i+T,1);
	Ins(S,S+T,0);
	Ins(T,T+T,0);
}

void SPFA(){
	static queue<int> Q;
	while(!Q.empty())	Q.pop();
	memset(dist,127,sizeof(dist));
	dist[S]=0;
	Q.push(S);
	vis[S]=true;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(dist[v]>dist[k]+E[u].w){
				dist[v]=dist[k]+E[u].w;
				if(!vis[v]){
					Q.push(v);
					vis[v]=true;
				}
			}
		}
		vis[k]=false;
	}
}

void work(){
	SPFA();
	print(dist[T]==INF ? -1 : dist[T]);
}

int main(){
	init();
	work();
//#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(E)+sizeof(G)*3)/1048576<<" MB."<<endl;
//#endif
	return 0;
}
