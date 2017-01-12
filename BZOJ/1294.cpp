/*
	Machine: Class4_B2
	System: Ubuntu_Kylin 14.10
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <bitset>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (11)
#define MAXM (520)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;
const int DirX[]={1,-1,0,0};
const int DirY[]={0,0,1,-1};

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()
#define sqr(x)	((x)*(x))

int Ans,N,M,D;
char G[MAXN][MAXN];
int V[MAXN];
int dist[MAXM][MAXN][MAXN];
bool vis[MAXM][MAXN][MAXN];
pair<int,int> P[MAXN];

struct Node{
	int x,y;
	bitset<10> s;
	Node(){}
	Node(int x,int y):
		x(x),y(y){}
	inline Node next(int k){
		return Node(x+DirX[k],y+DirY[k]);
	}
	inline bool legal(){
		return x>=1 && x<=N && y>=1 && y<=M && G[x][y]=='0';
	}
	inline int Modify(int _x,int _y){
		bitset<10> t=s;
		for(int i=0;i<D;i++)
			if(_y>P[i].second && ((x<=P[i].first && _x>P[i].first) || (x>P[i].first && _x<=P[i].first)))
				t.flip(i);
		return t.to_ulong();
	}
};

void init(){
#ifdef Judge
	freopen("1294.in","r",stdin);
	freopen("1294.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M),read(D);
	for(int i=0;i<D;i++)
		read(V[i]);
	for(int i=1;i<=N;i++){
		scanf("%s",G[i]+1);
		for(int j=1;j<=M;j++)
			if('1'<=G[i][j] && G[i][j]<='9')
				P[G[i][j]-'1']=make_pair(i,j);
	}
}

void SPFA(int x,int y){
	static queue<Node> Q;
	memset(dist,127,sizeof(dist));
	memset(vis,false,sizeof(vis));
	while(!Q.empty())	Q.pop();
	dist[0][x][y]=0;
	Q.push(Node(x,y)),Q.front().s.reset();
	vis[0][x][y]=true; 
	while(!Q.empty()){
		Node k=Q.front();
		Q.pop();
		vis[k.s.to_ulong()][x][y]=false;
		for(int i=0;i<4;i++){
			Node nxt=k.next(i);
			if(!nxt.legal())	continue;
			int tmp=k.Modify(nxt.x,nxt.y);
			if(dist[tmp][nxt.x][nxt.y] > dist[k.s.to_ulong()][k.x][k.y]+1){
				dist[tmp][nxt.x][nxt.y]=dist[k.s.to_ulong()][k.x][k.y]+1;
				if(!vis[tmp][nxt.x][nxt.y]){
					vis[tmp][nxt.x][nxt.y]=true;
					nxt.s=bitset<10>(tmp);
					Q.push(nxt);
				}
			}
		}
	}
}

void maintain(int x,int y){
	for(int i=0;i<(1<<D);i++){
		int tmp=-dist[i][x][y];
		for(int j=0;j<D;j++)
			if((i>>j)&1)
				tmp+=V[j];
		Ans=max(Ans,tmp);
	}
}

void work(){
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			if(G[i][j]=='0')
				SPFA(i,j),maintain(i,j);
	print(Ans);
}

int main(){
	init();
	work();
#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(G)+sizeof(V)+sizeof(dist)+sizeof(vis)+sizeof(P))/1048576<<" MB."<<endl;
#endif
	return 0;
}
