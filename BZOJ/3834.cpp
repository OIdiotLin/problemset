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

int T;

void init(){
#ifdef Judge
	freopen("3834.in","r",stdin);
	freopen("3834.out","w",stdout);
//	SpeedUp;
#endif
	read(T);
}

void work(){
	int l1,l2,r1,r2;
	read(l1),read(r1),read(l2),read(r2);
	int Ans=1,last;
	for(int i=1;i<=min(r1,r2);i=last+1){
		last=min(r1/(r1/i),r2/(r2/i));
		if(r1/last>(l1-1)/last && r2/last>(l2-1)/last)
			Ans=max(Ans,last);
	}
	print(Ans);
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