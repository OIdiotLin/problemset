#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1001
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int Count[MAXN];
int N,sum;

void init()
{
	int r;
	SpeedUp;
	#ifdef FILE
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	#endif
	memset(Count,0,sizeof(Count));
	sum=0;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>r;
		if(Count[r]==0)
			sum++;
		Count[r]++;
	}
}

void work()
{
	cout<<sum<<endl;
	for(int i=1;i<MAXN;i++)
		if(Count[i])
			cout<<i<<" ";
	cout<<endl;
}

int main()
{
	init();
	work();
	return 0;
}

