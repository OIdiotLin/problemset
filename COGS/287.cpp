#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#define MAXN 100010
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
//#define Debug
#define FILE
using namespace std;

inline int gcd(int a,int b){return b==0 ? a : gcd(b,a%b);}

int N,M,Max,Min,Ans,Limit;
vector<pair<int,int> > Adj[MAXN];
bool vis[MAXN],loop;
int dist[MAXN];

void init()
{
	int r1,r2;
	SpeedUp;
	#ifdef FILE
	freopen("party2008.in","r",stdin);
	freopen("party2008.out","w",stdout);
	#endif
	memset(vis,false,sizeof(vis));
	memset(dist,0,sizeof(dist));
	cin>>N>>M;
	for(int i=1;i<=M;i++)
	{
		cin>>r1>>r2;		//r1 can recognize r2
		Adj[r1].pb(mp(r2,1));
		Adj[r2].pb(mp(r1,-1));
	}
	Limit=Ans=0;
	Max=-INF;
	Min=INF;
	loop=false;
}

void dfs(int x,int dis)
{
	int k;
	if(vis[x])
		return;
	vis[x]=true;
	dist[x]=dis;
	if(Max<dis)
		Max=dis;
	if(Min>dis)
		Min=dis;
	for(int i=0;i<Adj[x].size();i++)
	{
		k=Adj[x][i].first;
		if(vis[k])
		{
			int t=abs(dis+Adj[x][i].second-dist[k]);
			if(t)	//There is a loop
			{
				#ifdef Debug
				cout<<"In dfs( "<<x<<" , "<<dis<<" ) ------ i = "<<i<<"\t Find A Circle"<<endl;
				#endif
				loop=true;
				Limit=gcd(Limit,t);
			}
		}
		else
			dfs(k,dis+Adj[x][i].second);
	}
}

int Get_Lim(int x)
{		
	#ifdef Debug
	cout<<"Get_Lim: "<<endl;
	#endif
	int LHD=INF;
	for(int i=1;i<=(int)sqrt((double)x);i++)
	{
		#ifdef Debug
		cout<<"\tRound #"<<i<<" : "<<endl;
		#endif
		if(x%i==0)
		{
			if(i>=3 && LHD>i)	//mask reached 3
			{
				LHD=i;
				#ifdef Debug
				cout<<"\t Refresh LHD = "<<LHD<<endl;
				#endif
			}
			if(LHD>x/i)
				LHD=x/i;
		}
	}
	return LHD;
}

void Travel_Graph()
{
	for(int i=1;i<=N;i++)
	{
		if(vis[i])
			continue;
		Max=-INF;Min=INF;
		dfs(i,0);
		Ans+=Max-Min+1;
	}
}

void work()
{
	Travel_Graph();
	if(loop)	//circle
	{
		#ifdef Debug
		cout<<"Circle"<<endl;
		#endif
		if(Limit<3)						//There is no solution
			cout<<"-1 -1"<<endl;
		else
			cout<<Limit<<" "<<Get_Lim(Limit)<<endl;
	} 
	else	//Tree
	{
		#ifdef Debug
		cout<<"Tree"<<endl;
		#endif
		if(Ans<3)						//There is no solution
			cout<<"-1 -1"<<endl;
		else
			cout<<Ans<<" "<<3<<endl;	//The min Ans in a tree must be 3.
	}
}

int main()
{
	init();
	work();
	return 0;
}

