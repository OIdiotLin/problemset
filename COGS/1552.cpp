#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 30
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

typedef long long LL;
struct Edge{
	int n,next;
	LL Weight;
};
Edge e[MAXN*MAXN*MAXN];
int k[MAXN];
bool vis[MAXN];
int N,cnt=0;
LL Ans;

inline LL gcd(LL a,LL b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}

void Add_Edge(int i,int j,int W)
{
	cnt++;
	e[cnt]=(Edge){j,k[i],W};
	k[i]=cnt;
}

void dfs(int n,LL w)
{
	if(n==2)
	{
		Ans=Ans*w/gcd(Ans,w);
		return ;
	}
	if(!(Ans%w))
		return;
	for(int i=k[n];i>0;i=e[i].next)
	{
		if(!vis[e[i].n])
		{
			vis[e[i].n]=true;
			dfs(e[i].n,gcd(w,e[i].Weight));
			vis[e[i].n]=false;
		}
	}
	
}

void init()
{
	int w;
	SpeedUp;
	#ifdef FILE
	freopen("testz.in","r",stdin);
//	freopen("testz.out","w",stdout);
	#endif
	Ans=1;
	memset(vis,false,sizeof(vis));
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			cin>>w;
			if(w)
				Add_Edge(i,j,w);
		}
	vis[1]=true;
}

void work()
{
	for(int i=k[1];i>0;i=e[i].next)
		dfs(e[i].n,e[i].Weight);
	cout<<Ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}

