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
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (105)
#define MAXM (200002)
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
	int v,next;
	Edge(int _v=0,int _n=0):
		v(_v),next(_n){}
}E[MAXM];

int N,tot;
int G[MAXN];
bool C[MAXN],vis[MAXN];

inline void Ins(int u,int v){
	E[++tot]=Edge(v,G[u]);	G[u]=tot;
	E[++tot]=Edge(u,G[v]);	G[v]=tot;
}

void init(){
	int u,v;
#ifdef Judge
	freopen("1106.in","r",stdin);
	freopen("1106.out","w",stdout);
//	SpeedUp;
#endif
	cin>>N;
	memset(C,false,sizeof(C));
	memset(vis,false,sizeof(vis));
	for(u=1;u<=N;u++){
		while(true){
			cin>>v;	if(!v)	break;
			Ins(u,v);
		}
	}
}

void dfs(int x){
	vis[x]=true;
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(!vis[v]){
			C[v]=C[x]^1;
			dfs(v);
		}
	}
}

void work(){
	int Ans=0;
	for(int i=1;i<=N;i++)
		if(!vis[i])
			dfs(i);
	for(int i=1;i<=N;i++)
		if(C[i]) Ans++;
	cout<<Ans<<endl;
	for(int i=1;i<=N;i++)
		if(C[i])
			cout<<i<<" ";
	cout<<endl;
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