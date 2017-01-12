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
#define MAXN (105)
#define INF ()
const double PI=acos(-1);
const int ZCY=2009;

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

#define p(i,j) (((j)-1)*N+(i))
int N,T;

struct Matrix{
	int g[MAXN][MAXN];
	int n;
	void Ins(int u,int v){
		g[u][v]=1;
	}
	void Init_Identity(){
		for(int i=1;i<=n;i++)
			g[i][i]=1;
	}
	void Init_Zero(){
		memset(g,0,sizeof(g));
	}
	Matrix(){Init_Zero();n=N*9;}
	
	Matrix operator * (const Matrix&B)const{
		Matrix C;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					C.g[i][j]=(C.g[i][j]+g[i][k]*B.g[k][j])%ZCY;
		return C;
	}
}G,Ans;

void qPow(LL k){
	Ans.Init_Identity();
	while(k){
		if(k&1) Ans=Ans*G;
		G=G*G;
		k>>=1;
	}
}

void init(){
	string S;
#ifdef Judge
	freopen("1297.in","r",stdin);
	freopen("1297.out","w",stdout);
//	SpeedUp;
#endif
	cin>>N>>T;
	G.n=Ans.n=N*9;
	for(int i=1;i<=N;i++)
		for(int j=2;j<=9;j++)
			G.Ins(p(i,j),p(i,j-1));
	for(int i=1;i<=N;i++){
		cin>>S;
		for(int j=0;j!=N;j++){
			int w=S[j]-'0';
			if(w) G.Ins(i,p(j+1,w));
		}
	}
}

void work(){
	qPow(T);
	cout<<Ans.g[1][N]%ZCY<<endl;
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