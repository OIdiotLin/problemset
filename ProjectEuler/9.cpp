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

void work(){
	for(int i=1;i<1000;i++)
		for(int j=501-i;j<1000;j++)
		{
			if(i*i+j*j==(1000-i-j)*(1000-i-j))
			{
				cout<<i*j*(1000-i-j)<<endl;
				return;
			}
		}
}

int main()
{
	work();
	return 0;
}

