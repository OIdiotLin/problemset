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
const double eps=1e-4;

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
#define sqr(x) ((x)*(x))

void init(){
	double a1,a2,b1,b2;
#ifdef Judge
	freopen("1294.in","r",stdin);
	freopen("1294.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2);
	double t1=a1*b1,t2=a2*b2;
	double ans=(t1*(sqr(a2)+sqr(b2))-t2*(sqr(a1)+sqr(b1)))/(t1-t2);
	if(a1*b1-a2*b2==0) {
		printf("Impossible.\n");
		return;
	}
	if(ans<0) {
		printf("Impossible.\n");
		return;
	}
	ans=1000*sqrt(fabs(ans));
	printf("Distance is %.0f km.\n",ans);
}

int main(){
	init();
//	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}