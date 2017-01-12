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
#include <stack>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (10005)
#define MAXM (50005)
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
}E1[MAXM],E2[MAXM];

int N,M,tot,scc,id;
int G1[MAXN],G2[MAXN];
int dfn[MAXN],low[MAXN],own[MAXN],pertain[MAXN];
bool vis[MAXN];

inline void Ins1(int u,int v){
	E1[++tot]=Edge(v,G1[u]);	G1[u]=tot;
}
inline void Ins2(int u,int v){
	E2[++tot]=Edge(v,G2[u]);	G2[u]=tot;
}

void init(){
	int u,v;
#ifdef Judge
	freopen("1051.in","r",stdin);
	freopen("1051.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	for(int i=1;i<=M;i++){
		read(u),read(v);
		Ins1(u,v);
	}
}

void Make_NewG(){
	tot=0;
	for(int x=1;x<=N;x++)
		for(int u=G1[x];u;u=E1[u].next){
			int v=E1[u].v;
			if(pertain[x]!=pertain[v])
				Ins2(pertain[x],pertain[v]);
		}
}

stack<int> St;
void Tarjan(int x){
	dfn[x]=low[x]=++id;
	St.push(x);
	vis[x]=true;
	for(int u=G1[x];u;u=E1[u].next){
		int v=E1[u].v;
		if(dfn[v]==0){
			Tarjan(v);
			low[x]=min(low[x],low[v]);
		}else if(vis[v])
			low[x]=min(low[x],dfn[v]);
	}
	int k=0;
	if(low[x]==dfn[x]){
		scc++;
		while(k!=x){
			k=St.top();
			St.pop();
			vis[k]=false;
			own[scc]++;
			pertain[k]=scc;
		}
	}
}

void work(){
	bool flag=false;
	int Ans;
	for(int i=1;i<=N;i++)
		if(dfn[i]==0)
			Tarjan(i);
	Make_NewG();
	for(int i=1;i<=scc;i++)
		if(!G2[i]){
			if(flag){
				puts("0");
				return;
			}else{
				Ans=own[i];
				flag=true;
			}
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