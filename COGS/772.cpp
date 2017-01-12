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
#define MAXN (1005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();if(ch==EOF)exit(0);
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();if(ch==EOF)exit(0);}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();if(ch==EOF)exit(0);}
	return x*f;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(32);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(32);
}
#define print(x) outputint(x)
#define read(x) x=getint()

int N,M,tot,cnt;
int A[MAXN][MAXN],B[MAXN*MAXN],P[MAXN*MAXN],d[MAXN];


void init(){
#ifdef Judge
	freopen("matrixa.in","r",stdin);
	freopen("matrixa.out","w",stdout);
//	SpeedUp;
#endif
}

inline int f(int x){
	int l=1,r=tot;
	while(l<=r){
		int mid=(l+r)>>1;
		B[mid]<x ? l=mid+1 : r=mid-1;
	}
	return l;
}

void work(){
	for(int i=1;i<=M;i++)
		d[i]=0;
	cnt=0,tot=1;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			B[++cnt]=(read(A[i][j]));
			P[cnt]=1001;
		}
	sort(B+1,B+cnt+1);
	for(int i=2;i<=cnt;i++)
		if(B[i]!=B[i-1])
			B[++tot]=B[i];
	for(int i=1;i<=N;i++){
		cnt=0;
		for(int j=1;j<=M;j++){
			A[i][j]=f(A[i][j]);
			if(P[A[i][j]]<=j)
				print(cnt+=d[j]);
			else{
				d[P[A[i][j]]]--;
				P[A[i][j]]=j;
				print(cnt+=(++d[j]));
			}
		}
		puts("");
	}
}

int main(){
	init();
	while(read(N),read(M)){
		work();
		// fprintf(stderr,"solved %d.\n",++cnt);
	}
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}