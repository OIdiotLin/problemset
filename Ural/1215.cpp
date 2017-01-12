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
	Point operator * (const int &a) const{
		return Point(x*a,y*a);
	}
	double operator * (const Point &v) const{
		return x*v.x+y*v.y;
	}
	double operator ^ (const Point &v) const{
		return x*v.y-y*v.x;
	}
}P[MAXN],A;

int N;

bool Cover(){
	for(int i=1;i<=N;i++){
		Point p0=P[i-1],p1=P[i],p2=P[i+1];
		if(((p1-p0)^(A-p0)) * ((p2-p1)^(A-p1)) < 0)
			return false;
	}
	return true;
}

void init(){
#ifdef Judge
	freopen("1215.in","r",stdin);
	freopen("1215.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%lf%lf%d",&A.x,&A.y,&N);
	for(int i=1;i<=N;i++)
		scanf("%lf%lf",&P[i].x,&P[i].y);
	P[N+1]=P[1],P[0]=P[N];
}

#define sqr(x) ((x)*(x))

double dist(Point p0,Point p1){
	return sqrt(sqr(p0.x-p1.x)+sqr(p0.y-p1.y));
}

//#define F

#ifdef F
double dist(Point p0,Point p1,Point p2){
	double dp=(p0-p1)*(p2-p1);
	if(dp<eps)		return dist(p0,p1);
	double iprod=(p2-p1)*(p2-p1);
	if(dp>iprod)	return dist(p0,p2);
	double k=dp/iprod;
	Point C=p1+(p2-p1)*k;
	return dist(p0,C);
}
#endif
#ifndef F
double dist(Point p0,Point p1,Point p2){
	double a,b,c;
	a=dist(p0,p1);
	if(a<eps)	return 0;
	b=dist(p0,p2);
	if(b<eps)	return 0;
	c=dist(p1,p2);
	if(c<eps)	return 0;
	if(sqr(b)>=sqr(a)+sqr(c))	return a;
	if(sqr(a)>=sqr(b)+sqr(c))	return b;
	double p=(a+b+c)/2,s=sqrt(p*(p-a)*(p-b)*(p-c));
	return s*2/c;
}
#endif

void work(){
	if(Cover()){
		printf("%.3lf\n",0.0);
		return;
	}
	double Min=1e20;
	for(int i=1;i<=N;i++){
		Point p1=P[i],p2=P[i+1];
		Min=min(Min,dist(A,p1,p2));
	}
	printf("%.3lf\n",Min*2);
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