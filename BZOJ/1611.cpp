/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
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
	if(x<0) {putchar('-');x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

const int DirX[]={0,1,0,-1};
const int DirY[]={1,0,-1,0};

struct QNode{
	int x,y,t;
	void Print(){
		cout<<x<<" "<<y<<" "<<t<<endl;
	}
	QNode (int x_=0,int y_=0,int t_=0):t(t_),x(x_),y(y_){}
};
int M,Ans;
int G[MAXN][MAXN];
bool vis[MAXN][MAXN];
deque<QNode> Q;

void init(){
	int x,y,t;
	#ifdef Judge
	freopen("1611.in","r",stdin);
	freopen("1611.out","w",stdout);
	SpeedUp;
	#endif
	read(M);
	memset(G,-1,sizeof(G));
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=M;i++){
		read(x),read(y),read(t);
		if(G[x][y]==-1 || G[x][y]>t) G[x][y]=t;
		if(x && (G[x-1][y]==-1||G[x-1][y]>t)) G[x-1][y]=t;
		if(G[x+1][y]==-1 || G[x+1][y]>t) G[x+1][y]=t;
		if(y && (G[x][y-1]==-1||G[x][y-1]>t)) G[x][y-1]=t;
		if(G[x][y+1]==-1 || G[x][y+1]>t) G[x][y+1]=t;
	}
	vis[0][0]=true;
	QNode s=QNode(0,0,0);
	Q.push_back(s);
}

void BFS(){
	while(!Q.empty()){
		QNode k=Q.front();
		int x=k.x,y=k.y,t=k.t;
		Q.pop_front();
		if(G[x][y]==-1) {Ans=t; return;}
		for(int i=0;i<4;i++){
			int nx=x+DirX[i],ny=y+DirY[i];
			if(nx<0||ny<0||vis[x][y]) continue;
			if(G[nx][ny]!=-1&&G[nx][ny]<=t+1) continue;
			Q.push_back(QNode(nx,ny,t+1));
			vis[nx][ny]=true;
		}
	}
	Ans=-1;
	return;
}

void work(){
	BFS();
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