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

int N,M;
int cost,cnt;
int Dr[MAXN],Kn[MAXN];

void init(){
	#ifdef Judge
	freopen("11292.in","r",stdin);
	freopen("11292.out","w",stdout);
//	SpeedUp;
	#endif
	while(true){
		read(N),read(M);
		cost=0;cnt=1;
		if(!N && !M) return;
		for(int i=1;i<=N;i++) read(Dr[i]);
		for(int i=1;i<=M;i++) read(Kn[i]);
		sort(Dr+1,Dr+1+N);
		sort(Kn+1,Kn+1+M);
		for(int i=1;i<=M&&cnt<=N;i++)
			if(Kn[i]>=Dr[cnt])
				cost+=Kn[i],cnt++;
		if(cnt>N) print(cost);
		else cout<<"Loowater is doomed!"<<endl;
	}
}

int main(){
	init();
	#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
	#endif
	return 0;
}