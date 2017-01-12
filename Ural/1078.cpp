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
#define MAXN (505)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0){putchar('-'); x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(32);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Segment{
	int l,r;
	void Read(){
		read(l),read(r);
	}
	bool Cover(const Segment &b)const{
		return l<b.l&&r>b.r;
	}
}A[MAXN];
int N;
bool G[MAXN][MAXN];
int f[MAXN],path[MAXN];
bool vis[MAXN];

void init(){
#ifdef Judge
	freopen("1078.in","r",stdin);
	freopen("1078.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++)
		A[i].Read();
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(A[i].Cover(A[j]))
				G[i][j]=true;
}

inline void dfs(int u){
	f[u]=1;
	vis[u]=1;
	for(int v=1;v<=N;v++)
		if(G[u][v]){
			if(!vis[v]) dfs(v);
			if(f[v]+1>f[u])
				f[u]=f[v]+1,path[u]=v;
		}
}

void Out(int st){
	if(path[st]==-1) return;
	Out(path[st]);
	print(path[st]);
}

void work(){
	memset(path,-1,sizeof(path));
	int Max=0,S=0;
	for(int i=1;i<=N;i++){
		if(!vis[i]){
			f[i]=1;
			vis[i]=true;
			for(int j=1;j<=N;j++)
				if(G[i][j]){
					dfs(j);
					if(f[j]+1>f[i])
						f[i]=f[j]+1,path[i]=j;
				}
		}
		if(f[i]>Max)
			Max=f[i],S=i;
	}
	print(Max);
	cout<<endl;
	Out(S);print(S);
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