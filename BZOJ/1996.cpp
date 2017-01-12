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
const int ZCY=19650827;

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
int A[MAXN];
int f[MAXN][MAXN][2];

void init(){
#ifdef Judge
	freopen("1996.in","r",stdin);
	freopen("1996.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
		read(A[i]);
		f[i][i][0]=1;
	}
}

void DP(){
	for(int i=N-1;i;i--)
		for(int j=i+1;j<=N;j++){
			if(A[i]<A[i+1])	f[i][j][0]+=f[i+1][j][0];
			if(A[i]<A[j])	f[i][j][0]+=f[i+1][j][1];
			if(A[j]>A[i])	f[i][j][1]+=f[i][j-1][0];
			if(A[j]>A[j-1])	f[i][j][1]+=f[i][j-1][1];
			f[i][j][0]%=ZCY,f[i][j][1]%=ZCY;
		}
}

void work(){
	DP();
	print((f[1][N][0]+f[1][N][1])%ZCY);
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
