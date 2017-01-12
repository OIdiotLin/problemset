#include <iostream>
#include <cstdio>
#define FILE
using namespace std;

int main()
{
	#ifdef FILE
	freopen("aplusb.in","r",stdin);
	freopen("aplusb.out","w",stdout);
	#endif
	
	double a,b;
	cin>>a>>b;
	cout<<(int)(a+b)<<endl;
	return 0;
}
