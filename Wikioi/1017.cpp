#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long Max(long long a,long long b)
{
    if(a>=b)
        return a;
    else
        return b;
}

long long Assis[100][100],F[100][100];
string st;
int N,K;

void init()
{
	cin>>N>>K;
	cin>>st;
	for(int i=0;i<N;i++)
	{
		long long n=0;
		for(int j=i;j<N;j++)
		{
			n=n*10+st[j]-'0';
			Assis[i][j]=n;
		}
	}
	memset(F,0,sizeof(F));
	for(int i=0;i<N;i++)
		F[i][0]=Assis[0][i];
}

void DP()
{
	for(int i=0;i<N;i++)
		for(int j=1;j<=K;j++)
			for(int k=0;k<i;k++)
				F[i][j]=Max(F[k][j-1]*Assis[k+1][i],F[i][j]);
}

int main()
{
	init();
	DP();
	cout<<F[N-1][K]<<endl;
	return 0;
}
