#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXM 50003
#define MAXN 20003
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

struct Edge{
	int v,next;
}E[MAXN<<1];
int v[MAXN];

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("hideseek.in","r",stdin);
	freopen("hideseek.out","w",stdout);
	#endif
}

queue<int> Q;
void spfa(){
	
}

int main()
{
	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

