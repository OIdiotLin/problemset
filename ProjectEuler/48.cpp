#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define EPS 10000000000
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

double f(int N,int K){
	double ret=1;
	while(K){
		ret*=N;
		if(ret>=EPS){
			ret=(LL)ret%EPS;
		}
		K--;
	}
	return ret;
}

int main()
{
	double Sum=0;
	for(int i=1;i<=1000;i++){
		Sum+=f(i,i);
	}
	cout<<(LL)Sum%EPS<<endl;
	return 0;
}

