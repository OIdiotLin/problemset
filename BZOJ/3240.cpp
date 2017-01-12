/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
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
#define MAXN (1000005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

struct Matrix{
	LL a,b;
	Matrix(){}
	Matrix(LL x,LL y):
		a(x),b(y){}
	Matrix operator * (const Matrix &T) const{
		return Matrix(a*T.a%ZCY,(b*T.a%ZCY+T.b)%ZCY);
	}
	Matrix operator *=(const Matrix &T){
		return (*this = *this *T);
	}
}A,B;
char N[MAXN],M[MAXN];
LL r1,r2,r3,r4,p,q;

LL get(char *s,LL p){
	LL res=0;
	for(char *c=s;*c;c++)
		res=(res*10LL+(*c)-'0')%p;
	return (res-1+p)%p;
}

Matrix qPow(Matrix x,LL k){
	Matrix res=Matrix(1,0);
	while(k){
		if(k&1)	res*=x;
		k>>=1;
		x*=x;
	}
	return res;
}

void init(){
#ifdef Judge
	freopen("3240.in","r",stdin);
	freopen("3240.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%s%s%lld%lld%lld%lld",N,M,&r1,&r2,&r3,&r4);
	A=Matrix(r1,r2),B=Matrix(r3,r4);
	p=get(N,ZCY-(r1!=1));
	q=get(M,ZCY-(r3!=1));
}

void work(){
	Matrix S=qPow(A,q);
	B*=S;
	Matrix T=qPow(B,p);
	S*=T;
	printf("%lld\n",(S.a+S.b)%ZCY);
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
