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
#define MAXN (1000005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline LL getint(){
	LL x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()
#define sqr(x) ((x)*(x))

int N;
LL a,b,c;
LL S[MAXN],Q[MAXN],f[MAXN];

inline LL calc(LL x){
	return sqr(x)*a+x*b+c;
}
double slope(int l,int r){
	return (double)(f[r]-f[l]+a*(sqr(S[r])-sqr(S[l]))-b*(S[r]-S[l]))/(double)(2*a*(S[r]-S[l]));
}

void init(){
	LL r;
#ifdef Judge
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
//	SpeedUp;
#endif
	scanf("%d%lld%lld%lld",&N,&a,&b,&c);
	for(int i=1;i<=N;i++){
		scanf("%lld",&r);
		S[i]=S[i-1]+r;
	}
}

void dp(){
	int head=0,tail=0;
	static int Q[MAXN];
	for(int i=1;i<=N;i++){
		while(head<tail && S[i]>slope(Q[head],Q[head+1]))	head++;
		f[i]=f[Q[head]]+calc(S[i]-S[Q[head]]);
		while(head<tail && slope(Q[tail-1],Q[tail])>slope(Q[tail],i))	tail--;
		Q[++tail]=i;
	}
}

void work(){
	dp();
	printf("%lld\n",f[N]);
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