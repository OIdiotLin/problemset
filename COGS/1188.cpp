#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define MAXN 155
#define INF (1<<31-1)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int f[MAXN][MAXN];
int TNode[MAXN][MAXN];	//TNode[i][0] Records the Number of child nodes on Node i;
int N,P,root;
bool p[MAXN];
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("reroads.in","r",stdin);
//	freopen("reroads.out","w",stdout);
	#endif
	cin>>N>>P;
	memset(p,true,sizeof(p));
	for(int i=1;i<N;i++){
		int r1,r2;
		cin>>r1>>r2;
		p[r2]=false;
		TNode[r1][0]++;
		TNode[r1][TNode[r1][0]]=r2;		//Set the new child node;
	}
	for(int i=1;i<=N;i++){
		if(p[i]){
			root=i;
			break;
		}
	}
	#ifdef Debug
	cout<<"Root is "<<root<<endl;
	#endif
	for(int i=1;i<=N;i++)
		for(int j=1;j<=P;j++)
			f[i][j]=INF;
}

void Dp(int o){					//Dp on Node o, as a root;
	f[o][1]=0;
	for(int i=1;i<=TNode[o][0];i++){
		Dp(TNode[o][i]);
		for(int j=P;j;j--){
			f[o][j]++;			//Cut this subtree down if it's not considered.
			for(int k=1;k<j;k++){
				f[o][j]=min(f[o][j],f[TNode[o][i]][j-k]+f[o][k]);
				#ifdef Debug
				cout<<"f["<<o<<"]["<<j<<"] = "<<f[o][j]<<endl;
				#endif
			}
		}
	}
}

int main()
{
	init();
	Dp(root);
	int Ans=f[root][P];
	for(int i=1;i<=N;i++){
		Ans=min(Ans,f[i][P]+1);
	}
	cout<<Ans<<endl;
	#ifdef Debug
	cout<<"Time Used: "<<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
	cout<<"Memory Used: "<<(double)(sizeof(p)+sizeof(TNode)+sizeof(f))/(1048576)<<" MB."<<endl;
	#endif
	return 0;
}

