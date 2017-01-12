#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cmath>
#define MAXN 
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

int N,t;
set<int> S;

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N;
	t=(int)sqrt(N);
}

void work(){
	for(int a=1;a<=t;a++){
		if(N%a==0){
			int b=N/a;
			for(int x=1;x<=N;x+=b)
				if((x+1)%a==0)
					S.insert(x);
			for(int x=b-1;x<=N;x+=b)
				if((x-1)%a==0)
					S.insert(x);
		}
	}
	while(S.size()){
		cout<<*S.begin()<<endl;
		S.erase(S.begin());
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

