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
#define MAXN (1005)
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

struct Matrix{
	int m,n;
	int a[MAXN][MAXN];
	Matrix(int _m=0,int _n=0):
		m(_m),n(_n){memset(a,0,sizeof(a));}
	Matrix operator * (const Matrix	&t) const{
		Matrix res=Matrix(m,t.n);
		for(int i=1;i<=res.m;i++)
			for(int j=1;j<=res.n;j++)
				for(int k=1;k<=n;k++)
					res.a[i][j]+=a[i][k]*t.a[k][j];
		return res;
	}
	bool operator == (const Matrix &t) const{
		for(int i=1;i<=m;i++)
			if(a[i][1]!=t.a[i][1])
				return false;
		return true;
	}
	void Init_Ran(int len){
		m=len,n=1;
		for(int i=1;i<=m;i++)
			a[i][1]=rand()%1000;
	}
	void get(){
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				read(a[i][j]);
	}
}A,B,C,ran,d1,d2;

int N;

void init(){
#ifdef Judge
	freopen("2396.in","r",stdin);
	freopen("2396.out","w",stdout);
//	SpeedUp;
#endif
	ran.Init_Ran(MAXN-1);
}

void work(){
	A=Matrix(N,N),A.get();
	B=Matrix(N,N),B.get();
	C=Matrix(N,N),C.get();
	d1=A*ran;
	d1=B*d1;
	d2=C*ran;
	puts(d1==d2 ? "Yes" : "No");
}

int main(){
	init();
	while(scanf("%d",&N)!=EOF){
		work();
	}
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}