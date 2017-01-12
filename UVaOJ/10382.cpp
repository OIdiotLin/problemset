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
#define MAXN (10005)
#define INF ()
#define eps (1e-6)
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
#define sqr(x) ((x)*(x))
struct Block{
	double l,r;
	bool operator < (const Block & T)const {
		return l<T.l;
	}
}A[MAXN];
int N,L,W;

void init(){
	#ifdef Judge
	freopen("10382.in","r",stdin);
	freopen("10382.out","w",stdout);
	SpeedUp;
	#endif
}

void work(){
	int Ans;
	int p,r;
	scanf("")
	for(int i=1;i<=N;i++){
		cin>>p>>r;
		if(r<W/2.0){
			A[i].l=L+716;
			A[i].r=L+716;
			continue;
		}
		double t=sqrt(sqr(r)-sqr(W)/4.0);
		A[i].r=p+t;
		A[i].l=p-t;
	}
	sort(A+1,A+N+1);
	bool flag=false;
	int last=1;
	p=0;
	while(p<L){
		double Max=-1;
		int i;
		for(i=last;(A[i].l<p||abs(A[i].l-p)<eps) && i<=N;i++)
			Max=max(Max,A[i].r);
		if(Max==-1){flag=false;break;}
		p=Max;
		last=i;
		Ans++;
	}
	cout<<(flag ? Ans : -1)<<endl;
}

int main(){
	init();
	while(cin>>N){
	cout<<N<<endl;
	work();
	}
	#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
	#endif
	return 0;
}