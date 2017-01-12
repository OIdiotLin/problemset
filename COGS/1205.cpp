#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 1<<28
#define Zero 10000
#define MAXN 1005
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct Domino{
	int upper,lower;
};

Domino c[MAXN];
int N,Lim=Zero;
int f[2*Zero+10];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("dom.in","r",stdin);
	freopen("dom.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>c[i].upper>>c[i].lower;
		Lim+=(c[i].upper-c[i].lower);
	}
	for(int i=Zero-5*N;i<=Zero+5*N;i++)
		f[i]=INF;
	f[Lim]=0;
}

void Dp()
{
	int t;
	for(int i=1;i<=N;i++)
	{
		t=(c[i].lower-c[i].upper)*2;
		if(t==0)
			continue;
		if(t>0)
		{
			for(int j=Zero+5*N-t;j>=Zero-5*N;j--)
			{
				if(f[j]!=INF)
				{
					f[j+t]=min(f[j+t],f[j]+1);
					#ifdef Debug
					cout<<"f["<<j+t<<"] = "<<f[j+t]<<endl;
					#endif
				}
			}
		}
		if(t<0)
		{
			for(int j=Zero-5*N+t;j<=Zero+5*N;j++)
			{
				if(f[j]!=INF)
				{
					f[j+t]=min(f[j+t],f[j]+1);
				}
			}
		}
	}
}

void work()
{
	init();
	Dp();
	Lim=0;
	while(f[Zero+Lim]==INF && f[Zero-Lim]==INF)
		Lim++;
	cout<<min(f[Zero+Lim],f[Zero-Lim])<<endl;
}

int main()
{
	work();
	return 0;
}

