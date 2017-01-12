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
#define MAXN (10005)
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

struct Point{
	double x,y;
	double ang;
	int id;
	Point(double _x=0,double _y=0):
		x(_x),y(_y){}
	void CalcAngle(const Point O){
		double tx=x-O.x,ty=y-O.y;
		ang=atan2(ty,tx);
	}
	bool operator < (const Point &B) const{
		return ang<B.ang;
	}
}P[MAXN];

int N;

void init(){
	int t;
	double min=1e9+1;
#ifdef Judge
	freopen("1207.in","r",stdin);
	freopen("1207.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lf %lf",&P[i].x,&P[i].y);
		P[i].id=i;
		if(P[i].y<min) t=i,min=P[i].y;
	}
	swap(P[1],P[t]);
}

void work(){
	for(int i=2;i<=N;i++)
		P[i].CalcAngle(P[1]);
	sort(P+2,P+N+1);
#ifdef Debug
	for(int i=2;i<=N;i++)
		printf("%d ",P[i].id);
	puts("");
#endif
	printf("%d %d\n",P[1].id,P[N/2+1].id);
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