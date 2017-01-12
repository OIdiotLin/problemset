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
#define MAXN (100005)
#define MAXM (500005)
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
inline void outputint(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Edge{
	int v,next,w;
	Edge(int _v=0,int _n=0,int _w=0):
		v(_v),next(_n),w(_w){}
}E[MAXM];

int N,M,tot;
bool vis[MAXN];
int G[MAXN],dist[MAXN],loop[MAXN];

inline void Ins(int u,int v,int w){
	E[++tot]=Edge(v,G[u],w);	G[u]=tot;
}

void init(){
	int x,u,v;
#ifdef Judge
	freopen("2330.in","r",stdin);
	freopen("2330.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	/*
	for(int i=1;i<=N;i++)
		Ins(0,i,1);
	*/
	for(int i=1;i<=M;i++){
		read(x),read(u),read(v);
		switch(x){
			case 1:	Ins(u,v,0),Ins(v,u,0);
					break;
			case 2:	if(u==v){puts("-1");exit(0);}Ins(u,v,1);
					break;
			case 3:	Ins(v,u,0);
					break;
			case 4:	if(u==v){puts("-1");exit(0);}Ins(v,u,1);
					break;
			case 5:	Ins(u,v,0);
					break;
			default:puts("Error");
					exit(0);
		}
	}
	for(int i=N;i;i--)
		Ins(0,i,1);
}

#define S (0)
queue<int> Q;
bool SPFA(){
	while(!Q.empty()) Q.pop();
	Q.push(S);
	vis[S]=true;
	loop[S]=1;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(dist[v]<dist[k]+E[u].w){
				dist[v]=dist[k]+E[u].w;
				if(++loop[v]>=N) return false;
				if(!vis[v]){
					vis[v]=true;
					Q.push(v);
				}
			}
		}
		vis[k]=false;
	}
	return true;
}

void work(){
	LL Ans=0;
	if(SPFA()==false){
		puts("-1");
		return;
	}
	for(int i=1;i<=N;i++)
		Ans+=dist[i];
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