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
#define MAXN (1005)
#define INF (1<<28)
const double PI=acos(-1);
const int ZCY=1000000007;

struct Task{
	int t,s;
	void read(){
		cin>>t>>s;
	}
	bool operator < (const Task&b)const{
		return s>b.s;
	}
}A[MAXN];
int N;

void init(){
	#ifdef Judge
	freopen("2591.in","r",stdin);
	freopen("2591.out","w",stdout);
	SpeedUp;
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		A[i].read();
	sort(A+1,A+N+1);
}

void work(){
	int Ans=INF;
	for(int i=1;i<=N;i++)
		Ans=min(Ans,A[i].s)-A[i].t;
	cout<<(Ans>=0 ? Ans : -1)<<endl;
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