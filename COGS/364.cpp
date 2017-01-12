#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 250
#define INF 1<<29
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug

using namespace std;

int N,A,B;
int Num[MAXN][MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("lift.in","r",stdin);
	freopen("lift.out","w",stdout);
	#endif
	memset(Num,0,sizeof(Num));
	cin>>N>>A>>B;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			if(i!=j)
				Num[i][j]=INF;
			else continue;
		}
	for(int i=1;i<=N;i++)
	{
		int r;
		cin>>r;
		if(i+r<=N)
			Num[i][i+r]=1;
		if(i-r>=1)
			Num[i][i-r]=1;
	}
	#ifdef Debug
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			cout<<Num[i][j]<<" ";
		cout<<endl;
	}
	#endif
}

void floyd()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)
				if(Num[j][i]+Num[i][k]<Num[j][k])
					Num[j][k]=Num[j][i]+Num[i][k];
	if(Num[A][B]==INF)
	{
		cout<<-1<<endl;
		return ;
	}
	cout<<Num[A][B]<<endl;
}

int main()
{
	init();
	floyd();
	return 0;
}
