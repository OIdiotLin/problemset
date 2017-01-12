#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
}

int SqrSgm(int N){
	return (N*(N+1)/2)*(N*(N+1)/2);
}

int SgmSqr(int N){
	return (N*(N+1)*(2*N+1))/6;
}

int main()
{
	cout<<SqrSgm(100)-SgmSqr(100)<<endl;
	return 0;
}

