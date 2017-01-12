#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 25000
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,V,item;
int bag[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("npack.in","r",stdin);
	freopen("npack.out","w",stdout);
	#endif
	memset(bag,0,sizeof(bag));
	cin>>V>>N;
}

void DP()
{
	while(N--)
	{
		cin>>item;
		for(int i=V;i>=item;i--)
			if(bag[i-item]+item>bag[i])
				bag[i]=bag[i-item]+item;
	}
}

void work()
{
	init();
	DP();
	cout<<V-bag[V]<<endl;
}

int main()
{
	work();
	return 0;
}

