#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

bool isP(LL x){
//	cout<<"Judge "<<x<<endl;
	for(LL i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

int main()
{
	LL Sum=5;
	cout<<isP(4)<<endl;
	for(LL i=4;i<=2000000;i++){
		if(isP(i))
		{
			Sum+=i;
//			cout<<Sum<<endl;
		}
	}
	cout<<Sum<<endl;
	return 0;
}

