/*
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
#define MAXN (10005)
#define INF (1<<28)
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

int f[MAXN],L[MAXN];
int l[MAXN],c[MAXN];
int N,S,T;

void init(){
#ifdef Judge
	freopen("1031.in","r",stdin);
	freopen("1031.out","w",stdout);
//	SpeedUp;
#endif
	for(int i=1;i<=3;i++) read(l[i]);
	for(int i=1;i<=3;i++) read(c[i]);
	read(N),read(S),read(T);
	if(S>T) swap(S,T);
	for(int i=2;i<=N;i++)
		read(L[i]);
}

void DP(){
	for(int i=S+1;i<=T;i++){
		f[i]=INF;
		for(int j=i-1;j>=S;j--){
			int d=L[i]-L[j];
			if(d>l[3]) break;
			for(int k=1;k<=3;k++)
				if(d<=l[k]){
					f[i]=min(f[i],f[j]+c[k]);
					break;
				}
		}
	}
}

void work(){
	DP();
	print(f[T]);
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