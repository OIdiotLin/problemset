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
#define MAXN (105)
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

int C[MAXN];

struct Matrix{
	int m,n;
	LL a[MAXN][MAXN];
	
	Matrix(int _m=1,int _n=1):
		m(_m),n(_n){memset(a,0,sizeof(a));}
	
	Matrix operator * (const Matrix &b) const{
		Matrix res = Matrix(m,b.n);
		for(int i=0;i<res.m;i++)
			for(int j=0;j<res.n;j++)
				for(int k=0;k<n;k++)
					res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%ZCY;
		return res;
	}
	
	void Init_Unit(){
		int l=min(n,m);
		for(int i=0;i<l;i++)
			a[i][i]=1;
	}
	
	void Setsp(){
		m=n=101;
		for(int i=0;i<99;i++)
			a[i][i+1]=1;
		for(int i=0;i<100;i++)
			a[99][i]=a[100][i]=C[100-i];
		a[100][100]=1;
	}
}sp;

Matrix qPow(Matrix x,int k){
	Matrix res=Matrix(x.m,x.n);
	res.Init_Unit();
	while(k){
		if(k&1)	res=x*res;
		x=x*x;
		k>>=1;
	}
	return res;
}

int N,K;

void init(){
	int d;
#ifdef Judge
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(K);
	for(int i=1;i<=N;i++){
		read(d);
		C[d]++;
	}
}

void work(){
	sp.Setsp();
	Matrix ans=qPow(sp,K);
	print((ans.a[100][99]+ans.a[100][100])%ZCY);
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