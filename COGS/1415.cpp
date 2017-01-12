#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1020
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int F[MAXN];
int N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("nums.in","r",stdin);
	freopen("nums.out","w",stdout);
	#endif
	memset(F,0,sizeof(F));
	cin>>N;
}

void Dp()
{
	F[1]=1;
	for(int i=2;i<=N;i++)
	{
		for(int j=1;j<=(i>>1);j++)
		{
			F[i]+=F[j];
		}
		F[i]++;
	}
		
}

void work()
{
	init();
	Dp();
	cout<<F[N]<<endl;
}

int main()
{
	work();
	return 0;
}

