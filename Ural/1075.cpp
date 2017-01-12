#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN ()
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

inline double sqr(double X){
	return X*X;
}
struct Point {
	double x,y,z;
	void read(){
		cin>>x>>y>>z;
	}
}A,B,C;
inline double dist(Point P1,Point P2){
	return sqrt(sqr(fabs(P1.x-P2.x))+sqr(fabs(P1.y-P2.y))+sqr(fabs(P1.z-P2.z)));
}
double r;
double dAB,dAC,dBC;
double a,b,c;

void work(){
	#ifdef Judge
	SpeedUp;
	freopen("1075.in","r",stdin);
	freopen("1075.out","w",stdout);
	#endif
	A.read();B.read();C.read();cin>>r;
	dAB=dist(A,B),dAC=dist(A,C),dBC=dist(B,C);
	a=acos(r/dAC);b=acos(r/dBC);
	c=acos((sqr(dAC)+sqr(dBC)-sqr(dAB))/(2*dAC*dBC));
	if(a+b>=c){
		cout<<fixed<<setprecision(2)<<dAB<<endl;		//Not cross .
	}else{
		double dAD=sqrt(sqr(dAC)-sqr(r)),dBE=sqrt(sqr(dBC)-sqr(r));
		double arDE=(c-a-b)*r;
		cout<<fixed<<setprecision(2)<<dAD+dBE+arDE<<endl;
	}
}

int main(){
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}


