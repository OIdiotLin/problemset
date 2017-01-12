#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 110

using namespace std;

struct Light{
	bool Status;
	int Key;
};

Light L[MAXN];
int N,M;

void init()
{
	int k;
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		L[i].Status=true;
	}
	for(int i=1;i<=M;i++)
	{
		cin>>k;
		for(int j=k;j<=N;j++)
		{
			if(L[j].Status)
			{
				L[j].Status=false;
				L[j].Key=k;
			}
		}
	}
}

void work()
{
	init();
	for(int i=1;i<=N;i++)
	{
		cout<<L[i].Key<<" ";
	}
	cout<<endl;
}
int main()
{
	work();
	return 0;
}

