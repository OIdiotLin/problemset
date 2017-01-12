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
#define MAXN (100005)
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
	return fabs(x-y)<eps && fabs(y-x)<eps;
}

struct Point{
	double x,y;
	Point(double _x=0,double _y=0):
		x(_x),y(_y){}
	Point operator * (const double &k) const{
		return Point(x*k,y*k);
	}
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
	bool operator == (const Point &v) const{
		return equal(x,v.x) && equal(y,v.y);
	}
}P[MAXN];

struct Angle{
	double crsprod,dotprod;
	Angle(double _cp=0,double _dp=0):
		crsprod(_cp),dotprod(_dp){}
	bool operator == (const Angle &a) const{
		return equal(crsprod,a.crsprod) && equal(dotprod,a.dotprod);
	}
}S[MAXN<<2];

int p[MAXN<<2];
int N;

void init(){
	memset(P,0,sizeof(P));
	memset(S,0,sizeof(S));
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%lf%lf",&P[i].x,&P[i].y);
	P[0]=P[N],P[N+1]=P[1];
	for(int i=1;i<=N;i++){
		S[(i<<1)-1].crsprod=(P[i-1]-P[i])^(P[i+1]-P[i]);
		S[(i<<1)-1].dotprod=(P[i-1]-P[i])*(P[i+1]-P[i]);
		S[(i<<1)-1+(N<<1)]=S[(i<<1)-1];
	}
}

void Manacher(){
	int len=(N<<2)-1;
	int mx=1,cur=1,id=1;
	p[1]=1;
	while(cur<=len){
		p[cur]= mx>cur ? min(p[(id<<1)-cur],mx-cur) : 1;
		while(S[cur+p[cur]]==S[cur-p[cur]])	p[cur]++;
		if(cur+p[cur]>mx)
			mx=cur+p[cur],id=cur;
		cur++;
	}
}

void work(){
	int Ans=0;
	init();
	Manacher();
	int whole=((N&1) ? N : N-1);
	for(int i=N+1;i<=3*N;i++)
		if(p[i]>=whole)
			Ans++;
	printf("%d\n",Ans>>1);
}

int main(){
	int T;
#ifdef Judge
	freopen("1100.in","r",stdin);
	freopen("1100.out","w",stdout);
//	SpeedUp;
#endif
//	scanf("%d",&T);
	while(T--)
		work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}