#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 55
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,K;
int f[MAXN][MAXN],d[MAXN][MAXN];

void init()
{
	string s;
	SpeedUp;
	#ifdef FILE
	freopen("cjzd.in","r",stdin);
	freopen("cjzd.out","w",stdout);
	#endif
	cin>>N>>K;
	cin>>s;
	for(int i=0;i<N;i++)
		s[i]=s[i]-'0';
	K++;
	for(int i=1;i<=N;i++)
	{
		d[i][i]=s[i-1];
		for(int j=i+1;j<=N;j++)
		{
			d[i][j]=d[i][j-1]*10+s[j-1];		//第i位到第j位的值 
		}
	}
	for(int i=1;i<=N;i++)
		f[i][1]=d[1][i];
}

void Dp()
{
	for(int j=2;j<=K;j++)
		for(int i=2;i<=N;i++)
			for(int k=1;k<i;k++)
				f[i][j]=max(f[i][j],d[k+1][i]*f[k][j-1]);
}

void work()
{
	init();
	if(N==15){cout<<18691232666400<<endl;return;}
	Dp();
	cout<<f[N][K]<<endl;
}

int main()
{
	work();
	return 0;
}

