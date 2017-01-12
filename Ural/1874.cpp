/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
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

double a,b;

void init(){
#ifdef Judge
	freopen("1874.in","r",stdin);
	freopen("1874.out","w",stdout);
	SpeedUp;
#endif
	cin>>a>>b;
}

inline double S(double c){
	double p=(a+b+c)/2.0;
	return sqrt(p*(p-a)*(p-b)*(p-c))+c*c/4;
}

void work(){
	double l=0,r=a+b;
	while(r-l>eps){
		double mid1=(l+r)/2;
		double mid2=(mid1+r)/2;
		S(mid1)>S(mid2) ? r=mid2 : l=mid1;
	}
	cout<<fixed<<setprecision(9)<<S(l)<<endl;
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