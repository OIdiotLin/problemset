/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <set>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (600005)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;
const LL LHD=257;

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

set<int> Set;
int base[MAXN];
char S[MAXN];
int N,M;

inline int hash(char *st){
	int len=strlen(st);
	int res=0;
	for(int i=0;i<len;i++)
		res=(res*LHD+st[i])%ZCY;
	return res;
}

void init(){
#ifdef Judge
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
//	SpeedUp;
#endif
	read(N),read(M);
	base[0]=1;
	for(int i=1;i<MAXN;i++)
		base[i]=base[i-1]*LHD%ZCY;
	for(int i=1;i<=N;i++){
		scanf("%s",S);
		Set.insert(hash(S));
	}
}

bool change(char *st){
	int len=strlen(st);
	int h=hash(st);
	for(int i=0;i<len;i++)
		for(int ch='a';ch<='c';ch++){
			if(ch==st[i])	continue;
			int key=(((LL)(ch-st[i])*base[len-i-1]+h)%ZCY+ZCY)%ZCY;
			if(Set.find(key)!=Set.end())
				return true;
		}
	return false;
}

void work(){
	for(int i=1;i<=M;i++){
		scanf("%s",S);
		puts(change(S) ? "YES" : "NO");
	}
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