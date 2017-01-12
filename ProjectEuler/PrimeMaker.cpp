#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

const int N=20000000;

void init()
{
	SpeedUp;
	#ifdef FILE
//	freopen(".in","r",stdin);
	freopen("Primes.txt","w",stdout);
	#endif
}

bool isPrime(int x)
{
	for(int i=2;i*i<=x;i++){
		if(x%i==0)
			return false;
	}
	return true;
}

void work()
{
	cout<<2<<" ";
	int cnt=1;
	for(int i=3;i<=N;i++){
		if(isPrime(i))
		{
			cout<<i<<" ";
			cnt++;
			if(cnt%50==0)
			{
			cout<<endl;
			}
		}
		
	}
	cout<<endl<<cnt<<endl;
}

int main()
{
	init();
	work();
	return 0;
}

