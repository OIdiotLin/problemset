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
const double eps=1e-7;

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

const int N=4;

inline bool equal(double x,double y){
	return fabs(x-y)<eps;
}

struct Point{
	double x,y;
	Point(double _x=0,double _y=0):
		x(_x),y(_y){}
	Point operator + (const Point &v) const{
		return Point(x+v.x,y+v.y);
	}
	Point operator - (const Point &v) const{
		return Point(x-v.x,y-v.y);
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
}P[10];

Point MidPoint(Point p1,Point p2){
	return (p1+p2)*0.5;
}

bool vertical(Point s1,Point t1,Point s2,Point t2){
	return equal((s1-t1)*(s2-t2),0);
}

bool chk_vertex(Point s,Point t,Point p1,Point p2){
	Point m=((p1-s)+(p2-s))*0.5;
	return !equal((m-s)^(t-s),0);
}

void init(){
#ifdef Judge
	freopen("1963.in","r",stdin);
	freopen("1963.out","w",stdout);
//	SpeedUp;
#endif
	for(int i=1;i<=N;i++)
		scanf("%lf%lf",&P[i].x,&P[i].y);
	for(int i=1;i<=N;i++)
		P[N+i]=MidPoint(P[i],P[(i+1>N ? 1 : i+1)]);
}

void work(){
	int cnt=0;
	for(int i=1;i<=2;i++)
		if(chk_vertex(P[i],P[i+2],P[i+1],P[i+3]) && vertical(P[i],P[i+2],P[i+1],P[i+3]))
			cnt++;
	for(int i=1;i<=2;i++)
		if(vertical(P[i],P[i+1],P[i+4],P[i+6]) && vertical(P[i+2],P[i+3],P[i+4],P[i+6]))
			cnt++;
	printf("%d\n",cnt<<1);
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