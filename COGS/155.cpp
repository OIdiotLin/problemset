#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 105
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define Judge
//#define Debug
using namespace std;
typedef long long LL;

const int X[]={0,1,0,-1};
const int Y[]={1,0,-1,0};

bool G[MAXN][MAXN];
int Ans[MAXN*MAXN];
int N,M,K,cnt;

void init()
{
	int x,y;
	#ifdef Judge
	SpeedUp;
	freopen("lake.in","r",stdin);
	freopen("lake.out","w",stdout);
	#endif
	cin>>N>>M>>K;
	cnt=0;
	memset(G,false,sizeof(G));
	for(int i=1;i<=K;i++){
		cin>>x>>y;
		G[x][y]=true;
	}
}

void FloodFill(int x,int y){
	#ifdef Debug
	cout<<"BFS on X="<<x<<"\tY="<<y<<endl;
	#endif
	G[x][y]=false;
	Ans[cnt]++;
	for(int i=0;i<4;i++){
		int tx=x+X[i],ty=y+Y[i];
		if(tx && ty && tx<=N && ty<=M){
			if(G[tx][ty])
				FloodFill(tx,ty);
		}
	}
}

void work(){
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			if(G[i][j]){
				Ans[++cnt]=0;
				#ifdef Debug
				cout<<"cnt="<<cnt<<endl;
				#endif
				FloodFill(i,j);
			}
		}
	int t=-1;
	for(int i=1;i<=cnt;i++){
		//t=max(t,Ans[cnt]); 不能再逗比 
		t=max(t,Ans[i]);
	}
	cout<<t<<endl;
}

int main()
{
	init();
	work();
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(G)+sizeof(Ans))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}
