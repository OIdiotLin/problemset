/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
#define Debug
#define MAXN (1005)
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
	int x,y;
	Point(int _x=0,int _y=0):
		x(_x),y(_y){}
	Point operator + (const Point &v) const{
		return Point(x+v.x,y+v.y);
	}
	Point operator - (const Point &v) const{
		return Point(x-v.x,y-v.y);
	}
	double operator * (const Point &v) const{
		return x*v.x+y*v.y;
	}
	double operator ^ (const Point &v) const{
		return x*v.y-y*v.x;
	}
	bool operator < (const Point &v) const{
		if(x==v.x)
			return y<v.y;
		return x<v.x;
	}
}P[MAXN],stk[MAXN];
#define sqr(x) ((x)*(x))
double dist(Point A,Point B){
	return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));
}
inline bool cmp(Point p1,Point p2){
	int crsprod=(p1-P[1])^(p2-P[1]);
	return crsprod==0 ? dist(p1,P[1])<dist(p2,P[1]) : crsprod>0;
}

int N,L;
double ans;

void init(){
	Point mn=Point(20000,20000);
	int k;
#ifdef Judge
	freopen("1185.in","r",stdin);
	freopen("1185.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d%d",&N,&L);
//	cin>>N>>L;
	for(int i=1;i<=N;i++){
		scanf("%d%d",&P[i].x,&P[i].y);
//		cin>>P[i].x>>P[i].y;
		if(P[i]<mn){
			mn=P[i];
			k=i;
		}
	}
	swap(P[1],P[k]);
#ifdef Debug
	printf("The O point is (%d,%d)\n",P[1].x,P[1].y);
#endif
}

void Graham(){
	static Point stk[MAXN];
	int top=0;
	sort(P+2,P+N+1,cmp);
#ifdef Debug
	for(int i=1;i<=N;i++)
		printf("P[%d]=(%d,%d)\n",i,P[i].x,P[i].y);
#endif
	stk[++top]=P[1],stk[++top]=P[2],stk[++top]=P[3];
	for(int i=4;i<=N;i++){
		while(top>1 && ((P[i]-stk[top-1])^(stk[top]-stk[top-1]))>=0) top--;
		stk[++top]=P[i];
	}
	stk[++top]=P[1];
#ifdef Debug
	for(int i=1;i<=top;i++)
		printf("Hull Point is (%d,%d)\n",stk[i].x,stk[i].y);
#endif
	for(int i=1;i<top;i++){
		ans+=dist(stk[i],stk[i+1]);
#ifdef Debug
		printf("%lf\n",dist(stk[i],stk[i+1]));
#endif
	}
}

void work(){
	Graham();
#ifdef Debug
	printf("convex hull: %lf\n",ans);
#endif
	ans+=2*L*PI;
	printf("%.0f\n",ans);
}

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof(P)*2)/1048576<<" MB."<<endl;
#endif
	return 0;
}