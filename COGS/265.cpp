#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 200000
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

struct SegNode{
	int L,R;
	int cnt,cover;
	SegNode *l,*r;
	int Llen(const SegNode *)
}T[MAXN];

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("xdfg.in","r",stdin);
	freopen("xdfg.out","w",stdout);
	#endif
	cin>>L>>N;
	
}

int main()
{
	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

