#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

typedef long long LL;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

LL GetLen(LL x){
	int cnt=1;
	while(x!=1){
		(x%2==0) ? (x>>=1) : x=3*x+1;
		cnt++;
	}
	return cnt;
}

void work()
{
	LL MAX=-INF,Ans;
	for(LL i=1;i<=1000000;i++){
		if(MAX<GetLen(i)){
			MAX=GetLen(i);
			Ans=i;
		}
	}
	cout<<MAX<<"\t"<<Ans<<endl;
}

int  main()
{
	work();
	return 0;
}

