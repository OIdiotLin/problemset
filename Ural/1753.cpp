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

double h,H,L;

void init(){
#ifdef Judge
	freopen("1753.in","r",stdin);
	freopen("1753.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%lf%lf%lf",&h,&H,&L);
	H=H/2;
}

#define sqr(x) ((x)*(x))
inline double f(double x){
	return x*H/sqrt(sqr(x)+sqr(h))-x;
}

void work(){
	double l=eps,r=min(sqrt(sqr(H)-sqr(h)),L);
	while(r-l>eps){
		double m1=(l+r)/2,m2=(l+m1)/2;
		f(m1)>f(m2) ? l=m2 : r=m1;
	}
	printf("%.6lf",f(l));
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