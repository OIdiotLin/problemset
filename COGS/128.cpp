#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>
#define MAXN 1100
#define INF (1<<28)
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;

struct Gear{
	int x,y,r;
	bool Con(Gear &a)const{
		return ((r+a.r)*(r+a.r)==(x-a.x)*(x-a.x)+(y+a.y)*(y+a.y));
	}
}C[MAXN];

int G[MAXN][MAXN],Deg[MAXN];
bool vis[MAXN];
int N,Power;

void init()
{
	int t;
	SpeedUp;
	#ifdef FILE
	freopen("rollers.in","r",stdin);
//	freopen("rollers.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
	{	
		t=i;
		cin>>C[i].x>>C[i].y>>C[i].r;
		if(C[i].x==0 && C[i].y==0)		//Driving Gear.
		{
			Power=i;
			break;
		}
		for(int j=1;j<=i;j++)
			if(C[i].Con(C[j]))
			{
				G[i][++Deg[i]]=j;
				G[j][++Deg[j]]=i;
			}
		
	}

	while(1){
		for(int i=1;i<=t;i++)
			if(C[t].Con(C[i]))
			{
				G[t][++Deg[t]]=i;
				G[i][++Deg[i]]=t;
			}
		t++;
		if(t>N)
			break;
		cin>>C[t].x>>C[t].y>>C[t].r;
	}
	if(Deg[Power]==0){
		cout<<0<<" "<<0<<endl;
		exit(0);
	}
	#ifdef Debug
	for(int i=1;i<=N;i++)
	{
		cout<<i<<" has "<<Deg[i]<<" paths."<<endl;
	}
	#endif
}

deque<int> Q;
void bfs(){
	vis[Power]=true;
	Q.push_back(Power);
	while(Q.size()){
		for(int i=1;i<=Deg[Q.front()];i++)
			if(!vis[G[Q.front()][i]])
			{
				Q.push_back(G[Q.front()][i]);
				#ifdef Debug
				cout<<Q.back()<<endl;
				#endif
				vis[Q.back()]=true;
				if(Deg[Q.back()]==1){
					cout<<C[Q.back()].x<<" "<<C[Q.back()].y<<endl;
					exit(0);
				}
			}
		Q.pop_front();
	}
}

int main()
{
	init();
	bfs();
	return 0;
}

