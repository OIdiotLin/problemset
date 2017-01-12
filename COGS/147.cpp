#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

int N,P,K;


void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("phoneline.in","r",stdin);
	freopen("phoneline.out","w",stdout);
	#endif
	cin>>N>>P>>K;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			m[i][j]=INF;
	for(int i=1;i<=)
}

int main()
{
	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

