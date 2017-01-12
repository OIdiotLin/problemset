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
#define MAXN (1000003)
#define INF (0x7f7f7f7f)
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
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

int N,Ans;
int A[MAXN],f[MAXN][3];

void init(){
	#ifdef Judge
	freopen("3427.in","r",stdin);
	freopen("3427.out","w",stdout);
//	SpeedUp;
	#endif
	Ans=INF;
	read(N);
	for(int i=1;i<=N;i++)
		read(A[i]);
	memset(f,127,sizeof(f));
}

void work(){
	f[1][A[1]+1]=0;
	for(int i=1;i<N;i++)
		for(int j=0;j<=2;j++)
			if(f[i][j]!=INF)
				for(int k=0;k<=2;k++){
					int next=A[i+1]+k*(j-1);
					if(next>=j-1 && next>=-1 && next<=1)
						f[i+1][next+1]=min(f[i+1][next+1],f[i][j]+k);
				}
	for(int i=0;i<=2;i++)
		Ans=min(f[N][i],Ans);
	if(Ans==INF){cout<<"BRAK"<<endl;return;}
	print(Ans);
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