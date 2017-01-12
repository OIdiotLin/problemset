#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 100
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

struct F_Array{
	int Max,Min;
};

bool Deleted[MAXN];
int Node[MAXN];
char Edge[MAXN];
F_Array f[MAXN][MAXN];	//Max of i merge with j,    Min of i merge with j.
int N,MaxA;
int cnt_Del,cnt_Len;

inline int max(int a,int b,int c,int d){return max(max(a,b),max(c,d));}
inline int min(int a,int b,int c,int d){return min(min(a,b),min(c,d));}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.out","w",stdout);
	#endif
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>Edge[i]>>Node[i];
	}
	MaxA=-INF;
}

void Dp_init()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(i==j)
				f[i][i].Max=f[i][i].Min=Node[i];
			else
			{
				f[i][j].Max=-INF;
				f[i][j].Min=INF;
			}
		}
}

void Dp()
{
	int MaxT,MinT;
	for(cnt_Len=2;cnt_Len<=N;cnt_Len++)
	{
		for(int i=cnt_Del;i<=N+cnt_Del-cnt_Len;i++)
		{
			int t=i+cnt_Len-1;
			for(int j=i;j<t;j++)
			{
				int MinL=f[i%N][j%N].Min;
				int MaxL=f[i%N][j%N].Max;
				int MinR=f[(j+1)%N][t%N].Min;
				int MaxR=f[(j+1)%N][t%N].Max;
				
				if(Edge[(j+1)%N]=='t')
				{
					MaxT=MaxL+MaxR;
					MinT=MinL+MinR;
				}
				else
				{
					MaxT=max(MaxL*MaxR,MinL*MinR,MinL*MaxR,MaxL*MinR);
					MinT=min(MaxL*MaxR,MinL*MinR,MinL*MaxR,MaxL*MinR);
					#ifdef Debug
					cout<<"Edge["<<(j+1)%N<<"]= x or digit"<<endl;
					#endif
				}
				if(f[i%N][t%N].Max<MaxT)
					f[i%N][t%N].Max=MaxT;
				if(f[i%N][t%N].Min>MinT)
					f[i%N][t%N].Min=MinT;
			}
		}
	}
}

void work()
{
	for(cnt_Del=0;cnt_Del<N;cnt_Del++)		//trying delete Every Edge
	{
		Dp_init();
		Dp();
		if(f[cnt_Del][(cnt_Del-1)%N].Max>MaxA)
		{
			memset(Deleted,false,sizeof(Deleted));
			MaxA=f[cnt_Del][(cnt_Del+N-1)%N].Max;
			Deleted[cnt_Del]=true;
		}
		else if(f[cnt_Del][(cnt_Del+N-1)%N].Max==MaxA)
		{
			Deleted[cnt_Del]=true;
		}
	}
	cout<<MaxA<<endl;
	for(int i=0;i<N;i++)
		if(Deleted[i])
			cout<<i+1<<" ";
	cout<<endl;
}

int main()
{
	init();
	work();
	return 0;
}

