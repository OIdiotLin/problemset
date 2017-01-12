/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (21)
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
}E[MAXN*MAXN];
int G[MAXN],pre[MAXN],V[MAXN][MAXN][MAXN];
bool vis[MAXN];
vector<pair<int,int> > Tar[MAXN];
int a,b,c,T,tot;

inline void Ins(int u,int v){
	E[++tot]=Edge(v,G[u]);	G[u]=tot;
}

void init(){
#ifdef Judge
	freopen("3140.in","r",stdin);
	freopen("3140.out","w",stdout);
//	SpeedUp;
#endif
	read(T);
}

bool find(int x){
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(!vis[v]){
			vis[v]=true;
			if(!pre[v] || find(pre[v])){
				pre[v]=x;
				return true;
			}
		}
	}
	return false;
}

void work(){
	read(a),read(b),read(c);
	int res=a;
	for(int i=1;i<=a;i++)
		Tar[i].clear();
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			for(int k=1;k<=c;k++){
				read(V[i][j][k]);
				if(V[i][j][k])
					Tar[i].push_back(make_pair(j,k));
			}
	for(int i=0;i<(1<<a);i++){
		int tmp=0;
		tot=0;
		memset(G,0,sizeof(G));
		memset(pre,0,sizeof(pre));
		for(int j=1;j<=a;j++)
			if((i>>(j-1))&1)
				++tmp;
			else for(vector<pair<int,int> >::iterator it=Tar[j].begin();it!=Tar[j].end();++it)
				Ins(it->first,it->second);
		for(int j=1;j<=b && tmp<res;j++){
			memset(vis,false,sizeof(vis));
			tmp+=find(j);
		}
		res=min(res,tmp);
	}
	print(res);
}

int main(){
	init();
	while(T--)
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}