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
#define MAXN (200005)
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
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

inline bool equal(const double u,const double v){
	return fabs(u-v)<eps;
}

struct Point{
	double x,y;
	Point(double _x=0,double _y=0):
		x(_x),y(_y){}
	inline Point operator - (const Point &v) const{
		return Point(x-v.x,y-v.y);
	}
	inline Point operator + (const Point &v) const{
		return Point(x+v.x,y+v.y);
	}
	inline Point operator * (const double &k) const{
		return Point(x*k,y*k);
	}
	inline double operator * (const Point &v) const{
		return x*v.x+y*v.y;
	}
	inline double operator ^ (const Point &v) const{
		return x*v.y-y*v.x;
	}
	inline bool operator == (const Point &v) const{
		return equal(x,v.x) && equal(y,v.y);
	}
}P[MAXN];

int N,k;

bool chk(Point p0,Point p1,Point p2){
	return ((p0-p1)^(p2-p1))>0;
}

void init(){
	double mx=-1e10;
#ifdef Judge
	freopen("1246.in","r",stdin);
	freopen("1246.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
		read(P[i].x),read(P[i].y);
		if(mx<P[i].x)	k=i,mx=P[i].x;
	}
	P[0]=P[N],P[N+1]=P[1];
}

void work(){
	puts(chk(P[k-1],P[k],P[k+1]) ? "cw" : "ccw");
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