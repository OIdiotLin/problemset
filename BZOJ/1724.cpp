﻿/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (300001)
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
inline void outputLL(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputLL(x)
#define read(x) x=getint()

int N;
LL Ans;
priority_queue<LL,vector<LL>,greater<LL> > Q;

void init(){
	int r;
#ifdef Judge
	freopen("1724.in","r",stdin);
	freopen("1724.out","w",stdout);
	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
		read(r);
		Q.push(r);
	}
}

void work(){
	for(int i=1;i<N;i++){
		int x=Q.top(); Q.pop();
		int y=Q.top(); Q.pop();
		Ans+=x+y;
		Q.push(x+y);
	}
	print(Ans);
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