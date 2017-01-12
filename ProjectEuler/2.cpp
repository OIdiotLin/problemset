#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

const int N=4000000;
int S=2;

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
	int a=1,b=2;
	for(int i=3;i<=N;)
	{		
		if(i%2==0)
			S+=i;
		a=i;
		i=a+b;
		b=a;
	}
}

int main()
{
	work();
	cout<<S<<endl;
	return 0;
}

