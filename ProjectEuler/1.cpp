#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

void work()
{
	int Sum=0;
	for(int i=1;i<1000;i++)
	{
		if(i%3==0 || i%5==0)
			Sum+=i;
	}
	cout<<Sum<<endl;
}

int main()
{
	work();
	return 0;
}

