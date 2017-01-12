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
#define MAXN (102)
#define INF ()
const double PI=acos(-1);
const int ZCY=9999973;

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

int N,M;
LL f[MAXN][MAXN][MAXN];

void init(){
	#ifdef Judge
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	SpeedUp;
	#endif
	read(N),read(M);
}

inline LL g(LL x){return (x*(x-1))>>1;}

void DP(){
	f[0][0][0]=1;
	for(int i=1;i<=N;i++)
		for(int j=0;j<=M;j++)
			for(int k=0;k<=M-j;k++){
				f[i][j][k]=f[i-1][j][k];
				if(j)
					f[i][j][k]+=f[i-1][j-1][k]*(M-j-k+1);
				if(j>1)
					f[i][j][k]+=f[i-1][j-2][k]*g(M-j-k+2);
				if(k&&j<M)
					f[i][j][k]+=f[i-1][j+1][k-1]*(j+1);
				if(j&&k)
					f[i][j][k]+=f[i-1][j][k-1]*(M-j-k+1)*j;
				if(k>1&&j<M-1)
					f[i][j][k]+=f[i-1][j+2][k-2]*g(j+2);
				f[i][j][k]%=ZCY;
			}
}

void work(){
	LL Ans=0;
	for(int i=0;i<=M;i++)
		for(int j=0;j<=M-i;j++)
			Ans+=f[N][i][j];
	print(Ans%ZCY);
}

int main(){
	init();
	DP();
	work();
	#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
	#endif
	return 0;
}