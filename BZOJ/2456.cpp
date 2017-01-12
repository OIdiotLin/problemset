#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;
typedef long long LL;

int N;
void init()
{
	#ifdef FILE
	SpeedUp;
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	scanf("%d",&N);
}

void work(){
	int cnt=0,tmp;
	int r;
	for(int i=1;i<=N;i++){
		scanf("%d",&r);
		if(cnt==0){
			cnt=1;
			tmp=r;
		}
		else if(tmp!=r) cnt--;
		else cnt++;
	}
	printf("%d\n",tmp);
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(N))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

