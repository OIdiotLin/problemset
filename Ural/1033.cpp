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
//#define Judge
//#define Debug
#define MAXN (50)
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

const int DirX[]={0,1,0,-1};
const int DirY[]={1,0,-1,0};
bool G[MAXN][MAXN],f[MAXN][MAXN];
int N;

void init(){
	string s;
#ifdef Judge
	freopen("1033.in","r",stdin);
	freopen("1033.out","w",stdout);
	SpeedUp;
#endif
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>s;
		for(int j=0;j<N;j++)
			G[i][j+1]=(s[j]=='.');
	}
}

inline void DFS(int x,int y){
	f[x][y]=true;
	G[x][y]=false;
	for(int i=0;i<4;i++){
		int tx=x+DirX[i],ty=y+DirY[i];
		if(G[tx][ty])
			DFS(tx,ty);
	}
}

void work(){
	int Ans=0;
	DFS(1,1);
	DFS(N,N);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(f[i][j])
				for(int k=0;k<4;k++){
					int tx=i+DirX[k],ty=j+DirY[k];
					if(!f[tx][ty]) Ans++;
				}
	cout<<(Ans-4)*9<<endl;
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