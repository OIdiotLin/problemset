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

LL N,M;

struct Matrix{
	int m,n;	/* m*n */
	LL a[5][5];
	Matrix(int _m=0,int _n=0):
		m(_m),n(_n){memset(a,0,sizeof(a));}
	
	Matrix operator * (const Matrix & B)const{
		Matrix C=Matrix(m,B.n);
		for(int i=1;i<=C.m;i++)
			for(int j=1;j<=C.n;j++)
				for(int k=1;k<=n;k++)
					C.a[i][j]=(C.a[i][j]+(LL)a[i][k]*B.a[k][j])%M;
		return C;
	}
	
	void Set(LL k,bool typ){
		if(typ){
			m=n=3;
			a[1][1]=k%M;	a[1][2]=0;		a[1][3]=0;
			a[2][1]=1;		a[2][2]=1;		a[2][3]=0;
			a[3][1]=1;		a[3][2]=1;		a[3][3]=1;
		}else{
			m=1,n=3;
							a[1][2]=(k/10-1)%M;	a[1][3]=1;
		}
	}
}res,A;

void qPow(LL k){
	while(k){
		if(k&1) res=res*A;
		A=A*A;
		k>>=1;
	}
}

void init(){
#ifdef Judge
	freopen("2326.in","r",stdin);
	freopen("2326.out","w",stdout);
//	SpeedUp;
#endif
	cin>>N>>M;
}

void work(){
	LL k=1;
	for(int i=1;i<=18;i++){
		k*=10;
		A.Set(k,true);
		res.Set(k,false);
		if(k<=N) qPow(k/10*9);
		else qPow(N-k/10+1);
		if(k>N) break;
	}
	print(res.a[1][1]);
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
