#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN (2*105)
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int f[MAXN][MAXN];
int bead[MAXN];
int N,Ans;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>bead[i];
		bead[N+i]=bead[i];		//A loop
	}
	memset(f,0,sizeof(f));
	Ans=-INF;
}

int Merge(int i,int j,int k){
	return bead[i]*bead[k+1]*bead[j+1];
}

void dp()
{
	for(int j=2;j<2*N;j++)		// from i , merge j beads. [MAX]
		for(int i=j-1;i && j-i<N;i--)
		{
			for(int k=i;k<j;k++)
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+Merge(i,j,k));				//enumerate the break point
			Ans=max(Ans,f[i][j]);
		}
}

void work()
{
	init();
	dp();
	cout<<Ans<<endl;
}

int main()
{
	work();
	return 0;
}

