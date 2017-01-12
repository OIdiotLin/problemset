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
#define MAXN (100005)
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

struct Seg{
	int l,r;
	inline void Read(){
		read(l),read(r);
	}
}A[MAXN>>1];

int N,tot,_tot;
int S[MAXN],p[MAXN];
int hash[1000005];

void init(){
#ifdef Judge
	freopen("1651.in","r",stdin);
	freopen("1651.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
		A[i].Read();
		p[++tot]=A[i].l,p[++tot]=A[i].r;
	}
	sort(p+1,p+tot+1);
	_tot=unique(p+1,p+tot+1)-p-1;
}

void work(){
	int Ans=0;
	for(int i=1;i<=_tot;i++)
		hash[p[i]]=i;
	for(int i=1;i<=N;i++){
		S[hash[A[i].l]-1]++;
		S[hash[A[i].r]]--;
	}
	for(int i=1;i<=_tot;i++){
		S[i]=S[i-1]+S[i];
		Ans=max(Ans,S[i]);
	}
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