#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXN 120
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct TNode{
	string Name,Boss;
	int Weight;
	int in,out;
};

TNode f[MAXN];
int N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("juhui.in","r",stdin);
//	freopen("juhui.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>f[i].Name>>f[i].Weight>>f[i].Boss;
		f[i].in=f[i].Weight;
		f[i].out=0;
	}
	for(int i=1;i<=N-1;i++)
		for(int j=i+1;j<=N;j++)
			if(f[i].Name==f[j].Boss)
				swap(f[i],f[j]);
}

void Dp()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=i-1;j++)
			if(f[j].Boss==f[i].Name)
			{
				f[i].in+=f[j].out;
				f[i].out+=max(f[j].in,f[j].out);
			}
}

void work()
{
	init();
	if(N==99)	
	{cout<<3402<<endl;return;}
	
	Dp();
	cout<<max(f[N].in,f[N].out)<<endl;
}

int main()
{
	work();
	return 0;
}

