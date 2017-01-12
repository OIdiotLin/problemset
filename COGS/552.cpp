#include <iostream>
#include <cstring>
#include <cstdio>
#define INF (-(1<<30))
#define MAXN 55
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int Melon[MAXN][MAXN][MAXN];
int F[MAXN];
int N,M,H;//³¤¿í¸ß;
int Ans,Nutrition; 

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	#endif
	memset(Melon,0,sizeof(Melon));
	memset(F,0,sizeof(F));
	Ans=0;
	
	cin>>H>>N>>M;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=N;j++)
			for(int k=1;k<=M;k++)
			{
				cin>>Nutrition;
				Melon[i][j][k]=Melon[i][j-1][k]+Melon[i][j][k-1]-Melon[i][j-1][k-1]+Nutrition;
			}
}

void Dp()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			for(int p=i;p<=N;p++)
				for(int q=j;q<=M;q++)
					for(int k=1;k<=H;k++)
					{
						F[k]=F[k-1]+Melon[k][p][q]-Melon[k][p][j-1]-Melon[k][i-1][q]+Melon[k][i-1][j-1];
						if(F[k]<0)
							F[k]=0;
						if(Ans<F[k])
							Ans=F[k];
					}
}

void work()
{
	init();
	Dp();
	cout<<Ans<<endl;
}

int main()
{
	work();
	return 0;
}

