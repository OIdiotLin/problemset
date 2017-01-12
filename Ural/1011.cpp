#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

double p,q;
LL Ans,Min,Max;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>p>>q;
	Min=1;
	while(Min>=Max){
		Min=(LL)(Ans*p*100)/10000+1;
		Max=(LL)(Ans*q*100)/10000;
		if((LL)(Ans*q*100)%10000!=0)
			Max++;
		Ans++;
	}
	cout<<Ans-1<<endl;
}

int main()
{
	init();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

