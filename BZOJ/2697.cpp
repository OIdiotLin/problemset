﻿/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
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
#define MAXN (305)
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

int N,K;
int A[MAXN];
inline bool cmp(int a,int b){
	return a>b;
}

void init(){
	#ifdef Judge
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	SpeedUp;
	#endif
	read(N),read(K);
	for(int i=1;i<=K;i++)
		read(A[i]);
	sort(A+1,A+K+1,cmp);
}

void work(){
	int Ans=0;
	for(int i=1,l=1,r=N;i<=K && l<r;i++,l++,r--)
		Ans+=(r-l)*A[i];
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