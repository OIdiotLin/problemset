/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <stack>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (50005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Cow{
	int h,x,Ans;
	void Read(){
		read(h),read(x);
	}
}A[MAXN];
int N,Max;
stack<int> S;

void init(){
#ifdef Judge
	freopen("1657.in","r",stdin);
	freopen("1657.out","w",stdout);
	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++)
		A[i].Read();
}

void work(){
	for(int i=1;i<=N;i++){
		while(!S.empty() && A[i].h>A[S.top()].h) A[i].Ans+=A[S.top()].x,S.pop();
		S.push(i);
	}
	while(!S.empty())S.pop();
	for(int i=N;i;i--){
		while(!S.empty() && A[i].h>A[S.top()].h) A[i].Ans+=A[S.top()].x,S.pop();
		S.push(i);
	}
	while(!S.empty())S.pop();
	for(int i=1;i<=N;i++)
		Max=max(Max,A[i].Ans);
	print(Max);
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