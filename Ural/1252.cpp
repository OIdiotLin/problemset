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
#define MAXN (130005)
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

int N;
int pos[MAXN];

inline int gcd(int a,int b){
	if(!a)	return b;
	if(!b)	return a;
	if(!(a&1) && !(b&1))
		return gcd(a>>1,b>>1)<<1;
	if(!(a&1))	return gcd(a>>1,b);
	if(!(b&1))	return gcd(b>>1,a);
	return gcd(abs(a-b),min(a,b));
}

void init(){
	int x;
#ifdef Judge
	freopen("1252.in","r",stdin);
	freopen("1252.out","w",stdout);
#endif
	read(N);
	for(int i=1;i<=N;i++){
		read(x);
		pos[x]=i;
	}
}

void Solve(int &x,int &c,int i){
	if(!pos[i]) return;
	if(pos[i]==++x) return;
	c=(c ? gcd(c,abs(pos[i]-x)) : abs(pos[i]-x));
}

void work(){
	int Ans1=0,Ans2=0,cnt=0;
	for(int i=1;i<MAXN;i++)
		Solve(cnt,Ans1,i);
	cnt=0;
	for(int i=MAXN-1;i;i--)
		Solve(cnt,Ans2,i);
	print((Ans1&&Ans2) ? max(Ans1,Ans2)-1 : N-1);

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