#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 510
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int f[MAXN][MAXN];
int B[MAXN],S[MAXN];
int N,K;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("books.in","r",stdin);
	freopen("books.out","w",stdout);
	#endif
	memset(f,0,sizeof(f));
	memset(S,0,sizeof(S));
	cin>>N>>K;
	for(int i=1;i<=N;i++)
	{
		cin>>B[i];
		S[i]=B[i]+S[i-1];
		f[1][i]=S[i];
	}
	for(int i=2;i<=K;i++)
	{
		f[i][i]=max(f[i-1][i-1],S[i]-S[i-1]);
	}
}

void Dp()
{
	for(int i=2;i<=K;i++)
		for(int j=i+1;j<=N;j++)
		{
			f[i][j]=INF;
			for(int k=1;k<j;k++)
				f[i][j]=min(f[i][j],max(f[i-1][k],S[j]-S[k]));
		}
}

void Out()
{
	int t,tN=N;
	B[0]=INF>>2;
	int Start[MAXN],End[MAXN];
	for(int i=K;i;i--)
	{
		t=0;
		int j;
		for(j=tN;j>=0;j--)
		{
			t+=B[j];
			if(t>f[K][N])
				break;
		}
		Start[i]=j+1;
		End[i]=tN;
		tN=j;
	}
	for(int i=1;i<=K;i++)
	{
		cout<<Start[i]<<" "<<End[i]<<endl;
	}
}

int main()
{	
	init();
	Dp();
	Out();
	return 0;
}

