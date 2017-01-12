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
#define MAXN (102)
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

int G[MAXN][MAXN],fa[MAXN];
char ans[MAXN][MAXN];
int N,Ac,Dc;
LL Cost;

inline int f(int x){
	return fa[x]==x ? x : fa[x]=f(fa[x]);
}

void init(){
	char ch;
	SpeedUp;
#ifdef Judge
	freopen("1709.in","r",stdin);
	freopen("1709.out","w",stdout);
#endif
	memset(ans,'0',sizeof(ans));
	cin>>N>>Dc>>Ac;
	for(int i=1;i<=N;i++)
		fa[i]=i;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			cin>>ch;
			if(ch=='1' && i<j){
				int x=f(i),y=f(j);
				if(x==y){
					ans[i][j]=ans[j][i]='d';
					Cost+=Dc;
				}else fa[x]=y;
			}
		}
}

void work(){
	int S=1;
	for(int i=1;i<=N;i++){
		int x=f(S),y=f(i);
		if(x!=y){
			ans[S][i]=ans[i][S]='a';
			fa[y]=x;
			Cost+=Ac;
		}
	}
	cout<<Cost<<endl;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout<<ans[i][j];
		cout<<endl;
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