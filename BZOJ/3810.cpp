/*
	Machine: Class4_B2
	System: Ubuntu_Kylin 14.10
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <bitset>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (305)
#define INF (1LL<<60)
const double PI=acos(-1);
const int ZCY=1000000007;
const double eps=1e-8;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	if(x<0)	{putchar('-');	x=-x;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()
#define sqr(x)	((x)*(x))

int N,M,K;
LL f[MAXN][MAXN][16];

void init(){
#ifdef Judge
	freopen("3810.in","r",stdin);
	freopen("3810.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M),read(K);
	memset(f,-1,sizeof(f));
}

LL dfs(int x,int y,bitset<4> s){
	if(x>y){
		swap(y,x);
		bitset<4> t(s);
		s[0]=t[2]&t[3],s[1]=t[2]|t[3];
		s[2]=t[0]&t[1],s[3]=t[0]|t[1];
	}
	if(f[x][y][s.to_ulong()]!=-1)	return f[x][y][s.to_ulong()];
	if(s.none())	return f[x][y][s.to_ulong()]=INF;
	LL t=x*y-K;	t*=t;
	if((s[0]|s[1]|s[2]) && (s[0]|s[1]|s[3])){
		bitset<4> k1(s);	k1.set(3,0);
		bitset<4> k2(s);	k2.set(2,0);
		for(int i=1;i<x;i++)
			t=min(t,dfs(i,y,k1)+dfs(x-i,y,k2));
	}
	if((s[0]|s[2]|s[3]) && (s[1]|s[2]|s[3])){
		bitset<4> k1(s);	k1.set(1,0);
		bitset<4> k2(s);	k2.set(0,0);
		for(int i=1;i<y;i++)
			t=min(t,dfs(x,i,k1)+dfs(x,y-i,k2));
	}
	return f[x][y][s.to_ulong()]=t;
}

void work(){
	bitset<4> k;
	k.set();
	print(dfs(N,M,k));
}

int main(){
	init();
	work();
#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}
