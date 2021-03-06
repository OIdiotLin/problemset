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
#define MAXN (300001)
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



void init(){
	int k,c1,c2,x;
#ifdef Judge
	freopen("3438.in","r",stdin);
	freopen("3438.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++)
		read(A[i]),Ans+=A[i];
	for(int i=1;i<=N;i++)
		read(B[i]),Ans+=B[i];
	cin>>M;
	S=(N+M)<<1|1,T=S+1;
	for(int i=1;i<=N;i++){
		Ins(S,i,A[i]);
		Ins(N+i,T,B[i]);
		Ins(i,N+i,INF);
	}
	for(int i=1;i<=M;i++){
		read(k),read(c1),read(c2);
		Ans+=c1+c2;
		Ins(S,(N<<1)+i,c1);
		Ins((N<<1)+M+i,T,c2);
		for(int j=1;j<=k;j++){
			read(x);
			Ins((N<<1)+i,x,INF);
			Ins(x,(N<<1)+M+i,INF);
		}
	}
}

void Augment(){
	int f=INF;
	for(int p=T;p!=S;p=

int main(){
	init();
	work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}