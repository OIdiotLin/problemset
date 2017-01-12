/*
	Work on OIdiot's PC
	System: Ubuntu 14.04 Kylin
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
//#define Judge
//#define Debug
#define MAXN (10005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

int A[MAXN];
LL S[MAXN];
int N;
LL Ans;

void init(){
	#ifdef Judge
	freopen("1616.in","r",stdin);
	freopen("1616.out","w",stdout);
	SpeedUp;
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	sort(A+1,A+N+1);
	for(int i=1;i<=N;i++)
		S[i]=S[i-1]+A[i];
}

void work(){
	for(int i=1;i<=N;i++)
		Ans+=(S[N]-S[i-1])-(LL)A[i]*(N-(i<<1)+1)-S[i];
	cout<<Ans<<endl;
}

int main(){
	init();
	work();
	#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
	#endif
	return 0;
}