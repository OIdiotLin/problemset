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
#define MAXN ()
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

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

inline bool equal(double x,double y){
	return fabs(x-y)<eps;
}

struct Point{
	double x,y;
	Point(double _x=0,double _y=0):
		x(_x),y(_y){}
	Point operator - (const Point &v) const{
		return Point(x-v.x,y-v.y);
	}
	Point operator + (const Point &v) const{
		return Point(x+v.x,y+v.y);
	}
	Point operator * (const double &k) const{
		return Point(x*k,y*k);
	}
	double operator * (const Point &v) const{
		return x*v.x+y*v.y;
	}
	double operator ^ (const Point &v) const{
		return x*v.y-y*v.x;
	}
	bool operator == (const Point &v) const{
		return equal(x,v.x) && equal(y,v.y);
	}
	double angle(){
		return atan2(y,x);
	}
	double length(){
		return sqrt((*this)*(*this));
	}
};

struct Circle{
	Point c;
	double r;
	Circle(){}
	Circle(Point _c,double _r):
		c(_c),r(_r){}
	Point Pnt_arc(const double &arc) const{
		return Point(c.x+r*cos(arc),c.y+r*sin(arc));
	}
	bool CoverPnt(const Point &p) const{
		double dist=(c-p).length();
		return dist-r<eps;
	}
	bool CoverCir(const Circle &C) const{
		double dist_c=(C.c-c).length();
		double diff_r=r-C.r;
		return diff_r<=eps && dist_c-diff_r<=eps;
	}
	Point InterPnt(const Circle &C) const{
		double dist_c=(C.c-c).length();
	}
};

int N;
Circle C[MAXN];
bool vis[MAXN];
vector<double> Ang[MAXN];

void init(){
#ifdef Judge
	freopen("2572.in","r",stdin);
	freopen("2572.out","w",stdout);
//	SpeedUp;
#endif
}



int main(){
	init();
	while(scanf("%d",&N)!=EOF && N){
		Init();
		work();
	}
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}