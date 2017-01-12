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
#define MAXN (305)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

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

int N;

struct Point{
	double x,y;
	Point(double _x=0,double _y=0):
		x(_x),y(_y){}
	Point operator + (const Point& v) const{
		return Point(x+v.x,y+v.y);
	}
	Point operator - (const Point& v) const{
		return Point(x-v.x,y-v.y);
	}
	Point operator * (const double& k) const{
		return Point(k*x,k*y);
	}
	double operator * (const Point& v) const{
		return x*v.x+y*v.y;
	}
	double operator ^ (const Point& v) const{
		return x*v.y-y*v.x;
	}
	bool operator < (const Point& v) const{
		return (x==v.x ? y<v.y : x<v.x);
	}
}P[MAXN];
#define sqr(x) ((x)*(x))
double dist(Point A,Point B){
	return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));
}

double cross(Point p0,Point p1,Point p2){
	return (p0-p1)^(p2-p1);
}

bool G[MAXN][MAXN];

void init(){
#ifdef Judge
	freopen("1588.in","r",stdin);
	freopen("1588.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%lf%lf",&P[i].x,&P[i].y);
}

void work(){
	double ans=0;
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++){
			int mn=i,mx=j;
			if(P[j]<P[i])
				swap(mn,mx);
			for(int k=1;k<=N;k++){
				if(i==k || j==k) continue;
				if(cross(P[k],P[i],P[j])==0){
					if(P[k]<P[mn])	mn=k;
					if(P[mx]<P[k])	mx=k;
				}
			}
			if(G[mn][mx])	continue;
			ans+=dist(P[mn],P[mx]);
			G[mn][mx]=G[mx][mn]=true;
		}
	printf("%.0lf\n",ans);
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