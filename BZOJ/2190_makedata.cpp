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
	freopen("2190.in","w",stdout);
	#endif
	srand(time(0));
}

double random(){
	return (double)rand()/(double)RAND_MAX;
}
int random(int Lim){
	return random()*Lim;
}


int main()
{
	init();
	cout<<random(39999)+1<<endl;
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<()/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

