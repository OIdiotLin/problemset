#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct P{
	string s;
	int L;
	bool operator <(P b)const {
		return L<b.L;
	}
}S[4];


void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("A.in","r",stdin);
//	freopen(".out","w",stdout);
	#endif
	for(int i=0;i<4;i++){
		cin>>S[i].s;
		S[i].L=S[i].s.length()-2;
	}
	sort(S,S+4);
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

