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

int T,F,N;
int sg[MAXN];

int get_sg(int x){
	if(sg[x]!=-1)	return sg[x];
	if(x<F)	return sg[x]=0;
	bool vis[MAXN];
	memset(vis,false,sizeof(vis));
	for(int i=2;i<=x;i=x/(x/i)+1)
		for(int j=i;j<=i+1&&j<=x;j++){
			int t=0;
			if((x%j)&1)		t^=get_sg(x/j+1);
			if((j-x%j)&1)	t^=get_sg(x/j);
			vis[t]=true;
		}
	int p=0;
	while(vis[p])	p++;
	return sg[x]=p;
}

void init(){
#ifdef Judge
	freopen("3576.in","r",stdin);
	freopen("3576.out","w",stdout);
//	SpeedUp;
#endif
	read(T),read(F);
	memset(sg,-1,sizeof(sg));
}

void work(){
	read(N);
	int res=0,x;
	while(N--){
		read(x);
		res^=get_sg(x);
	}
	putchar(res ? '1' : '0');
	if(T)putchar(' ');
}

int main(){
	init();
	while(T--)
		work();
#ifdef Debug
	cout<<"Time Used : "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used : "<<(double)(sizeof())/1048576<<" MB."<<endl;
#endif
	return 0;
}