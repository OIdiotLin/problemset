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

#define sqr(x) ((x)*(x))

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
};

vector<Point> P;
int N;
double maxH,x,y,z;

void init(){
#ifdef Judge
	freopen("4986.in","r",stdin);
	freopen("4986.out","w",stdout);
//	SpeedUp;
#endif
}

double h2r(double h){
	double r=0;
	for(vector<Point>::iterator p=P.begin();p!=P.end();++p)
		if(r*(h-p->y)<h*p->x)
			r=h*p->x/(h-p->y);
	return r;
}

void work(){
	P.clear();
	maxH=0;
	for(int i=1;i<=N;i++){
		scanf("%lf%lf%lf",&x,&y,&z);
		Point p=Point(sqrt(sqr(x)+sqr(y)),z);
		P.push_back(p);
		maxH=max(maxH,z);
	}
	double l=maxH,r=1e11;
	while(r-l>eps){
		double tmp=(r-l)/3.0;
		double mid1=l+tmp,mid2=l+tmp*2;
		if(sqr(h2r(mid1))*mid1>sqr(h2r(mid2))*mid2)
			l=mid1;
		else r=mid2;
	}
	printf("%.3lf %.3lf\n",l+eps,h2r(l)+eps);
}

int main(){
	init();
	while(scanf("%d",&N)!=EOF)
		work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}