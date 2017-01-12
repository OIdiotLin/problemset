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
#define MAXM (805)
#define MAXN (22)
#define INF (0x7fffffff)
const double PI	=	acos(-1);
const int ZCY	=	1000000007;
const int AMOUNT=	400;

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
	int v,next,w;
	Edge(int _v=0,int _next=0,int _w=0):v(_v),next(_next),w(_w){}
}E[500005];
int G[MAXM],Map[MAXN][MAXN];
int h[MAXM];
int R,C,D,tot,Ans;

#define sqr(x) ((x)*(x))
inline bool InRange(int x1,int y1,int x2,int y2){
	return (sqr(x1-x2)+sqr(y1-y2)<=sqr(D))&&(Map[x1][y1])&&(Map[x2][y2]);
}

inline void Ins(int u,int v,int w){
	E[++tot]=Edge(v,G[u],w),G[u]=tot;
	E[++tot]=Edge(u,G[v],0),G[v]=tot;
}

#define id(i,j) ((i-1)*C+j)

void init(){
	string st;
	tot=1;
#ifdef Judge
	freopen("1066.in","r",stdin);
	freopen("1066.out","w",stdout);
	SpeedUp;
#endif
	cin>>R>>C>>D;
	for(int i=1;i<=R;i++){
		cin>>st;
		for(int j=1;j<=C;j++)
			Map[i][j]=st[j-1]-'0';
	}
	for(int i=1;i<=R;i++){
		cin>>st;
		for(int j=1;j<=C;j++)
			if(st[j-1]=='L'){
				Ins(0,id(i,j),1);
				Ans++;
			}
	}
	for(int i=1;i<=D;i++)
		for(int j=D+1;j<=R-D;j++){
			Ins(id(j,i)+AMOUNT,AMOUNT<<1|1,INF);
			Ins(id(j,C-i+1)+AMOUNT,AMOUNT<<1|1,INF);
		}
	for(int i=1;i<=D;i++)
		for(int j=1;j<=C;j++){
			Ins(id(i,j)+AMOUNT,AMOUNT<<1|1,INF);
			Ins(id(R-i+1,j)+AMOUNT,AMOUNT<<1|1,INF);
		}
	for(int x1=1;x1<=R;x1++)
		for(int y1=1;y1<=C;y1++)
			for(int x2=x1-D;x2<=x1+D;x2++)
				for(int y2=y1-D;y2<=y1+D;y2++)
					if(InRange(x1,y1,x2,y2) && (x1!=x2 || y1!=y2))
						Ins(id(x1,y1)+AMOUNT,id(x2,y2),INF);
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			if(Map[i][j])
				Ins(id(i,j),id(i,j)+AMOUNT,Map[i][j]);
}

queue<int> Q;
bool BFS(){
	while(!Q.empty()) Q.pop();
	memset(h,-1,sizeof(h));
	Q.push(0);
	h[0]=0;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		for(int u=G[k];u;u=E[u].next){
			int v=E[u].v;
			if(h[v]==-1&&E[u].w){
				h[v]=h[k]+1;
				Q.push(v);
			}
		}
	}
	return h[AMOUNT<<1|1]!=-1;
}

int DFS(int x,int f){
	if(x==(AMOUNT<<1|1)) return f;
	int cnt=0;
	for(int u=G[x];u;u=E[u].next){
		int v=E[u].v;
		if(h[v]==h[x]+1&&E[u].w){
			int w=f-cnt;
			w=DFS(v,min(w,E[u].w));
			E[u].w-=w;
			E[u^1].w+=w;
			cnt+=w;
			if(cnt==f) return f;
		}
	}
	if(cnt==0) h[x]=-1;
	return cnt;
}

void dinic(){
	while(BFS()) Ans-=DFS(0,INF);
}

void work(){
	dinic();
	cout<<Ans<<endl;
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(G)+sizeof(E)+sizeof(Map))/1048576<<" MB."<<endl;
#endif
	return 0;
}
