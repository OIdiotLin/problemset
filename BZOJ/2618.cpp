/*
	Machine: Class4_B2
	System: Ubuntu_Kylin 14.10
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (1005)
#define INF (1<<30)
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
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()
#define sqr(x)	((x)*(x))

struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y):
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
}P[MAXN];
inline double len(const Point &v){
	return sqrt(v*v);
}

struct Segment{
	Point s,t;
	double k;
	Segment(){}
	Segment(Point _s,Point _t):
		s(_s),t(_t){k=atan2(t.y-s.y,t.x-s.x);}
	bool operator < (const Segment &T) const{
		return k!=T.k ? k<T.k : ((t-s)^(T.t-s))>0;
	}
};
inline Point Inter(const Segment &u,const Segment &v){
	double k1,k2,t;
	k1=(v.t-u.s)^(u.t-u.s);
	k2=(u.t-u.s)^(v.s-u.s);
	t=k1/(k1+k2);
	return v.t+(v.s-v.t)*t;
}

vector<Segment> L;
vector<Segment>::iterator it;
vector<Point> I;
vector<Point>::iterator it2;
int N;

void init(){
#ifdef Judge
	freopen("2618.in","r",stdin);
	freopen("2618.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
		int m=getint();
		for(int j=1;j<=m;j++)
			read(P[j].x),read(P[j].y);
		P[m+1]=P[1];
		for(int j=1;j<=m;j++){
			Segment tmp=Segment(P[j],P[j+1]);
			L.push_back(tmp);
		}
	}
	sort(L.begin(),L.end());
}

inline bool chk(const Segment &r1,const Segment &r2,const Segment &r3){
	Point p=Inter(r1,r2);
	return ((r3.t-r3.s)^(p-r3.s))<0;
}

void HPI(){
	static Segment Q[MAXN];
	register int head=1,tail=0;
	int k=-1;
	for(it=L.begin();it!=L.end();++it){
		if(it==L.begin() || it->k!=(it-1)->k)	k++;
		L[k]=*it;
	}
//	for(it=L.begin();it!=L.end();it++)
//		fprintf(stderr,"(%lf,%lf)->(%lf,%lf)\n",it->s.x,it->s.y,it->t.x,it->t.y);
	L.resize(k);
//	fprintf(stderr,"-----------\n");
//	for(it=L.begin();it!=L.end();it++)
//		fprintf(stderr,"(%lf,%lf)->(%lf,%lf)\n",it->s.x,it->s.y,it->t.x,it->t.y);
	Q[++tail]=L[0],Q[++tail]=L[1];
	for(it=L.begin()+2;it!=L.end();it++){
		while(head<tail && chk(Q[tail-1],Q[tail],*it))	tail--;
		while(head<tail && chk(Q[head+1],Q[head],*it))	head++;
		Q[++tail]=*it;
	}
	while(head<tail && chk(Q[tail-1],Q[tail],Q[head]))	tail--;
	while(head<tail && chk(Q[head-1],Q[head],Q[tail]))	head++;
	Q[++tail]=Q[head];
	for(int i=head;i<tail;i++){
		I.push_back(Inter(Q[i],Q[i+1]));
		fprintf(stderr,"(%lf,%lf)\n",(I.end()-1)->x,(I.end()-1)->y);
	}
}

void work(){
	double S=0;
	HPI();
	I.push_back(I[0]);
	for(it2=I.begin();it2!=I.end()-1;it2++)
		S+=(*it2)^(*(it2+1));
	printf("%.3lf\n",fabs(S/2));
}

int main(){
	init();
	work();
//#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(L)+sizeof(I)+sizeof(P))/1048576<<" MB."<<endl;
//#endif
	return 0;
}
