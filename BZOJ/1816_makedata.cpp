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

void init()
{
	SpeedUp;
	#ifdef FILE
//	freopen(".in","r",stdin);
	freopen("1816.in","w",stdout);
	#endif
	srand(time(NULL));
}

double random(){
	return rand()/RAND_MAX;
}
LL random(LL Lim){
	return (LL)random()*Lim;
}

void work(){
	int N=random(48)+1;
	cout<<N<<" "<<random(500000000)+1<<endl;
	for(int i=1;i<=N;i++){
		cout<<random(500000000)+1<<" ";
	}
	cout<<endl;
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

