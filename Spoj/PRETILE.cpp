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

int T,len;
int next[MAXN];
char S[MAXN];

void init(){
#ifdef Judge
	freopen("PRETILE.in","r",stdin);
	freopen("PTRTILE.out","w",stdout);
//	SpeedUp;
#endif
	read(T);
}

void ext_KMP(){
	int k=0,p=0;
	next[1]=len;
	for(int i=2;i<=len;i++){
		int l=min(next[i-k+1],p-i+1);
		if(l<0)	l=0;
		while(i+l<=len && S[l+1]==S[i+l])	l++;
		next[i]=l;
		if(p<i+l-1)
			p=i+l-1,k=i;
	}
}

void work(){
	scanf("%s",S+1);
	len=strlen(S+1);
	LL ans=len;
	ext_KMP();
	for(int i=1;i<len;i++)
		ans+=next[i+1]+i;
	printf("%lld\n",ans);
}

int main(){
	init();
	for(int i=1;i<=T;i++){
		work();
		fprintf(stderr,"solved %d/%d.\n",i,T);
	}
#ifdef Debug
	cerr<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cerr<<"Memory Used : "<<(double)(sizeof(S)+sizeof(next))/1048576<<" MB."<<endl;
#endif
	return 0;
}
