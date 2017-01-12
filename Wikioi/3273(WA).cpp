#include <iostream>
#include <iomanip>
#include <cmath>
#define FILE

const double pi=4.0*atan(1.0);

using namespace std;
struct circle
{
	double x;
	double y;
	double r;
};

circle A,B;
double dist,shit1,shit2,fuck1,fuck2;

void input(circle *cir)
{
	cin>>cir->x>>cir->y>>cir->r;
}

void init()
{ 
	double temp=0;
	input(&A);
	input(&B);
	if(A.r<B.r)
		temp=A.r,B.r=A.r,A.x=temp;
}

void calculate()
{
	shit1=(A.r*A.r-B.r*B.r+dist*dist)/2/dist;
	shit2=sqrt(A.r*A.r-shit1*shit1);
	fuck1=A.r*A.r*pi*(asin(shit2/A.r)/pi)-shit2*shit1;
	fuck2=B.r*B.r*pi*(asin(shit2/B.r)/pi)-shit2*fabs(dist-shit1);
	if(shit1>dist)
		fuck2=B.r*B.r*pi-fuck2;
}

int main()
{
	#ifdef FILE
	freopen("3273.in","r",stdin);
	#endif
	init();
	dist=hypot(A.x-B.x,A.y-B.y);
	if(dist>=A.r+B.r)
	{
		cout<<"0.000"<<endl;
		return 0;
	}
	
	if(A.r>=A.r+dist)
	{
		cout<<fixed<<setprecision(3)<<pi*B.r*B.r<<endl;
		return 0;
	}
	
	calculate();
	cout<<fixed<<setprecision(3)<<fuck1+fuck2<<endl;
	return 0;
}
