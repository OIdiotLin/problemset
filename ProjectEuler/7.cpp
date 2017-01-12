#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
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

bool is_Prime(int x){
	for(int i=2;i<=sqrt(x)+1;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

void work(){
	int cnt=0;
	for(int i=3;;i++)
	{
		if(is_Prime(i))
			cnt++;
		if(cnt==10000)
		{
			cout<<i<<endl;
			return;
		}
	}
}

int main()
{
	work();
	return 0;
}

