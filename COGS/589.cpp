#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 2100
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

inline int Max(int a,int b,int c){if(a>b)return (b>c?c:b);return(a>c?c:a);}

int N;
int f[MAXN][MAXN],C[MAXN],Ans;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("xoinc.in","r",stdin);
	freopen("xoinc.out","w",stdout);
	#endif
	Ans=0;
	cin>>N;
	for(int i=N;i;i--)
		cin>>C[i];
	for(int i=1;i<=N;i++)
		C[i]+=C[i-1];
}

void Dp()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			int x=(i-j*2+1)>=0 ? C[i]-f[i-j*2+1][j*2-1] : 0;
			int y=(i-j*2)>=0 ? C[i]-f[i-j*2][j*2] : 0;
			f[i][j]=Max(f[i][j-1],x,y);
		}
}

void work()
{
	init();
	Dp();
	cout<<f[N][1]<<endl;
}

int main()
{
	work();
	return 0;
}

