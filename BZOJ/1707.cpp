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
#define MAXN (2505)
#define INF (0x7fffffff)
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

struct Cow{
	int l,r;
	bool used;
	Cow(int _l=0,int _r=0):
		l(_l),r(_r){used=false;}
	bool Include(int v){
		return v<=r&&v>=l;
	}
}C[MAXN];

struct item{
	int v,num;
	item(int _v=0,int _n=0):
		v(_v),num(_n){}
	bool operator < (const item &t)const{
		return v<t.v;
	}
}A[MAXN];

int N,M,Ans;

inline void get(int x){
	int res=0,Min=INF;
	for(int i=1;i<=N;i++){
		if(C[i].used || !C[i].Include(x)) continue;
		if(C[i].r<Min)
			Min=C[i].r,res=i;
	}
	if(res) C[res].used=true,Ans++;
}

void init(){
	int l,r,v,num;
#ifdef Judge
	freopen("1707.in","r",stdin);
	freopen("1707.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	for(int i=1;i<=N;i++){
		read(l),read(r);
		C[i]=Cow(l,r);
	}
	for(int i=1;i<=M;i++){
		read(v),read(num);
		A[i]=item(v,num);
	}
	sort(A+1,A+M+1);
}

void work(){
	for(int i=1;i<=M;i++)
		while(A[i].num--)
			get(A[i].v);
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