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
#define MAXN (600005)
#define INF (1e12)
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-9;

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
	bool operator < (const Point &v) const{
		return equal(x,v.x) ? y<v.y : x<v.x;
	}
}ConvexHull[MAXN][2],P[MAXN];


struct Operate{
	int type;		// 0: Adding New Point , 1: Query a Point
	Point p;
	Operate(){}
}Q[MAXN];

bool Ans[MAXN];
int N,top1,top0;

void init(){
	bool flag=false;
#ifdef Judge
	freopen("2961.in","r",stdin);
	freopen("2961.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d%lf%lf",&Q[i].type,&Q[i].p.x,&Q[i].p.y);
		if(Q[i].type==0)	flag=true;
		else Ans[i]=flag;
	}
}

void GetAns(int i){
	Point find,p=Q[i].p;
	if(p.y>0){
		int l=1,r=top0;
		while(l<=r){
			int mid=(l+r)>>1;
			p*(ConvexHull[mid][0]-ConvexHull[mid+1][0])<eps ? r=mid-1,find=ConvexHull[mid][0] : l=mid+1;
		}
	}
	else{
		int l=1,r=top1;
		while(l<=r){
			int mid=(l+r)>>1;
			p*(ConvexHull[mid+1][1]-ConvexHull[mid][1])>-eps ? r=mid-1,find=ConvexHull[mid][1] : l=mid+1;
		}
	}
	if((p*find)*2<p*p+eps)
		Ans[i]=0;
}

void Solve(int l,int r){ 
	if(l==r)	return;
	int mid=(l+r)>>1;
	Solve(l,mid);
	Solve(mid+1,r);
	
	int tot=0;
	top0=top1=0;
	for(int i=l;i<=mid;i++)
		if(Q[i].type==0)
			P[++tot]=Q[i].p;
	sort(P+1,P+tot+1);
	for(int i=tot;i;i--){
		while(top0>=2 && ((ConvexHull[top0][0]-ConvexHull[top0-1][0])^(P[i]-ConvexHull[top0][0]))>-eps)	top0--;
		ConvexHull[++top0][0]=P[i];
	}
	for(int i=1;i<=tot;i++){
		while(top1>=2 && ((ConvexHull[top1][1]-ConvexHull[top1-1][1])^(P[i]-ConvexHull[top1][1]))>-eps) top1--;
		ConvexHull[++top1][1]=P[i];
	}
	ConvexHull[top1+1][1].x=ConvexHull[top1][1].x+eps;
	ConvexHull[top1+1][1].y=-INF;
	ConvexHull[top0+1][0].x=ConvexHull[top0][0].x-eps;
	ConvexHull[top0+1][0].y=INF;
	for(int i=mid+1;i<=r;i++)
		if(Q[i].type)
			if(Ans[i])		//Refresh
				GetAns(i);
}

void work(){
	Solve(1,N);
	for(int i=1;i<=N;i++)
		if(Q[i].type)
			puts(Ans[i]?"Yes":"No");
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