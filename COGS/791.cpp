#include <iostream>
#include <cstdio>
#include <cstring>
#define FILE
//#define Debug
using namespace std;

int N,maxLevel,beginLevel,ans;
bool F[60][1010];
int vol[60];

void init()
{
	#ifdef FILE
	freopen("changingsounds.in","r",stdin);
	freopen("changingsounds.out","w",stdout);
	#endif
	
	ans=-1;
	cin>>N>>beginLevel>>maxLevel;
	for(int i=1;i<=N;i++)
		cin>>vol[i];
	memset(F,false,sizeof(F));
	F[0][beginLevel]=true;
}

void Work()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=maxLevel;j++)
		{
			if(j-vol[i]>=0 && j-vol[i]<=maxLevel)
			{
				F[i][j]=(F[i-1][j-vol[i]] || F[i][j]);
			}
			if(j+vol[i]>=0 && j+vol[i]<=maxLevel)
			{
				F[i][j]=(F[i-1][j+vol[i]] || F[i][j]);
			}
			#ifdef Debug
			cout<<"\tF["<<i<<"]["<<j<<"]="<<(F[i][j] ? "True" : "False")<<endl;
			#endif
		}
	}
	for(int i=0;i<=maxLevel;i++)
		if(F[N][i])
			ans=i;
}

int main()
{
	init();
	Work();
	cout<<ans<<endl;
	return 0;
}
