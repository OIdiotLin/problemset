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
#define MAXN (32)
#define INF (1e29)
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

double f[MAXN][MAXN][MAXN];
double K,C;
int d[MAXN];
int N,S;

void init(){
#ifdef Judge
	freopen("1261.in","r",stdin);
	freopen("1261.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d%lf%lf",&N,&K,&C);
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			for(int k=0;k<=N;k++)
				f[i][j][k]=-1;
	for(int i=1;i<=N;i++)
		S+=(read(d[i]));
}

double dfs(int i,int j,int k){
	if(i>j)		return 0;
	if(i==j)	return d[i]*(K*(k+1)+C);
	if(f[i][j][k]!=-1)	return f[i][j][k];
	f[i][j][k]=INF;
	for(int p=i;p<=j;p++)
		f[i][j][k]=min(f[i][j][k], dfs(i,p-1,k+1)+dfs(p+1,j,k+1)+d[p]*(K*(k+1)+C));
	return f[i][j][k];
}

void work(){
	double ans=dfs(1,N,0)/S;
	printf("%.3lf\n",ans);
	// fprintf(stderr,"%lf\n",ans);
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