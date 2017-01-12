#include <iostream>
#include <iomanip>
#include <cstdio>
#define FILE
using namespace std;

int N;
double S=0;

void init()
{
	#ifdef FILE
	freopen("dog.in","r",stdin);
	freopen("dog.out","w",stdout);
	#endif
	
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		double a,b;
		cin>>a>>b;
		S+=a*b/10;
	}
}

int main()
{
	init();
	cout<<fixed<<setprecision(2)<<S<<endl;
	return 0;
}
