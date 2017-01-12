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
#include<ext/pb_ds/priority_queue.hpp>
#include <algorithm>
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
typedef __gnu_pbds::priority_queue<pair<LL,int>,greater<pair<LL,int> >,pairing_heap_tag> Heap;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (1000005)
#define MAXM (10000005)
#define MAX (100000000)
#define INF (900000000000000000LL)
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
inline void outputint(LL x){
	char ch[20];
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
	int v,next,w;
	Edge(){}
	Edge(int v,int n,int w):
		v(v),next(n),w(w){}
}E[MAXM];

int G[MAXN];
Heap::point_iterator d[MAXN];
LL dist[MAXN];
int N,M;
int T,r1,r2,r3,r4,r5;

inline pair<int,int> Decode(){
	static int x=0,y=0;
	pair<int,int> res;
	x=((LL)x*r1+r2)%r5;
	y=((LL)y*r3+r4)%r5;
	res=make_pair(min(x%N+1,y%N+1),max(x%N+1,y%N+1));
	return res;
}

inline void Ins(int u,int v,int w){
	static int tot=0;
	E[++tot]=Edge(v,G[u],w);	G[u]=tot;
}

void init(){
	int u,v,w;
#ifdef Judge
	freopen("3040.in","r",stdin);
	freopen("3040.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M),read(T),read(r1),read(r2),read(r3),read(r4),read(r5);
	for(int i=1;i<=N;i++)
		dist[i]=INF;
	for(int i=1;i<=T;i++){
		pair<int,int> t=Decode();
		Ins(t.first,t.second,MAX-100*t.first);
	}
	for(int i=1;i<=M-T;i++){
		read(u),read(v),read(w);
		Ins(u,v,w);
	}
}

LL Dijkstra(int S,int T){
	static Heap Q;
	dist[S]=0;
	d[S]=Q.push(make_pair(dist[S],S));
	while(!Q.empty()){
		int k=Q.top().second;
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(dist[v]>dist[k]+E[u].w){
				dist[v]=dist[k]+E[u].w;
				if(d[v]!=NULL)
					Q.modify(d[v],make_pair(dist[v],v));
				else
					d[v]=Q.push(make_pair(dist[v],v));
			}
		}
	}
	return dist[T];
}

void work(){
	print(Dijkstra(1,N));
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