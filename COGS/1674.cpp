#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

struct cmp{
	bool operator ()(int a,int b)
	{
		return a>b;
	}
};

priority_queue <int,vector<int>,cmp> Q;
int N;

void init()
{
	int a;
	#ifdef FILE
	SpeedUp;
	freopen("testled.in","r",stdin);
	freopen("testled.out","w",stdout);
	#endif
	cin>>N;
}

int main()
{
	init();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

