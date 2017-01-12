#include <iostream>
#include <cstring>

using namespace std;
const int MAXN=500010;

int bed[MAXN];
int M,N,ans;

void work()
{
	ans=0;
	memset(bed,0,sizeof(bed));
	cin>>N>>M;
	for(int i=1;i<=M;i++)
	{
		int x,y;
		cin>>x>>y;
		bed[x]++;
		bed[y+1]--;
	}
	for(int i=1;i<=N;i++)
	{
		bed[i]+=bed[i-1];
		if(bed[i]==0)
			ans++;
	}
	cout<<ans<<endl;
}

int main()
{
	work();
	return 0;
}
