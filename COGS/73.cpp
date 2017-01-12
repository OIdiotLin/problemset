#include <iostream>
#include <cstring>
#include <cstdio>
#define FILE
#define MAXN 51

using namespace std;

int path[MAXN],Adj[MAXN][MAXN],len[2500],que[2500];
bool vis[MAXN];
int N,M,start,target;

void init()
{
	memset(vis,false,sizeof(vis));
	memset(len,0,sizeof(len));
	memset(que,0,sizeof(que));
	#ifdef FILE
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	#endif
	
	cin>>N>>M>>start>>target;
	for(int i=1;i<=M;i++)
	{
		int a,b;
		cin>>a>>b;
		Adj[a][path[a]++]=b;	//ÓĞÏòÍ¼ 
	}
	que[0]=start;
	len[0]=1;
	vis[start]=true;
}

void bfs()
{
	int tail=0,head=1;
	while(tail<=head)
	{
		for(int i=0;i<path[que[tail]];i++)
			if(!vis[Adj[que[tail]][i]])
			{
				head++;
				que[head]=Adj[que[tail]][i];
				len[head]=len[tail]+1;
				vis[que[head]]=true;
				if(que[head]==target)
				{
					cout<<len[head]<<endl;
					return ;
				}
			}
		tail++;
	}
}

int main()
{
	init();
	bfs();
	return 0;
}
