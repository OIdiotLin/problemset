#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 100
#define INF 1<<25
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;

int Adj[MAXN][MAXN],dist[MAXN][MAXN];
int N,M,set;			//N为村庄，M为道路，set为学校选址 
int t[MAXN];
int S,T,W;
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("djsa.in","r",stdin);
	//freopen("djsa.out","w",stdout);
	#endif
	memset(Adj,0,sizeof(Adj));
	memset(t,0,sizeof(t));
	memset(dist,0,sizeof(dist));
	set=0;
	#ifdef Debug
	cout<<"Memset Success!!"<<endl;
	#endif
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dist[i][j]=INF;
	#ifdef Debug
	cout<<"Dist init Success!!!"<<endl;
	#endif
	for(int i=1;i<=M;i++)
	{
		cin>>S>>T>>W;
		Adj[S][T]=Adj[T][S]=W;
		dist[S][T]=dist[T][S]=W;
	}

}

void Floyd()
{
	#ifdef Debug
	cout<<"Reading Success!!!"<<endl;
	#endif	
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					#ifdef Debug
					cout<<"Success in "<<k<<"-"<<i<<"-"<<j<<endl\
						<<"\t dist["<<i<<"]["<<j<<"]"<<" = "<<dist[i][j]<<endl;
					#endif
				}
	#ifdef Debug
	cout<<"Floyd Success!!!"<<endl;
	#endif 
}

void work()
{
	for(int i=0;i<N;i++)
	{
		t[i]=dist[0][i];
		for(int j=1;j<N;j++)
		{
			if(dist[j][i]>t[i])
				t[i]=dist[j][i];
			#ifdef Debug
			cout<<"InLoop #"<<j<<":\tt["<<i<<"] = "<<t[i]<<endl;
			#endif
		}
	}
	for(int i=1;i<N;i++)
		if(t[i]<t[set])
			set=i;
	cout<<set<<endl;
}

int main()
{
	init();
	Floyd();
	work();
	return 0;
}

