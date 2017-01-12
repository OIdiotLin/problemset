/*
	Machine: Class4_B2
	System: Ubuntu_Kylin 14.10
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (1005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

inline LL getint(){
	LL x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()
#define sqr(x)	((x)*(x))

inline LL qPow(LL x,LL k){
	LL res=1;
	while(k){
		if(k&1)	res=res*x%ZCY;
		k>>=1;
		x=x*x%ZCY;
	}
	return res;
}

LL fac[MAXN],inv[MAXN];
LL N,M;
LL f[MAXN];

inline int coef(int x){
	return x&1 ? -1 : 1;
}

inline LL C(LL n,LL m){
	return fac[n]*inv[m]%ZCY*inv[n-m]%ZCY;
}

bool init(){
#ifdef Judge
	freopen("3157.in","r",stdin);
	freopen("3157.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	if(M==1){
		print((N*(N+1)>>1)%ZCY);
		return false;
	}
	fac[0]=1;
	for(int i=1;i<=M;i++)
		fac[i]=i*fac[i-1]%ZCY;
	inv[M]=qPow(fac[M],ZCY-2);
	inv[0]=1;
	for(int i=M-1;i;i--)
		inv[i]=inv[i+1]*(i+1)%ZCY;
	return true;
}

void work(){
	f[0]=((qPow(M,N+1)-M)%ZCY+ZCY)%ZCY*qPow(M-1,ZCY-2);
	for(int i=1;i<=M;i++){
		f[i]=qPow(N,i)*qPow(M,N+1)%ZCY;
		for(int j=0;j<=i-1;j++)
			f[i]=((f[i]+coef(i-j)*C(i,j)*f[j])%ZCY+ZCY)%ZCY;
		f[i]=f[i]*qPow(M-1,ZCY-2)%ZCY;
	}
	print(f[M]);
}

int main(){
	if(init()) work();
//#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(inv)*3)/1048576<<" MB."<<endl;
//#endif
	return 0;
}
