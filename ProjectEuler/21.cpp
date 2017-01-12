#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

const int N=9999;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

int d(int x){
	int ret=0;
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			ret+=(i+x/i);
		}
		if(i*i==x)
			ret-=i;
	}
	return ret-x;
}

void work(){
	long long Sum=0;
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++)
			if(d(i)==j && d(j)==i)
				Sum+=i+j;
	}
	cout<<Sum<<endl;
}

int main()
{
	work();
	cout<<(double)clock()/(double)CLOCKS_PER_SEC<<endl;
	return 0;
}

