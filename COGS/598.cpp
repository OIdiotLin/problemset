#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 100
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
//#define Debug
using namespace std;

bool G[20][MAXN][MAXN],vis[20][MAXN];
int t[1001],E[1001];				//t 就是一个队列，包含了周期里的各种情况。 
int N,M,T;

void init()
{
	int v1,v2;
	SpeedUp;
	#ifdef FILE
	freopen("house.in","r",stdin);
	freopen("house.out","w",stdout);
	#endif
	memset(G,false,sizeof(G));
	memset(vis,false,sizeof(vis));
	
	cin>>N>>M>>T;
	for(int i=1;i<=T;i++)
		for(int j=0;j<=N;j++)
			G[i][j][j]=true;
	for(int i=1;i<=T;i++)
		for(int j=1;j<=M;j++)
		{
			cin>>v1>>v2;
			G[i][v1][v2]=true;
			G[i][v2][v1]=true;
		}
	E[0]=t[0]=1;
}

void bfs()
{
	vis[1][1]=true;
	
	int tail,head;
	tail=head=0;
	int k;
	while(tail<=head)
	{
		k=t[tail]%T;
		if(k==0)
			k=T;
		for(int i=0;i<=N;i++)
		{
			if(!G[k][E[tail]][i])
				continue;
			head++;
			E[head]=i;
			t[head]=t[tail]+1;
			if(vis[k+1][E[head]])
				head--;
			else
				vis[k+1][E[head]]=true;
			if(E[head]==0)
			{
				cout<<t[tail]<<endl;
				return;
			}
			#ifdef Debug
			cout<<"tail="<<tail<<"  head="<<head<<": "<<endl<<"\t";
			cout<<"Array of E: ";
			for(int i=0;i<=N;i++)
				cout<<E[i]<<" ";
			cout<<endl;
			#endif
		}
		tail++;
	}
	cout<<"Poor Z4!"<<endl;
}

void work()
{
	init();
	bfs();
}

int main()
{
	work();
	return 0;
}

