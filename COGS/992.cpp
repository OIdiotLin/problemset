#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXM 40010
#define MAXN 110
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;

struct Item{
	int Value,Weight,M;
};

int N,W;
int f[MAXM];
Item T[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	#endif
	cin>>N>>W;
	for(int i=1;i<=N;i++)
		cin>>T[i].Value>>T[i].Weight>>T[i].M;
	memset(f,0,sizeof(f));
}

void Pick(Item A)
{
	for(int i=W;i>=A.Weight;i--)
		f[i]=max(f[i],f[i-A.Weight]+A.Value);
	for(int i=1;i<=W;i++)
		f[i]=max(f[i],f[i-1]);
}

void Dp(Item A)
{
	int t=1;
	while(1)
	{
		if(A.M>=t)
		{
			Item tmp=(Item){A.Value*t,A.Weight*t,0};
			Pick(tmp);
			A.M-=t;
		}
		else
		{
			Item tmp=(Item){A.Value*A.M,A.Weight*A.M,0};
			Pick(tmp);
			return;
		}
		t*=2;
	}
}

void work()
{
	for(int i=1;i<=N;i++)
	{
		Dp(T[i]);
	}
	cout<<f[W]<<endl;
}

int main()
{
	init();
	work();
	return 0;
}

