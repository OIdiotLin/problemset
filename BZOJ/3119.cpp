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
#define MAXN (200005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

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
	if(x==0) {putchar('0'); putchar(32);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(32);
}
#define print(x) outputint(x)
#define read(x) x=getint()

LL N,a1,A,S,B;
bool vis[MAXN];

void init(){
#ifdef Judge
	freopen("3119.in","r",stdin);
	freopen("3119.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(a1),read(A),read(B),read(S);
}

void work(){
	// LL x=(B*N*(N-1)+(a1*N<<1)-(S<<1))/(B-A<<1);
	// LL y=(A*N*(N-1)+(a1*N<<1)-(S<<1))/(A-B<<1);
	LL x=(S-a1*N+B*(N*(N-1)>>1))/(A+B);
	LL y=(N*(N-1)>>1)-x;
	LL cur=N-1;
	while(x){
		if(x-cur>=0){
			vis[cur]=true;
			x-=cur;
		}
		cur--;
	}
	print(a1);
	for(int i=N-1;i;i--)
		print(a1+=(vis[i] ? A : -B));
	puts("");
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