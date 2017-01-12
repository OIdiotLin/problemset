/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <queue>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (105)
#define INF (10000000000LL)
const double PI=acos(-1);
const int ZCY=1000000007;
const int DirX[]={0,1,0,-1,0};
const int DirY[]={0,0,1,0,-1};

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

struct Pos{
	int x,y;
	Pos(int _x=0,int _y=0):x(_x),y(_y){};
};

int h[MAXN][MAXN];
bool vis[MAXN][MAXN];
double dist[MAXN][MAXN];
double v[MAXN][MAXN];
int R,C;
double v0;

void init(){
#ifdef Judge
	freopen("1744.in","r",stdin);
	freopen("1744.out","w",stdout);
	SpeedUp;
#endif
	cin>>v0>>R>>C;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++){
			cin>>h[i][j];
			v[i][j]=v0*pow(2.0,(h[1][1]-h[i][j]));
		}
	v[1][1]=v0;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			dist[i][j]=INF;
}

inline bool InRange(Pos p){
	return (p.x && p.y && p.x<=R && p.y<=C);
}

queue<Pos> Q;
void SPFA(){
	dist[1][1]=0,vis[1][1]=true;
	Pos k=Pos(1,1);
	Q.push(k);
	while(!Q.empty()){
		k=Q.front();
		Q.pop();
		vis[k.x][k.y]=false;
		for(int i=1;i<=4;i++){
			Pos nxt;
			nxt.x=k.x+DirX[i];
			nxt.y=k.y+DirY[i];
			if(!InRange(nxt)) continue;
			double cost=1.0/v[k.x][k.y];
			if(dist[k.x][k.y]+cost<dist[nxt.x][nxt.y]){
				dist[nxt.x][nxt.y]=dist[k.x][k.y]+cost;
				if(!vis[nxt.x][nxt.y]){
					vis[nxt.x][nxt.y]=true;
					Q.push(nxt);
				}
			}
		}
	}
}

void work(){
	SPFA();
	cout<<fixed<<setprecision(2)<<dist[R][C]<<endl;
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
