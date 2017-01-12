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
#define MAXN (20)
#define MAXM (1<<11)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000001;

inline int getint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
inline void outputint(LL x){
	char ch[20];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(10);
}
#define print(x) outputint(x)
#define read(x) x=getint()

LL Ans;

int f[MAXN][MAXM],bits[MAXN],G[MAXN][MAXN];
bool vis[1<<MAXN];
int N;

void init(){
#ifdef Judge
	freopen("bzoj_2734.in","r",stdin);
	freopen("bzoj_2734.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
}

#define R 18
#define C 11
inline int Calc(int x){
	memset(bits, 0, sizeof(bits));
	G[1][1] = x;
	for (int i = 2; i <= R; i++)
		G[i][1] = (G[i-1][1]*2<=N) ? G[i-1][1]*2 : 0;
	for (int i = 1; i <= R; i++)
		for (int j = 2; j <= C; j++)
			G[i][j] = (G[i][j-1]*3 <= N) ? G[i][j-1]*3 : 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (G[i][j]) {
				bits[i] += 1<<(j-1);
				vis[G[i][j]] = true;
			}
	for (int i = 0; i <= R; i++)
		for (int j = 0; j <= bits[i]; j++)
			f[i][j] = 0;
	f[0][0] = 1;
	for (int i = 0; i < R; i++)
		for (int j = 0; j <= bits[i]; j++) {
			if (f[i][j])
				for (int k = 0; k <= bits[i+1]; k++)
					if(!(j&k) && !(j&(j>>1)))
						f[i+1][k] = (f[i+1][k] + f[i][j]) %ZCY;
		}
	return f[R][0];
}

void work(){
	Ans = 1;
	for (int i = 1; i <= N; i++)
		if (!vis[i])
			Ans = (Ans * Calc(i)) %ZCY;
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