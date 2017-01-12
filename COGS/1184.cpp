#include <iostream>
#include <cstdio>
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define MAXN 2050

using namespace std;

int Apple[MAXN],TT[MAXN];
bool picked[MAXN];
int Na,Nt,rest;

void init()
{
	#ifdef FILE
	freopen("applea.in","r",stdin);
	freopen("applea.out","w",stdout);
	#endif
	SpeedUp;
	cin>>Na>>Nt;
	rest=Nt;
	for(int i=1;i<=Na;i++)
		cin>>Apple[i];
	for(int i=1;i<=Nt;i++)
	{
		cin>>TT[i];
		if(TT[i]<=0)
		{
			i--;
			Nt--;
		}
	}	
}

void pick()
{
	for(int i=1;i<=Na;i++)
	{
		int t=-1;
		for(int j=1;j<=Nt;j++)
		{
			if(!picked[j] && Apple[i]>TT[j])
			{
				if(t==-1 || TT[t]<TT[j])
					t=j;
			}
		}
		picked[t]=true;
	}
	for(int i=1;i<=Nt;i++)
		if(picked[i])
			rest--;
}

int main()
{
	init();
	pick();
	cout<<rest<<endl;
	return 0;
}
