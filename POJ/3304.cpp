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
#define MAXN (102)
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
	double operator * (const Point &v)const{
		return x*v.y-y*v.x;
	}
	Point operator - (const Point &v)const{
		return Point(x-v.x,y-v.y);
	}
}P[MAXN<<1];

struct Segment{
	Point s,t;
	Segment(Point _s=Point(0,0),Point _t=Point(0,0)):
		s(_s),t(_t){}
}L[MAXN];

double cross(const Point p1,const Point p2,const Point p0){
	return (p1-p0)*(p2-p0);
}

inline int sign(double x){
	return (x>eps)-(x<eps);
}

int N,T;

void init(){
#ifdef Judge
	freopen("3304.in","r",stdin);
	freopen("3304.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&T);
}

void work(){
	double x1,y1,x2,y2;
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			L[i].s=P[(i<<1)-1]=Point(x1,y1);
			L[i].t=P[i<<1]=Point(x2,y2);
		}
		for(int i=1;i<=N<<1;i++)
			for(int j=i+1;j<=N<<1;j++){
				if(fabs(P[i].x-P[j].x)<eps && fabs(P[i].y-P[j].y)<eps)
					continue;
				int k;
				for(k=1;k<=N;k++)
					if(sign(cross(L[k].s,P[i],P[j])*cross(L[k].t,P[i],P[j]))>0)
						break;
				if(k==N+1) goto victory;
			}
		printf("No!\n");	continue;
		victory:
		printf("Yes!\n");
	}
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