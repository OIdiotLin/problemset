#include <iostream>
#include <cstring>
#define LHD 1000000007
#define MAXN 2010

using namespace std;

int f[MAXN][MAXN];
int N,K;
bool d[MAXN][MAXN];

int dfs(int i,int j)
{
	if(j==1)
		return i;
	if(d[i][j]==true)
		return f[i][j];
	d[i][j]=true;
	for(int k=1;k<=i;k++)
		f[i][j]=(f[i][j]+dfs(i/k,j-1))%LHD;
		
	return f[i][j];
}

void work()
{
	cin>>N>>K;
	cout<<dfs(N,K)<<endl;
}

int main()
{
	work();
	return 0;
}

