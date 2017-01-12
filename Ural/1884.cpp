/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (10010)
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

const int lCar=5;
const double vCar=20/3.6;
bool L[MAXN],R[MAXN];
int N;

void init(){
	int x;
#ifdef Judge
	freopen("1884.in","r",stdin);
	freopen("1884.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;++i){
		read(x);
		for(int t=0;t<lCar;++t)
			L[x+t]=true;
	}
	read(N);
	for(int i=1;i<=N;++i){
		read(x);
		for(int t=0;t<lCar;++t)
			R[x+t]=true;
	}
}

void work(){
	for(int i=0;i!=MAXN;++i){
		bool flag=false;
		for(int j=0;j<8;++j)
			if(L[i+j] || R[i+j+8])
				flag=true;
		if(!flag){
			cout<<fixed<<setprecision(6)<<(double)i/vCar<<endl;
			return;
		}
	}
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