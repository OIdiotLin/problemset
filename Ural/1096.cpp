/*
	Machine: Class4_B2
	System: Windows7 SP1 32bit
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
typedef long long LL;
using namespace std;
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
#define MAXN (2005)
#define INF (0x3fffff)
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

struct Edge{
	int x,y;
	void Read(){
		read(x);
		read(y);
	}
}E[MAXN];

int path[MAXN];
int dist[MAXN];
int N,S,T,k;

void init(){
#ifdef Judge
	freopen("1096.in","r",stdin);
	freopen("1096.out","w",stdout);
	//SpeedUp;
#endif
	read(N);
	for(int i=1;i<=N;i++){
		E[i].Read();
		dist[E[i].x]=dist[E[i].y]=INF;
	}
	read(S),read(T),read(k);
	dist[S]=0;
}

inline void Out(int x){
	if(x==S) return;
	print(path[x]);
	Out(E[path[x]].y);
}

void work(){
	bool flag=false;
	while(true){
		flag=true;
		for(int i=1;i<=N;i++){
			int x=E[i].x,y=E[i].y;
			if(dist[x]==INF && dist[y]!=INF){
				flag=false;
				dist[x]=dist[y]+1;
				path[x]=i;
				if(x==T || x==k){
					print(dist[x]);
					Out(x);
					return;
				}
			}
		}
		if(flag) break;
	}
	printf("IMPOSSIBLE\n");
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
