#include <iostream>
#include <cstring>
#define SpeedUp ios::sync_with_stdio(false)
#define MAXN 250 

using namespace std;

int cnt,N,M;
int Num[MAXN],Map[MAXN][12000];

void dfs(int a)
{
	Num[a]=0;
	cnt++;
	for(int i=0;i<N;i++)
	{
		if(Map[a][i] && Num[i])
		{
			#ifdef Debug
			cout<<"-----dfs("<<i<<"): "<<endl;
			#endif
			dfs(i);
		}
	}
}

void work()
{
	int x,y;
	SpeedUp;
	cin>>N>>M;
	cnt=0;
	memset(Map,0,sizeof(Map));
	memset(Num,0,sizeof(Num));
	for(int i=0;i<M;i++)
	{
		cin>>x>>y;
		Map[x][y]++;
		Map[y][x]++;
		Num[x]++;
		Num[y]++;
	}
	for(int i=0;i<N;i++)
	{
		if(Num[i]%2)
		{
			cnt=1;
			break;
		}
	}
	if(cnt)
	{
		cout<<"Not Possible"<<endl;
		return;
	}
	dfs(x);
	if(cnt!=N)
		cout<<"Not Possible"<<endl;
	else 
		cout<<"Possible"<<endl;
}

int main()
{
	while(1)
	{
		work();
	}
	return 0;
}
