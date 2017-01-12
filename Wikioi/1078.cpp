#include <iostream>
 
using namespace std;

int n,V[100][100],Suc=1,Min,PosMin,ans;
bool vis[100]={false};

void init()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>V[i][j];
			if(V[i][j]==0)			//如果不相连则赋值为最大值 
				V[i][j]=1073741824;
		}
	vis[0]=true,Min=1073741824;ans=0;
}

void work()
{
	for(int i=0;i<n;i++)
		for(int now=0;now<n;now++)
			if(!vis[i]&&vis[now]&&V[now][i]<Min)
			{
				Min=V[now][i];
				PosMin=i;
			}
	ans+=Min;
	vis[PosMin]=true;
	Suc++;
	Min=1073741824;
}

int main()
{
	init();
	while(Suc<n)
		work();
	cout<<ans<<endl;
	return 0;
}
