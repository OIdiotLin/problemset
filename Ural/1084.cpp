#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define MAXN ()
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

const double Pi=acos(-1);

inline double sqr(double x){
	return x*x;
}
inline bool equal(double a,double b){
	return fabs(a-b)<0.000001;
}

int A,R;

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>A>>R;
}

double Calc(int a,int r){
	if(a>=(r<<1)) return (double)sqr(r)*Pi;
	if(r>sqrt(sqr(a/2.0)*2) || equal(r,sqrt(sqr(a/2.0)))) return (double)sqr(a);
	
	double x=sqrt(sqr(r)-sqr(a)/4.0);
	double A=x*a/2.0;
//	double angle=Pi/2-2*atan(x/a/2.0);
	double angle=Pi/2-2*asin(x/r);
	double B=Pi*sqr(r)*(angle/(2*Pi));
	return (A+B)*4.0;
}

int main(){
	init();
	cout<<fixed<<setprecision(3)<<Calc(A,R)<<endl;
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

