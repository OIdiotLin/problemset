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
//#define Judge
//#define Debug
#define MAXN (5002)
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

int f1[MAXN],f2[MAXN];
int G[MAXN][MAXN];
int N,H,D;

void init(){
	int r,x;
#ifdef Judge
	freopen("1270.in","r",stdin);
	freopen("1270.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(H),read(D);
	for(int i=1;i<=N;i++){
		read(r);
		while(r--){
			read(x);
			G[i][x]++;
		}
	}
}

void Dp(){
	for(int i=H;i;i--){
		int w=(i+D<=H ? f1[D+i] : 0);
		for(int j=1;j<=N;j++){
			f2[j]=max(f2[j],w)+G[j][i];
			f1[i]=max(f1[i],f2[j]);
		}
	}
	print(f1[1]);
}

int main(){
	init();
	Dp();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}