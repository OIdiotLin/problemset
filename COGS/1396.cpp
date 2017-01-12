#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 30
#define M 20
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N;
int Ans[MAXN][MAXN][MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("wwww.in","r",stdin);
	freopen("wwww.out","w",stdout);
	#endif
	for(int i=0;i<=M;i++)
		for(int j=0;j<=M;j++)
			Ans[0][i][j]=1;
	for(int i=0;i<=M;i++)
		for(int j=0;j<=M;j++)
			Ans[i][0][j]=1;
	for(int i=0;i<=M;i++)
		for(int j=0;j<=M;j++)
			Ans[i][j][0]=1;
	for(int i=1;i<=M;i++)
		for(int j=1;j<=M;j++)
			for(int k=1;k<=M;k++)
			{
				if(i<j && j<k)
					Ans[i][j][k]=Ans[i][j][k-1]+Ans[i][j-1][k-1]-Ans[i][j-1][k];
				else
					Ans[i][j][k]=Ans[i-1][j][k]+Ans[i-1][j-1][k]+Ans[i-1][j][k-1]-Ans[i-1][j-1][k-1];
			}
	
}

void ask()
{

	while(1)
	{
		int r1,r2,r3;
		cin>>r1>>r2>>r3;
		if(r1==-1 && r2==-1 && r3==-1)
			break ;
		if(r1<0 || r2<0 || r3<0)
			cout<<1<<endl;
		else if(r1>M || r2>M || r3>M)
			cout<<Ans[M][M][M]<<endl;
		else
			cout<<Ans[r1][r2][r3]<<endl;
	}
}

void work()
{
	init();
	ask();
}

int main()
{
	work();
	return 0;
}

