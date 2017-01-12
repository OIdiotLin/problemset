/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (300001)
#define INF (1<<28)
const double PI=acos(-1);
const double eps=1e-8;
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

struct Rectangle{
	double x1,y1,x2,y2;
	Rectangle(double _x1=0,double _y1=0,double _x2=0,double _y2=0):x1(_x1),y1(_y1),x2(_x2),y2(_y2){}
	inline void Read(){
		read(x1),read(y1),read(x2),read(y2);
	}
};
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}	
	void Print(){
		cout<<"("<<x<<","<<y<<")"<<endl;
	}	
};

Point P[MAXN],O;
vector<Rectangle> R;
bool vis[MAXN];
int dis[MAXN];
int N,tot;

inline double dist_Mht(Point A,Point B){
	return fabs(A.x-B.x)+fabs(A.y-B.y);
}
inline bool Inter(Rectangle A,Rectangle B){
	if(B.x2<=A.x1 || B.x1>=A.x2) return false;
	if(B.y2<=A.y1 || B.y1>=A.y2) return false;
	return true;
}
inline bool Inter(Point A,Point B){
	double x1=A.x,x2=B.x,y1=A.y,y2=B.y;
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
	for(vector<Rectangle>::iterator it=R.begin();it!=R.end();++it)
		if(Inter(Rectangle(x1,y1,x2,y2),*it))
			return true;
	return false;
}


inline double Cross(double x,double y1,double y2){
	if(y1>y2) swap(y1,y2);
	if(x<=O.x) return false;
	return y1<O.y && y2>O.y;
}
	
vector<pair<int,int> > G[MAXN];
inline void Ins(int x,int y,int w){
	G[x].push_back(make_pair(y,w));
	G[y].push_back(make_pair(x,w));
}
/* Test Adding Edge P[i] and P[j] */
inline void AddEdge(int i,int j){
	int dist=dist_Mht(P[i],P[j]);
	if(dist<eps) return;
	Point Tmp=Point(P[i].x,P[j].y);
	if(!Inter(P[i],Tmp) && !Inter(Tmp,P[j])){
		if(Cross(P[i].x,P[i].y,Tmp.y)){
			Ins(i,j+tot,dist);
			Ins(i+tot,j,dist);
		}else{
			Ins(i,j,dist);
			Ins(i+tot,j+tot,dist);
		}
	}
	Tmp=Point(P[j].x,P[i].y);
	if(!Inter(P[i],Tmp) && !Inter(P[j],Tmp)){
		if(Cross(P[j].x,Tmp.y,P[j].y)){
			Ins(i,j+tot,dist);
			Ins(i+tot,j,dist);
		}else{
			Ins(i,j,dist);
			Ins(i+tot,j+tot,dist);
		}
	}
}

void init(){
	Rectangle t;
#ifdef Judge
	freopen("1343.in","r",stdin);
	freopen("1343.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
		t.Read();
		P[++tot]=Point(t.x1,t.y1);
		P[++tot]=Point(t.x1,t.y2);
		P[++tot]=Point(t.x2,t.y1);
		P[++tot]=Point(t.x2,t.y2);
		R.push_back(t);
	}
	O=P[1],O.x+=0.5,O.y+=0.5;
	
	N=(tot<<1);
	for(int i=1;i<=tot;i++)
		for(int j=i+1;j<tot;j++)
			AddEdge(i,j);
}

queue<int> Q;
int SPFA(int S,int T){
	memset(vis,false,sizeof(vis));
	memset(dis,127,sizeof(dis));
	Q.push(S),vis[S]=true,dis[S]=0;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		vis[k]=false;
		for(vector<pair<int,int> >::iterator it=G[k].begin();it!=G[k].end();++it){
			int v=(*it).first;
			if(dis[v]>dis[k]+(*it).second){
				dis[v]=dis[k]+(*it).second;
				if(!vis[v]){
					Q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	return dis[T];
}

void work(){
	int Ans=INF;
	for(int i=1;i<=tot;i++)
		Ans=min(Ans,SPFA(i,i+tot));
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