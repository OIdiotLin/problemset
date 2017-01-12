/*
	System: Windows7 32bit
	Machine: Class4_B2
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN ()
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

int N,M;
int f[100][100];

void init(){
	#ifdef Judge
	SpeedUp;
	freopen("horse.in","r",stdin);
	freopen("horse.out","w",stdout);
	#endif
	cin>>M>>N;
}

int dfs(int i,int j){
	if(i<1||j<1||i>M||j>N) return 0;
	if(i==1 && j==1) return 1;
	if(f[i][j]) return f[i][j];
	return f[i][j]=dfs(i-2,j-1)+dfs(i+2,j-1)+dfs(i-1,j-2)+dfs(i+1,j-2);
}

int main(){
	init();
	cout<<dfs(M,N)<<endl;
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof())/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

