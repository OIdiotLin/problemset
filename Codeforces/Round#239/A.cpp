#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 110
#define INF 1<<30
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

struct Cashier{
	int Customer;
	int Item[MAXN];
	int Waste;
	
}Cash[MAXN];

int N;
int Min;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	Min=INF;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>Cash[i].Customer;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=Cash[i].Customer;j++)
		{
			cin>>Cash[i].Item[j];
			Cash[i].Waste+=Cash[i].Item[j]*5;
		}
		Cash[i].Waste+=15*Cash[i].Customer;
		if(Cash[i].Waste<Min)
			Min=Cash[i].Waste;
	}
}

void work()
{
	init();
	cout<<Min<<endl;
}

int main()
{
	work();
	return 0;
}

