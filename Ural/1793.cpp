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
//#define Judge
//#define Debug
#define MAXN (300001)
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

struct Plate{
	double r1,r2;
	inline void Read(){
		cin>>r1>>r2;
	}
}P1,P2;
double a,b,d,h;

void init(){
#ifdef Judge
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	SpeedUp;
#endif
	cin>>a>>b>>d;
	P1.Read();
	P2.Read();
	cin>>h;
}

#define sqr(x) ((x)*(x))
bool Check(){
	if(P1.r1*2>a || P1.r1>b || P2.r1>a || P2.r1>b) 
		return false;
	if(h>d){
		double dr=P1.r2-P1.r1,dh=h-d;
		a+=dr*dh/h,b+=dr*dh/h;
		dr=P2.r2-P2.r1;
		a+=dr*dh/h,b+=dr*dh/h;
	}
	if(P1.r2*2>a || P1.r2>b || P2.r2>a || P2.r2>b)
		return false;
	double dr=a-P1.r2-P2.r2,dR=b-P1.r2-P2.r2;
	if(sqrt(sqr(dr)+sqr(dR))<P1.r2+P2.r2)
		return false;
	return true;
}

void work(){
	cout<<(Check() ? "YES" : "NO")<<endl;
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