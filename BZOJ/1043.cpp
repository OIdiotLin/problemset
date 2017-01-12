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
#define MAXN (1003)
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
#define sqr(x)	((x)*(x))

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
	double operator ^ (const  Point &v) const{
		return x*v.y-y*v.x;
	}
	bool operator == (const Point &v) const{
		return equal(x,v.x) && equal(y,v.y);
	}
	void Read(){
		scanf("%lf%lf",&x,&y);
	}
};
inline double dist(const Point &u,const Point &v){
	return sqrt((u-v)*(u-v));
}

struct Circle{
	Point C;
	double r;
	Circle(){}
	Circle(Point _c,double _r):
		C(_c),r(_r){}
	inline bool Contain(const Circle &T) const{
		return r>=T.r+dist(C,T.C);
	}
	void Read(){
		scanf("%lf",&r);
		C.Read();
	}
}C[MAXN];

struct Segment{
	double l,r;
	Segment(){}
	Segment(double _l,double _r):
		l(_l),r(_r){}
	inline bool operator < (const Segment &v) const{
		return l<v.l;
	}
	void format(){
		if(l<0)	l+=2*PI;
		if(r<0)	r+=2*PI;
	}
};

inline Segment Inter(const Circle &A,const Circle &B){
	double d=dist(A.C,B.C);
	double t=(sqr(A.r)-sqr(B.r)+sqr(d))/(d*2);
	double mid=atan2(A.C.x-B.C.x,A.C.y-B.C.y);
	double theta=acos(t/A.r);
	return Segment(mid-theta,mid+theta);
}

int N;

void init(){
#ifdef Judge
	freopen("1043.in","r",stdin);
	freopen("1043.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		C[i].Read();
}

double Calc_arclen(int x){
	for(int i=x+1;i<=N;i++)
		if(C[i].Contain(C[x]))
			return 0;
	int cnt=0;
	static Segment Q[MAXN];
	for(int i=x+1;i<=N;i++)
		if(!C[x].Contain(C[i]) && C[x].r+C[i].r>=dist(C[x].C,C[i].C))
			Q[++cnt]=Inter(C[x],C[i]);
	for(int i=1;i<=cnt;i++){
		Q[i].format();
		if(Q[i].l>Q[i].r){
			Q[cnt++]=Segment(0,Q[i].r);
			Q[i].r=2*PI;
		}
	}
	sort(Q+1,Q+cnt+1);
	double len=0,cur=0;
	for(int i=1;i<=cnt;i++)
		if(Q[i].l>cur){
			len+=Q[i].l-cur;
			cur=Q[i].r;
		}else	cur=max(cur,Q[i].r);
	len+=2*PI-cur;
	return C[x].r*len;
}

void work(){
	double ans=0;
	for(int i=1;i<=N;i++)
		ans+=Calc_arclen(i);
	printf("%.3lf\n",ans);
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