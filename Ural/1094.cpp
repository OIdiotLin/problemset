#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN (100010)
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
using namespace std;
typedef long long LL;

char st[MAXN],t[120];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	for(int i=0;i<MAXN;i++)
		t[i]=' ';
	cin.getline(t,MAXN);
}

int main(){
	
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

