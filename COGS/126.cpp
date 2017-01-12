#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#define MAXN 510
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int N,Sum;
int A[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("stats.in","r",stdin);
	freopen("stats.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
		Sum+=A[i];
	}
	sort(A+1,A+N+1);
	#ifdef Debug
	for(int i=1;i<=N;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	cout<<"Sum = "<<Sum<<endl;
	#endif
}

void work()
{
	cout<<fixed<<setprecision(6)<<(double)(Sum)/N<<endl;
	if(N%2==0)
	{
		cout<<fixed<<setprecision(6)<<((double)(A[N>>1]+A[(N>>1)+1])/2.0)<<endl;
	}
	else
	{
		cout<<fixed<<setprecision(6)<<(double)A[(N>>1)+1]<<endl;
	}
}

int main()
{
	init();
	work();
	return 0;
}

