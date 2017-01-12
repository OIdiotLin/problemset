#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 30
#define INF 1<<30
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int N,B,Ans,t;
int A[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("shelf2.in","r",stdin);
	freopen("shelf2.out","w",stdout);
	#endif
	cin>>N>>B;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	t=0;Ans=INF;
}

void dfs(int k)
{
	if(t>=B)
		if(t-B<Ans)
			Ans=t-B;
		else
			return;
	for(int i=k+1;i<=N;i++)
	{
		t+=A[i];
		dfs(i);
		t-=A[i];
	}
}
 
int main()
{
	init();
	dfs(0);
	cout<<Ans<<endl;
	return 0;
}

