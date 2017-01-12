#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#define MAXN 1010
#define MAXM 110
#define INF (1<<30)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

int W,H;	//stage 
struct Pizza{
	int T,P,V,S;
};

Pizza A[MAXN];
int fa[MAXN][MAXM];			//record the source of pizza;
int Score[MAXN][MAXM];		//Score on Position j,when i sec;
int f[MAXN][MAXM];
int N,MaxT;

void init()
{
	int T,P,V,S;
	SpeedUp;
	#ifdef FILE
	freopen("freepizza.in","r",stdin);
	freopen("freepizza.out","w",stdout);
	#endif
	cin>>W>>H;
	N=MaxT=0;
	while(cin>>T>>P>>V>>S)
	{
		if((H-1)%V==0 || T==0){
			MaxT=max(MaxT,T+(H-1)/V);
			Score[T+(H-1)/V][P]+=S;
		}
	}
	#ifdef Debug
	cout<<"Array Score:"<<endl;
	for(int i=0;i<=MaxT;i++)
	{
		for(int j=1;j<=W;j++)
			cout<<"\t"<<Score[i][j];
		cout<<endl;
	}	
	#endif
	for(int i=0;i<=MaxT;i++)
		for(int j=1;j<=W;j++)
			f[i][j]=-INF;
	f[0][(W+1)/2]=Score[0][(W+1)/2];
}

void Dp()
{
	for(int i=1;i<=MaxT;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(j>2 && f[i-1][j-2]>f[i][j])
			{
				f[i][j]=f[i-1][j-2];
				fa[i][j]=2;
			}
			if(j>1 && f[i-1][j-1]>f[i][j])
			{
				f[i][j]=f[i-1][j-1];
				fa[i][j]=1;
			}
			if(f[i-1][j]>f[i][j])
			{
				f[i][j]=f[i-1][j];
				fa[i][j]=0;
			}
			if(j+1<=W && f[i-1][j+1]>f[i][j])
			{
				f[i][j]=f[i-1][j+1];
				fa[i][j]=-1;
			}
			if(j+2<=W && f[i-1][j+2]>f[i][j])
			{
				f[i][j]=f[i-1][j+2];
				fa[i][j]=-2;
			}
			f[i][j]+=Score[i][j];
		}
	}
}

void Out()
{
	deque<int> Order;
	int t=0,k;
	bool flag=false;
	
	for(int i=1;i<=W;i++)
		if(f[MaxT][i]>f[MaxT][t])
			k=t=i;
	if(!MaxT)
	{
		cout<<f[0][t]<<endl;
		if(f[0][t])
			cout<<0<<endl;
		return;
	}
	for(int i=MaxT;i;i--)
	{
		if(flag)
		{
			Order.push_front(fa[i][k]);
			k-=fa[i][k];
		}
		else{
			if(Score[i][k] || i==1)
			{
				flag=true;
				Order.push_front(fa[i][k]);
			}
			k-=fa[i][k];
		}
	}
	cout<<f[MaxT][t]<<endl;
	for(int i=0;i<Order.size();i++)
		cout<<Order[i]<<endl;
}

void work()
{
	init();
	Dp();
	#ifdef Debug
	cout<<"After Dp:"<<endl;
	cout<<"Array f:"<<endl;
	for(int i=0;i<=MaxT;i++)
	{
		for(int j=1;j<=W;j++)
			cout<<"\t"<<f[i][j];
		cout<<endl;
	}
	cout<<"Array fa:"<<endl;
	for(int i=0;i<=MaxT;i++)
	{
		for(int j=1;j<=W;j++)
			cout<<"\t"<<fa[i][j];
		cout<<endl;
	}
	#endif
	Out();
	cout<<endl;
}

int main()
{
	work();
	return 0;
}

