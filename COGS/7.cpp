#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1520
#define INF 0x7FFFFFFF 
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;

struct Edge{
	Edge *next;
	int s,W;
};

int N,Ans,cnt;
Edge E[2*MAXN*MAXN],(*V[MAXN]);
int MST[MAXN];
bool vis[MAXN];

void Add_Edge(int s,int t,int w)
{
	E[cnt].next=V[s];
	E[cnt].s=t;
	E[cnt].W=w;
	V[s]=&E[cnt];
	cnt++;
}

void init()
{
	int w;
	SpeedUp;
	#ifdef FILE
	freopen("mcst.in","r",stdin);
	freopen("mcst.out","w",stdout);
	#endif
	cnt=Ans=0;

	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			cin>>w;
			if(w!=-1)
				Add_Edge(i,j,w);
		}	
	for(int i=1;i<=N;i++)
	{
		MST[i]=INF;
		vis[i]=false;
	}
}

void Prim()
{
	int i=1;MST[1]=0;
	while(i!=-1)
	{
		#ifdef Debug
		cout<<"\ti = "<<i<<endl;
		#endif
		
		vis[i]=true;
		for(Edge *k=V[i];k;k=k->next)
		{
			if(!vis[k->s] && k->W<MST[k->s])
			{
				MST[k->s]=k->W;
				#ifdef Debug
				cout<<"MST["<<k->s<<"] = "<<k->W<<endl;
				#endif
			}
		}
		int Min=INF;
		i=-1;
		for(int j=1;j<=N;j++)
		{
			if(!vis[j] && MST[j]<Min)
			{
				Min=MST[j];
				#ifdef Debug
				cout<<"Min is "<<MST[j]<<"  (MST["<<j<<"])"<<endl;
				#endif
				i=j;
			}
		}
	}
}

void work()
{
	init();
	Prim();
	for(int i=1;i<=N;i++)
	{
		Ans+=MST[i];
		#ifdef Debug
		cout<<"MST["<<i<<"] = "<<MST[i]<<endl;
		#endif
	}
	cout<<Ans<<endl;
}

int main()
{
	work();
	return 0;
}

