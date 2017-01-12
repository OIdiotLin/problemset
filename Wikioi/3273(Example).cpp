#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

const double pi=4.0*atan(1.0);

double xa,xb,ya,yb,ra,rb,n;

void init()
{
}

double qiucos(double a,double b,double c)
{
	return (a*a+b*b-c*c)/(2.0*a*b);
}

double sanjiao(double x,double y,double z)
{
	double p=(x+y+z)/2.0;
	return sqrt(p*(p-x)*(p-y)*(p-z));
}

double max(double a,double b)
{
    	if(a<=b) return b;
    	else return a;
}

double min(double a,double b)
{
    	if(a<=b) return a;
    	else return b;
}


void readdata()
{
	scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&ra,&xb,&yb,&rb);
	n=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
	if( n>=(ra+rb) )
	{
		printf("0.000");
		exit(0);
	}
	if( (max(ra,rb)-n) >= min(ra,rb))
	{
        printf("%.3lf",pi*min(ra,rb)*min(ra,rb));
        exit(0);
    	}
    	if(n<=max(ra,rb))
    	{
 		printf("%.3lf\n", (pi*min(ra,rb)*min(ra,rb)) - ( ((2.0*pi) - acos(qiucos(n,min(ra,rb),max(rb,ra)))*2.0)/(2.0*pi)*(pi*min(ra,rb)*min(ra,rb)) - ( (acos(qiucos(n,max(ra,rb),min(ra,rb)))*2.0)/(2.0*pi)*(pi*max(ra,rb)*max(ra,rb)) - (sanjiao(n,ra,rb)*2))) );
		exit(0);	
    	}
}

void work()
{
	double w=sanjiao(ra,rb,n)*2*2.0/n;
	printf("%.3lf", acos( qiucos(ra,ra,w) )/(2.0*pi)*(pi*ra*ra)+acos( qiucos(rb,rb,w) )/(2.0*pi)*(pi*rb*rb)-sanjiao(ra,rb,n)*2 );
}

int main()
{
	init();
	readdata();
	work();
	return 0;
}
