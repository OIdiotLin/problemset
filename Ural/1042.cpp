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
#define MAXN (255)
#define INF ()
const double PI=acos(-1);
const int ZCY=1000000007;

inline int getint(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void outputint(int x){
	char ch[12];
	int cnt=0;
	if(x==0) {putchar('0'); putchar(10);return;}
	while(x) ch[++cnt]=x%10,x/=10;
	while(cnt) putchar(ch[cnt--]+48);
	putchar(32);
}
#define print(x) outputint(x)
#define read(x) x=getint()

int N;
struct Matrix{
	int mat[MAXN][MAXN];
	int x[MAXN];
	int n;
	Matrix(){memset(mat,0,sizeof(mat));}
	
	void Gauss(){
		for(int i=0;i<N;i++){
			if(mat[i][i]==0){	/* 对角已消元 */
				for(int j=i+1;j<N;j++)
					if(mat[j][i]){
						for(int k=i;k<=N;k++)
							swap(mat[i][k],mat[j][k]);
						break;
					}
			}
			for(int j=i+1;j<N;j++)
				if(mat[j][i])
					for(int k=i;k<=N;k++)
						mat[j][k]^=mat[i][k];
		}
		for(int i=N-1;i>=0;i--){
			x[i]=mat[i][N];
			for(int j=i+1;j<N;j++)
				x[i]^=mat[i][j]*x[j];
		}
	}
	
	void RootVector(){
		for(int i=0;i<N;i++)
			if(x[i]) print(i+1);
		puts("");
	}
	
	void Read(){
		int x;
		for(int i=0;i<N;i++){
			while(true){
				read(x);
				if(x==-1) break;
				mat[x-1][i]=1;
			}
			mat[i][N]=1;	/* spread Matrix */
		}
	}
}Sol;

void init(){
#ifdef Judge
	freopen("1042.in","r",stdin);
	freopen("1042.out","w",stdout);
//	SpeedUp;
#endif
	read(N);
	Sol.Read();
}

void work(){
	Sol.Gauss();
	Sol.RootVector();
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