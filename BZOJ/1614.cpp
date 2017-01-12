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
//#define Judge
//#define Debug
#define MAXM (20005)
#define MAXN (1005)
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
	if(x==-1) {puts("-1");return;}
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
	int pre,next,w;
}E[MAXM];
int G[MAXN],dist[MAXN];
bool vis[MAXN];
int N,P,K,tot;

inline void Ins(int x,int y,int w){
	E[++tot]=(Edge){y,G[x],w};
	G[x]=tot;
}

void init(){
	int x,y,w;
	#ifdef Judge
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	SpeedUp;
	#endif
	read(N),read(P),read(K);
	for(int i=1;i<=P;i++){
		read(x),read(y),read(w);
		Ins(x,y,w);
		Ins(y,x,w);
	}
}

bool check_SPFA(int x){
	queue<int> Q;
	memset(dist,127,sizeof(dist));
	dist[1]=0;
	Q.push(1);
	vis[1]=true;
	while(!Q.empty()){
		int k=Q.front();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].pre;
			int s=(E[u].w>x ? dist[k]+1 : dist[k]);
			if(s<dist[v]){
				dist[v]=s;
				if(!vis[v]){
					Q.push(v);
					vis[v]=true;
				}
			}
		}
		Q.pop();
		vis[k]=false;
	}
	return dist[N]<=K;
}

void work(){
	int l=0,r=1000000,Ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		check_SPFA(mid) ? Ans=mid,r=mid-1 : l=mid+1;
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