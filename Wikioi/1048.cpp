#include <iostream>
#include <cstring>
#define INF 1<<30
#define MAXN 200
#define FILE

using namespace std;

int stone[MAXN],F[MAXN][MAXN],d[MAXN];
int N,Min;

void init()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>stone[i];
		s[i]=s[i-1]+stone[i];
	}
}

void DP()
{
	for(int i=N-1;i>=1;i--)
		for(int j=i+1;j<=N;j++)
		{
			Min=INF;
			for(int k=i;k<j;k++)
				if(Min>F[i][k]+F[k+1][j]+d[j]-d[i-1])
					Min=F[i][k]+F[k+1][j]+d[j]-d[i-1];
			F[i][j]=Min;
		}
}

int main()
{
	init();
	DP();
	cout<<F[1][N]<<endl;
	return 0;
} 
