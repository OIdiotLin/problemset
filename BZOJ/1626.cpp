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
//#define Judge
//#define Debug
#define MAXN (1002)
#define INF (1<<28)
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
#define sqr(x) ((x)*(x))
struct Point{
	double x,y;
	void Read(){
		cin>>x>>y;
	}
}P[MAXN];
inline double dist(Point A,Point B){return sqrt(sqr(A.x-B.x)+(B.x-B.y));}
double G[MAXN][MAXN],d[MAXN];
bool vis[MAXN];
int N,M;

void init(){
	#ifdef Judge
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	SpeedUp;
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		P[i].Read();
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			G[j][i]=G[i][j]=dist(P[i],P[j]);
	for(int i=1;i<=M;i++){
		cin>>x>>y;
		G[x][y]=G[y][x]=0;
	}
}

void Prim(int x){
	for(int i=1;i<=N;i++) d[i]=G[x][i];
	vis[x]=true;
	int Min,cnt=0;
	while(cnt!=N){
		Min=-1;
		for(int i=1;i<=N;i++){
			if(vis[i]) continue;
			if(Min==-1||d[i]<d[Min]) Min=i;
		}
		if(Min==-1) break;
		vis[Min]=1;
		Ans+=

int main(){
	init();
	work();
	#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
	#endif
	return 0;
}