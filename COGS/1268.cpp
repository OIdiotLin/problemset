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
typedef long long LL;

int N;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	#endif
	cin>>N;
}

void work(){
	for(int i=2;i<=50000;i++){
		if(N%i==0){
			cout<<N/i<<endl;
			break;
		}
	}
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

