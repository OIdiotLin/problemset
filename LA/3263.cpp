/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
// #define Debug
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
	bool operator < (const Point &v) const{
		return equal(x,v.x) ? y<v.y : x<v.x;
	}
	bool operator == (const Point &v) const{
		return equal(x,v.x) && equal(y,v.y);
	}
	bool onSeg(const Point &s,const Point &t) const{
		return equal((s-*this)^(t-*this),0) && (s-*this)*(t-*this)<0;
	}
}P[MAXN];
vector<Point> v;

bool properInter(Point s1,Point t1,Point s2,Point t2){
	return (((t1-s1)^(s2-s1))*((t1-s1)^(t2-s1))<-eps)&&(((t2-s2)^(s1-s2))*((t2-s2)^(t1-s2))<-eps);
}

Point getInter(Point s1,Point t1,Point s2,Point t2){
	Point v=t1-s1,w=t2-s2,u=s1-s2;
	double t=(w^u)/(v^w);
	return s1+v*t;
}

int N,V,E,cas;

void init(){
	v.clear();
	read(N);
	if(N==0)	exit(0);
	for(int i=0;i<N;i++){
		scanf("%lf%lf",&P[i].x,&P[i].y);
		v.push_back(P[i]);
	}
	E=--N;
	v.pop_back();
}

void work(){
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(properInter(P[i],P[i+1],P[j],P[j+1]))
				v.push_back(getInter(P[i],P[i+1],P[j],P[j+1]));
	sort(v.begin(),v.end());
	V=unique(v.begin(),v.end())-v.begin();
#ifdef Debug
	for(int i=0;i<v.size();i++)
		printf("x=%lf,y=%lf\n",v[i].x,v[i].y);
	printf("V = %d\n",V);
#endif
	for(int i=0;i<V;i++)
		for(int j=0;j<N;j++)
			if(v[i].onSeg(P[j],P[j+1]))
				E++;
	printf("Case %d: There are %d pieces.\n",++cas,E+2-V);
}

int main(){
#ifdef Judge
	freopen("3263.in","r",stdin);
	freopen("3263.out","w",stdout);
//	SpeedUp;
#endif
	while(true){
		init();
		work();
	}
	Point A=Point(0,-1),B=Point(5,2),C=Point(0,0),D=Point(5,0);
	Point P=getInter(A,B,C,D);
	printf("%d\n",properInter(A,B,C,D));
	printf("%lf\t%lf\n",P.x,P.y);
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(P)+sizeof(v))/1048576<<" MB."<<endl;
#endif
	return 0;
}