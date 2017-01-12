/*
	Work on OIdiot's PC
	System: Ubuntu 14.04 Kylin
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
const int ZCY=1000000007;
const int DirX[]={0,0,-1,0,1};
const int DirY[]={0,1,0,-1,0};

int N,M,T;
int Sx,Sy,Tx,Ty;
bool G[MAXN][MAXN];
int f[20][MAXN][MAXN];

void init(){
	string S;
	#ifdef Judge
	freopen("1616.in","r",stdin);
	freopen("1616.out","w",stdout);
	SpeedUp;
	#endif
	cin>>N>>M>>T;
	for(int i=1;i<=N;i++){
		cin>>S;
		for(int j=0;j<M;j++)
			G[i][j+1]=(S[j]=='.');
	}
	cin>>Sx>>Sy>>Tx>>Ty;
}

void work(){
	f[0][Sx][Sy]=1;
	for(int i=1;i<=T;i++)
		for(int j=1;j<=N;j++)
			for(int k=1;k<=M;k++)
				if(G[j][k])
					for(int x=1;x<=4;x++){
						int tx=j+DirX[x],ty=k+DirY[x];
						if(tx<=0||ty<=0||tx>N||ty>M||!G[tx][ty]) continue;
						f[i][j][k]+=f[i-1][tx][ty];
					}
	cout<<f[T][Tx][Ty]<<endl;
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