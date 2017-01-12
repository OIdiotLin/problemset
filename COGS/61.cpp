#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN 10005
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct Mole{
	int Time,X,Y;
	friend bool operator <=(Mole i,Mole j){
		return ((abs(i.X-j.X)+abs(i.Y-j.Y))<=i.Time-j.Time);
	}
};

Mole a[MAXN];
int Ans,N,M;
int f[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	#endif
	cin>>N>>M;
	Ans=-INF;
	memset(f,0,sizeof(f));
	for(int i=1;i<=M;i++)
	{
		cin>>a[i].Time>>a[i].X>>a[i].Y;
		f[i]=1;
	}
	Ans=1;
}

void Dp()
{
	for(int i=1;i<=M;i++)
	{
		for(int j=i-1;j>=1;j--)
			if(f[i]<f[j]+1 && a[i]<=a[j])
				f[i]=f[j]+1;
		Ans=max(Ans,f[i]);
	}
}

int main()
{
	init();
	Dp();
	cout<<Ans<<endl;
	return 0;
}

