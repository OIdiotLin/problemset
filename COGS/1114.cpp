#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXM 1005
#define MAXN 205
#define INF 1<<30
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct Edge{
	int S,T;
	int W;
	friend bool operator < (Edge A,Edge B){
		return A.W<B.W;
	}
	friend int Diff(Edge A,Edge B){
		return A.W-B.W;
	}
};

Edge E[MAXM];
int fa[MAXN];
int N,M;


void init()
{
	int r1,r2,r3;
	SpeedUp;
	#ifdef FILE
	freopen("motor.in","r",stdin);
	freopen("motor.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=M;i++)
	{
		cin>>r1>>r2>>r3;
		E[i]=(Edge){r1,r2,r3};
	}
	sort(E+1,E+M+1);
}

int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}

void Question()
{
	int Start,Target,s_Fa,t_Fa;
	int Ans=INF;
	
	cin>>Start>>Target;
	
	for(int i=1;i<=M;i++)
	{
		for(int x=1;x<=N;x++)
			fa[x]=x;
		int j;
		for(j=i;j<=M;j++)
		{
			s_Fa=find(E[j].S);
			t_Fa=find(E[j].T);
			if(s_Fa!=t_Fa)
				fa[s_Fa]=t_Fa;
			if(find(Start)==find(Target))				//已经连通 
				break;
		}
		if(fa[Start]==fa[Target])
		{
			Ans=min(Ans,Diff(E[j],E[i]));
		}
	}
	cout<<Ans<<endl;
}

void work()
{
	int K;
	cin>>K;
	while(K--)
	{
		Question();
	}
}

int main()
{
	init();
	work();
	return 0;
}

