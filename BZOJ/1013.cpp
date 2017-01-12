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
#define Judge
//#define Debug
#define MAXN (12)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-4;

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
double p[MAXN][MAXN],x[MAXN];

struct Matrix{
	int n;
	double a[MAXN][MAXN];
	void Init_Zero(){for(int i=0;i<MAXN;i++)for(int j=0;j<MAXN;j++)a[i][j]=0.0;}
	Matrix(int _n=1):n(_n){Init_Zero();}
	
	void Set(int i,int j,double x){
		a[i][j]=x;
	}
	
	double &X(const int i){
		return a[i][n+1];
	}
	
	void Gauss_Elmt(int now){
		if(now==n){
			x[now]=X(now)/a[now][n];
			return;
		}
		if(fabs(a[now][now])<eps)
			for(int i=now+1;i<=n;i++)
				if(fabs(a[i][now])>eps){
					for(int j=now;j<=n+1;j++)
						swap(a[now][j],a[i][j]);
					break;
				}
		if(fabs(a[now][now])>eps)
			for(int i=now+1;i<=n;i++)
				for(int j=now+1;j<=n+1;j++)
					a[i][j]-=a[now][j]*a[i][now]/a[now][now];
		Gauss_Elmt(now+1);
		for(int i=now+1;i<=n;i++)
			X(now)-=x[i]*a[now][i];
		x[now]=X(now)/a[now][now];
	}
}A;

#define sqr(x) ((x)*(x))

void init(){
#ifdef Judge
	freopen("bzoj_1013.in","r",stdin);
	freopen("bzoj_1013.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d",&N);
	A=Matrix(N);
	for(int i=1;i<=N+1;i++)
		for(int j=1;j<=N;j++)
			scanf("%lf",&p[i][j]);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			A.Set(i,j,(p[i+1][j]-p[i][j])*2.0);
		for(int j=1;j<=N;j++)
			A.X(i)+=sqr(p[i+1][j])-sqr(p[i][j]);
	}
}

void work(){
	A.Gauss_Elmt(1);/*
	for(int i=1;i<=N;i++)
		cout<<fixed<<setprecision(3)<<x[i]<<" ";
	cout<<endl;*/
	for(int i=1;i<N;i++)
		printf("%.3lf ",x[i]);
	printf("%.3lf\n",x[N]);
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