/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iomanip>
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
#define MAXN (300001)
#define INF (1050)
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-7;

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

int N;
double f[MAXN];

void init(){
#ifdef Judge
	freopen("1066.in","r",stdin);
	freopen("1066.out","w",stdout);
	SpeedUp;
#endif
	cin>>N>>f[1];
}

inline bool chk(double x){
	f[2]=x;
	for(int i=3;i<=N;i++){
		f[i]=f[i-1]*2-f[i-2]+2;
		if(f[i]<0) return false;
	}
	return true;
}

void work(){
	double l=0,r=f[1];
	while(r-l>eps){
		double mid=(l+r)/2;
		chk(mid) ? r=mid : l=mid;
	}
	cout<<fixed<<setprecision(2)<<f[N];
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