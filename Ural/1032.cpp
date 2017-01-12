/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <vector>
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
#define MAXN (10003)
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

int N,l,r;
int A[MAXN],Sum[MAXN];
int chk[MAXN];

void init(){
#ifdef Judge
	freopen("1032.in","r",stdin);
	freopen("1032.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	memset(chk,-1,sizeof(chk));
	chk[0]=0;
	for(int i=1;i<=N;i++){
		read(A[i]);
		Sum[i]=(A[i]+Sum[i-1])%N;
	}
}

void work(){
	for(int i=1;i<=N;i++){
		if(chk[Sum[i]]==-1) chk[Sum[i]]=i;
		else l=chk[Sum[i]],r=i;
	}
	print(r-l);
	for(int i=l+1;i<=r;i++)
		print(A[i]);
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
