/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iomanip>
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

int FwT[MAXN];

inline int lowbit(int x){
	return x&(-x);
}

void init(){
#ifdef Judge
	freopen("1316.in","r",stdin);
	freopen("1316.out","w",stdout);
	
#endif
}

void Modify(int x,int v){
	while(x>0){
		FwT[x]+=v;
		x-=lowbit(x);
	}
}

int Query(int x){
	int ret=0;
	while(x<MAXN){
		ret+=FwT[x];
		x+=lowbit(x);
	}
	return ret;
}

void work(){
	LL Ans=0;
	int p;
	char CMD[10];
	double x;int k;
	while(true){
		scanf("%s",CMD);
		switch(CMD[0]){
			case 'B':	scanf("%lf",&x);		p=floorl(x*100+0.5);
						Modify(p,1);
						break;
			case 'S':	scanf("%lf%d",&x,&k);	p=floorl(x*100+0.5);
						Ans+=min(Query(p),k);
						break;
			case 'D':	scanf("%lf",&x);		p=floorl(x*100+0.5);
						Modify(p,-1);
						break;
			case 'Q':	printf("%.2lf\n",Ans/100.0);
						return;
			default:	cout<<"Error Command"<<endl;
						return;
		}
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
