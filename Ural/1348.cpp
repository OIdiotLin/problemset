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
#define MAXN (300001)
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
#define sqr(x)	((x)*(x))

struct Point{
	double x,y;
	Point(double _x=0,double _y=0):
		x(_x),y(_y){}
	Point operator * (const double k)const{
		return Point(k*x,k*y);
	}
	Point operator + (const Point &v)const{
		return Point(x+v.x,y+v.y);
	}
	Point operator - (const Point &v)const{
		return Point(x-v.x,y-v.y);
	}
	double dprod(const Point &v)const{
		return x*v.x+y*v.y;
	}
	double cprod(const Point &v)const{
		return x*v.y-y*v.x;
	}
}C;

struct Segment{
	Point s,t;
	Segment(Point _s=Point(0,0),Point _t=Point(0,0)):
		s(_s),t(_t){}
}L;

double R;

double dist(Point A,Point B){
	return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));
}

double dist(Point A,Segment l){
	double dp=(A-l.s).dprod(l.t-l.s);
	if(dp<eps)		return dist(A,l.s);
	double iprod=(l.t-l.s).dprod(l.t-l.s);
	if(dp>=iprod)	return dist(A,l.t);
	double k=dp/iprod;
	Point C=l.s+(l.t-l.s)*k;
	return dist(A,C);
}

void init(){
#ifdef Judge
	freopen("1348.in","r",stdin);
	freopen("1348.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%lf%lf%lf%lf",&L.s.x,&L.s.y,&L.t.x,&L.t.y);
	scanf("%lf%lf%lf",&C.x,&C.y,&R);
}

void work(){
	double ans1=dist(C,L);
	if(ans1>R) ans1-=R; else ans1=0;
	double ans2=max(dist(C,L.s),dist(C,L.t));
	if(ans2>R) ans2-=R; else ans2=0;
	printf("%.2lf\n%.2lf\n",ans1,ans2);
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