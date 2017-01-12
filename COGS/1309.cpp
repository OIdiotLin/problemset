#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

int N;
stack<int> s;
vector<int> G[MAXN];

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("cow.in","r",stdin);
	freopen("cow.out","w",stdout);
	#endif
	cin>>N;
}

void work(){
	
}

int main()
{
	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

