#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 100000
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

int N,ans;
int a[MAXN];
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("wallet.in","r",stdin);
	freopen("wallet.out","w",stdout);
	#endif
	cin>>N;
	ans=0;
}

void work()
{
	while(1<<ans<=N)
	{
		a[ans]=1<<ans;
		ans++;	
	}
}

int main()
{
	init();
	work();
	cout<<ans<<endl;
	for(int i=0;i<ans;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

