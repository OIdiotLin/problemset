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
#define MAXN (200005)
#define INF ()
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

struct Segment{
	Point s,t;
	int id;
	double slope;
	Segment(){}
	inline bool operator < (const Segment &v) const{
		return equal(slope,v.slope) ? ((t-s)^(v.s-s))>0 : slope<v.slope;
	}
}L[MAXN],*Q[MAXN],*tmp[MAXN];
inline Point Inter(const Segment &u,const Segment &v) const{
	double k1,k2,delta;
	k1=(v.t-u.s)^(u.t-u.s);
	k2=(u.t-u.s)^(v.s-u.s);
	delta=k2/(k1+k2);
	return v.s+(v.t-v.s)*delta;
}

inline bool chk(Segment a,Segment b,Segment x){
	Point p=Inter(a,b);
	return (x.t-x.s)^(p-x.s)>0;
}

int N,tot;

void init(){
	int x,y1,y2;
#ifdef Judge
	freopen("1483.in","r",stdin);
	freopen("1483.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
		read(x),read(y1),read(y2);
		
}

bool chk_hpi(int x){
	int cnt=0;
	for(int i=1;i<=M;i++)
		if(L[i].id<=x){
			if()
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