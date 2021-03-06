﻿/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (10005)
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

int N,T;
int A[MAXN];

void init(){
#ifdef Judge
	freopen("2124.in","r",stdin);
	freopen("2124.out","w",stdout);
//	SpeedUp;
#endif
	read(T);
}

inline bool chk_bits(){
	bitset<MAXN> pre,suf;
	static bitset<MAXN> tmp;
	for(int i=1;i<=N;i++) suf[i]=1;
	for(int i=1;i<=N;i++){
		suf[A[i]]=0;
		if(i!=1) pre[N-A[i-1]+1]=1;
		tmp=(suf>>A[i])&(pre>>(N-A[i]+1));
		if(tmp.any()) return true;
	}
	return false;
}

void work(){
	read(N);
	for(int i=1;i<=N;i++)
		read(A[i]);
	if(chk_bits()){puts("Y");return;}
	reverse(A+1,A+N+1);
	if(chk_bits()){puts("Y");return;}
	puts("N");
}

int main(){
	init();
	while(T--)
		work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}