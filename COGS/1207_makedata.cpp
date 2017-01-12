#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
typedef long long LL;

double random(){
	return ((double)rand())/RAND_MAX;
}
LL random(LL Lim){
	return (LL)random()*Lim;
}

void init()
{
	#ifdef FILE
	SpeedUp;
	freopen("pasture.in","w",stdout);
	#endif
	
}

int main()
{
	init();
	srand(time(NULL));
	int N=random(37)+3;
	cout<<N<<endl;
	for(int i=1;i<=N;i++){
		cout<<random(40)<<endl;
	}
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

