#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 55
#define MAXM 510
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int Brick[MAXN][MAXN],d[MAXN][MAXN];
int f[MAXN][MAXM][MAXN];
int N,M;
int Ans;
  
void init()
{
	Ans=0;
	SpeedUp;
	#ifdef FILE
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	#endif
	memset(d,0,sizeof(d));
	memset(f,-1,sizeof(f));
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j++)
			cin>>Brick[j][i];
			
	for(int i=1;i<=N;i++)
		for(int j=1;j<=i;j++)
		{
			d[i][j]=d[i][j-1]+Brick[i][j];
		}
	for(int i=0;i<=N;i++)
	{
		f[i][0][0]=0;
		f[i+1][1][1]=Brick[i+1][1];
	}
	
}

void DP()
{
	for(int i=1;i<=N;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=M;k++)
			{
				if(j<=k)
				{
					for(int x=j-1;x<=i;x++)
					{
						if(f[i-1][k-j][x]!=-1)
						{
							f[i][k][j]=max(f[i][k][j],d[i][j]+f[i-1][k-j][x]);
							if(k==M)
								Ans=max(Ans,f[i][k][j]);
						}
					}
				}
			}
}

void work()
{
	DP();
	#ifdef Debug
	cout<<"DP"<<endl;
	#endif

	cout<<Ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}

