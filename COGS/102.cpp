#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define eps 0.00001
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

double H,S1,V,L,K,N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("freefaller.in","r",stdin);
	freopen("freefaller.out","w",stdout);
	#endif
	cin>>H>>S1>>V>>L>>K>>N;
}

int Cal(double h,double s,double v,double l,double k,double n)
{
	int Catch_Ball=0;
	double Dota,LoL;
	Dota=s-v*sqrt((h-k)*0.2);
	LoL=Dota+1;
	Dota=s-v*sqrt(h*0.2);
	for(int i=0;i<n;i++)
		if(i<=LoL+eps && i>=Dota-eps)
			Catch_Ball++;
	return Catch_Ball;
}

void work()
{
	init();
	cout<<Cal(H,S1,V,L,K,N)<<endl;
}

int main()
{
	work();
	return 0;
}
